#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "proj2.h"
#include "proj3.h"

FILE *asm_file;

#define EMIT(args...) \
{ \
    fprintf(asm_file, args); \
    fprintf(asm_file, "\n"); \
    fflush(asm_file); \
}

#define GET_LEFT_CHILD(x) (tree)((uintptr_t)LeftChild(x))
#define GET_RIGHT_CHILD(x) (tree)((uintptr_t)RightChild(x))

extern void* yyin;
tree SyntaxTree = NULL;
int l_reg = 0xfc000003;
int c_off = 0, g_off = 0, c_size = 0, label_counter = 0;

void generate_cbody_op(tree tn, int idx);
void generate_code(tree tn);
void generate_cfunc_op(tree tn);
void generate_cfunc_body(tree tn, int* o);
void generate_cfunc_decl(tree tn, int*o);
void emit_parray_code(tree tn, int idx);
void emit_word_code(tree tn, int idx);
void emit_stack_code(tree tn, int flag);
void emit_cnd_code(tree tn, int lbl);
void emit_expr_code(tree tn);
void gen_op_code(tree tn);
int generate_var_op(tree tn, int addr);
int calc_array_size(tree tn);
int get_int_val(tree tn);
int get_next_reg();

int main(int argc, char *argv[]) {
    FILE *fid = fopen(argv[1], "r");
    asm_file = fopen("code.s", "w");

    yyin = fid;

    yyparse();
    STInit();
    MkST(SyntaxTree);

    EMIT(".data");
    EMIT("Enter:\t.asciiz \"  \n\"");
    EMIT("base:");
    EMIT(".text");
    EMIT(".globl main");

    generate_code(SyntaxTree);

    fclose(fid);
    fclose(asm_file);

    return 0;
}

void generate_code(tree treenode) {
    if (IsNull(treenode)) return;

    if (NodeOp(treenode) == ClassDefOp) {
        c_size = 0;
        c_off = 0;
        int num_s_ind = IntVal(GET_RIGHT_CHILD(treenode));
        SetAttr(num_s_ind, OFFSET_ATTR, g_off);
        generate_cbody_op(GET_LEFT_CHILD(treenode), num_s_ind);
        if (!IsAttr(num_s_ind, 10)) SetAttr(num_s_ind, 10, c_size);
        g_off += c_size;
    } else {
        generate_code(GET_LEFT_CHILD(treenode));
        generate_code(GET_RIGHT_CHILD(treenode));
    }
}

void generate_cbody_op(tree treenode, int ind) {
    if (IsNull(treenode)) return;

    generate_cbody_op(GET_LEFT_CHILD(treenode), ind);
    tree var_d = GET_RIGHT_CHILD(treenode);

    if (NodeOp(var_d) == MethodOp) {
        SetAttr(ind, 10, c_size);
        generate_cfunc_op(var_d);

    } else if (NodeOp(var_d) == DeclOp) {
        EMIT(".data");
        tree var_comma = GET_RIGHT_CHILD(var_d);
        int lc_var_comma = GET_LEFT_CHILD(var_comma);
        int lc_rc_var_comma = GET_LEFT_CHILD(RightChild(var_comma));
        int rc_rc_var_comma = GET_RIGHT_CHILD(RightChild(var_comma));
        while (!IsNull(var_d)) {
            int num_s_ind = IntVal(lc_var_comma);
            int attr = GetAttr(num_s_ind, KIND_ATTR);

            if (attr == VAR) {
                if (NodeKind(GET_LEFT_CHILD(lc_rc_var_comma)) == INTEGERTNode) {
                    SetAttr(num_s_ind, OFFSET_ATTR, c_off);
                    c_off += 4;
                    EMIT("\t.word\t%d", get_int_val(rc_rc_var_comma));
                } else if (NodeKind(GET_LEFT_CHILD(lc_rc_var_comma)) == STNode) {
                    SetAttr(num_s_ind, OFFSET_ATTR, c_off);
                    tree lc_lc_rc_var_comma = GET_LEFT_CHILD(lc_rc_var_comma);
                    tree classdef = (tree)((uintptr_t)GetAttr(IntVal(lc_lc_rc_var_comma),TYPE_ATTR));
                    emit_stack_code(GET_LEFT_CHILD(classdef), 0);
                    c_off += GetAttr(IntVal(lc_lc_rc_var_comma), 10);
                }

            } else if (attr == ARR && NodeOp(rc_rc_var_comma) == ArrayTypeOp) {
                SetAttr(num_s_ind, OFFSET_ATTR, c_off);
                c_off += (calc_array_size(rc_rc_var_comma) << 2);
                emit_word_code(GET_LEFT_CHILD(rc_rc_var_comma),num_s_ind);
            }

            var_d = GET_LEFT_CHILD(var_d);
            var_comma = GET_RIGHT_CHILD(var_d);
            lc_var_comma = GET_LEFT_CHILD(var_comma);
            lc_rc_var_comma = GET_LEFT_CHILD(RightChild(var_comma));
            rc_rc_var_comma = GET_RIGHT_CHILD(RightChild(var_comma));
        }
        c_size = c_off;
    }
}

void generate_cfunc_op(tree treenode) {
    tree h_op = GET_LEFT_CHILD(treenode);
    int num_s_ind = IntVal(GET_LEFT_CHILD(h_op));

    char attr_label[16];
    strcpy(attr_label, (char*)getname(GetAttr(num_s_ind, NAME_ATTR)));

    EMIT(".text");

    if (strcmp(attr_label, "main") == 0) {
        EMIT("%s:", attr_label);
        EMIT("\tla\t$28\tbase");
        EMIT("\tmove\t$t1\t$28");
        num_s_ind--;
        while (num_s_ind > 0 && (GetAttr(num_s_ind, KIND_ATTR) != CLASS)) {
            num_s_ind--;
        }
        EMIT("\tadd\t$t1\t$t1\t%d", GetAttr(num_s_ind,OFFSET_ATTR));
        EMIT("\tli\t$t2\t0");
        EMIT("\tmove\t$fp\t$sp");
    } else {
        EMIT("%s_%d:", attr_label, num_s_ind);
        EMIT("\tlw\t$t1\t%d($fp)", 80 + (GetAttr(num_s_ind, 10)<<2));
        EMIT("\tlw\t$t2\t%d($fp)", 84 + (GetAttr(num_s_ind, 10)<<2));
    }

    EMIT("\tsw\t$ra\t0($sp)");
    EMIT("\taddi\t$sp\t$sp\t-4");

    tree var_arg_op = GET_LEFT_CHILD(GET_RIGHT_CHILD(h_op));
    tree var_comma = GET_LEFT_CHILD(var_arg_op);
    int o = 0;
    while (!IsNull(var_arg_op)) {
        o += 4;
        num_s_ind = IntVal(GET_LEFT_CHILD(var_comma));
        SetAttr(num_s_ind, OFFSET_ATTR, o);
        var_arg_op = GET_RIGHT_CHILD(var_arg_op);
        var_comma = GET_LEFT_CHILD(var_arg_op);
    }

    int temp = 4;
    generate_cfunc_body(GET_RIGHT_CHILD(treenode), &temp);
    EMIT("\tlw\t$ra\t0($fp)");
    EMIT("\tmove\t$sp\t$fp");
    EMIT("\tjr\t$ra");
}

void generate_cfunc_body(tree treenode, int *off) {
    if (IsNull(treenode)) return;

    generate_cfunc_body(GET_LEFT_CHILD(treenode), off);
    tree bodychild = GET_RIGHT_CHILD(treenode);

    if (NodeOp(bodychild) == DeclOp) {
        generate_cfunc_decl(bodychild, off);
    } else if (NodeOp(bodychild) == StmtOp) {
        gen_op_code(bodychild);
    }
}

void generate_cfunc_decl(tree treenode, int *s_off) {
    tree var_comma = GET_RIGHT_CHILD(treenode);
    tree lc_var_comma = GET_LEFT_CHILD(var_comma);
    tree lc_rc_var_comma = GET_LEFT_CHILD(RightChild(var_comma));
    tree rc_rc_var_comma = GET_RIGHT_CHILD(RightChild(var_comma));
    int initial_i = 0;
    while (!IsNull(treenode)) {
        int num_s_ind = IntVal(lc_var_comma);
        int attr = GetAttr(num_s_ind, KIND_ATTR);

        if (attr == VAR) {
            if (NodeKind(GET_LEFT_CHILD(lc_rc_var_comma)) == INTEGERTNode) {
                SetAttr(num_s_ind, OFFSET_ATTR, *s_off);
                *s_off = *s_off + 4;
                if (NodeKind(rc_rc_var_comma) == NUMNode) {
                    initial_i = IntVal(rc_rc_var_comma);
                }

                int nr = get_next_reg();
                EMIT("\tli\t$%d\t%d", nr, initial_i);
                EMIT("\tsw\t$%d\t0($sp)", nr);
                EMIT("\taddi\t$sp\t$sp\t-4");
            } else if (NodeKind(GET_LEFT_CHILD(lc_rc_var_comma)) == STNode) {
                SetAttr(num_s_ind, OFFSET_ATTR, *s_off);
                tree lc_lc_rc_var_comma = GET_LEFT_CHILD(lc_rc_var_comma);
                emit_stack_code(GET_LEFT_CHILD((tree)((uintptr_t)GetAttr(IntVal(lc_lc_rc_var_comma), TYPE_ATTR))), 1);
                *s_off = *s_off + GetAttr(IntVal(lc_lc_rc_var_comma), 10);
            }

        } else if (attr == ARR && NodeOp(rc_rc_var_comma) == ArrayTypeOp) {
            SetAttr(num_s_ind, OFFSET_ATTR, *s_off);
            *s_off = *s_off + (calc_array_size(rc_rc_var_comma) << 2);
            emit_parray_code(GET_LEFT_CHILD(rc_rc_var_comma), num_s_ind);
        }

        treenode = GET_LEFT_CHILD(treenode);
        var_comma = GET_RIGHT_CHILD(treenode);
        lc_var_comma = GET_LEFT_CHILD(var_comma);
        lc_rc_var_comma = GET_LEFT_CHILD(RightChild(var_comma));
        rc_rc_var_comma = GET_RIGHT_CHILD(RightChild(var_comma));
        initial_i = 0;
    }
}

void emit_parray_code(tree treenode, int ind) {
    if (IsNull(treenode)) return;

    if (NodeOp(treenode) == CommaOp) {
        emit_parray_code(GET_LEFT_CHILD(treenode),ind);
        int nr = get_next_reg();
        EMIT("\tli\t$%d\t%d", nr, get_int_val(GET_RIGHT_CHILD(treenode)));
        EMIT("\tsw\t$%d\t0($sp)", nr);
        EMIT("\taddi\t$sp\t$sp\t-4");
    } else if (NodeOp(treenode) == BoundOp) {
        int d = GetAttr(ind, 11);
        int dd = GetAttr(ind, 12);
        int i;

        if (dd > 0) d *= dd;

        for (i = 0; i < d; i++) {
            EMIT("\tsw\t$0\t0($sp)");
            EMIT("\taddi\t$sp\t$sp\t-4");
        }
    }
}


void emit_word_code(tree treenode, int ind) {
    if (IsNull(treenode)) return;

    if (NodeOp(treenode) == CommaOp) {
        emit_word_code(GET_LEFT_CHILD(treenode),ind);
        EMIT("\t.word\t%d", get_int_val(GET_RIGHT_CHILD(treenode)));
    } else if (NodeOp(treenode) == BoundOp) {
        int d = GetAttr(ind, 11);
        int dd = GetAttr(ind, 12);
        if (dd > 0) {
            d *= dd;
        }

        int i;
        for (i = 0; i < d; i++) {
            EMIT("\t.word\t0");
        }
    }
}

int calc_array_size(tree treenode) {
    if (NodeOp(treenode) != ArrayTypeOp) return 0;

    int s = 0;
    tree left_child = GET_LEFT_CHILD(treenode);
    tree right_left_child = GET_RIGHT_CHILD(left_child);

    while (!IsNull(left_child)) {
        if (NodeKind(right_left_child) != NUMNode) exit(-1);
        if (NodeOp(left_child) == CommaOp) {
            s++;
        } else {
            s = IntVal(right_left_child);
        }
        left_child = GET_LEFT_CHILD(left_child);
        right_left_child = GET_RIGHT_CHILD(left_child);
    }

    return s;
}


void emit_stack_code(tree treenode, int flag) {
    if (IsNull(treenode)) return;

    int initial;

    emit_stack_code(GET_LEFT_CHILD(treenode), flag);
    tree var_d = GET_RIGHT_CHILD(treenode);
    if (NodeOp(var_d) == MethodOp) return;
    tree rchild_var_d_comma = GET_RIGHT_CHILD(var_d);
    tree lc_var_comma = GET_LEFT_CHILD(rchild_var_d_comma);
    tree lc_rc_var_comma = GET_LEFT_CHILD(RightChild(rchild_var_d_comma));
    tree rchild_rchild_var_d_comma = GET_RIGHT_CHILD(RightChild(rchild_var_d_comma));

    while (!IsNull(var_d)) {
        int num_s_ind = IntVal(lc_var_comma);
        int attr = GetAttr(num_s_ind, KIND_ATTR);

        if (attr == VAR) {
            if (NodeKind(GET_LEFT_CHILD(lc_rc_var_comma)) == INTEGERTNode) {
                initial = get_int_val(rchild_rchild_var_d_comma);
                if (flag != 1) {
                    EMIT("\t.word\t%d", initial);
                } else {
                    int nr = get_next_reg();
                    EMIT("\tli\t$%d\t%d", nr, initial);
                    EMIT("\tsw\t$%d\t0($sp)", nr);
                    EMIT("\taddi\t$sp\t$sp\t-4");
                }
            } else if (NodeKind(GET_LEFT_CHILD(lc_rc_var_comma)) == STNode) {
                emit_stack_code(GET_LEFT_CHILD((tree)((uintptr_t)GetAttr(IntVal(GET_LEFT_CHILD(lc_rc_var_comma)), TYPE_ATTR))), flag);
            }

        } else if (attr == ARR) {
            if (NodeOp(rchild_rchild_var_d_comma) == ArrayTypeOp) {
                if (flag == 1) emit_parray_code(GET_LEFT_CHILD(rchild_rchild_var_d_comma), num_s_ind);
                else emit_word_code(GET_LEFT_CHILD(rchild_rchild_var_d_comma), num_s_ind);
            }
        }

        var_d = GET_LEFT_CHILD(var_d);
        rchild_var_d_comma = GET_RIGHT_CHILD(var_d);
        lc_var_comma = GET_LEFT_CHILD(rchild_var_d_comma);
        lc_rc_var_comma = GET_LEFT_CHILD(RightChild(rchild_var_d_comma));
        rchild_rchild_var_d_comma = GET_RIGHT_CHILD(RightChild(rchild_var_d_comma));
    }
}

int get_int_val(tree treenode) {
    int r = -1;
    if (IsNull(treenode)) r = 0;
    if (NodeKind(treenode) == NUMNode) r = IntVal(treenode);
    return r;
}

int get_next_reg() {
    int reg;
    reg = l_reg | 0Xff0007ff;

    int i;
    for (i = 0; i <= 25 ; i++) {
        if (reg % 2 == 0) break;
        reg >>= 1;
    }

    if (i > 25) exit(-1);

    return i;
}

void emit_cnd_code(tree treenode, int lbl) {
    if (IsNull(treenode)) return;

    emit_cnd_code(GET_LEFT_CHILD(treenode), lbl);
    tree right_child = GET_RIGHT_CHILD(treenode);

    if (NodeOp(right_child) == CommaOp) {
        tree b = GET_LEFT_CHILD(right_child);
        tree s = GET_RIGHT_CHILD(right_child);
        emit_expr_code(b);
        int r = get_next_reg();
        int ll = label_counter++;

        EMIT("\tlw\t$%d\t4($sp)", r);
        EMIT("\tbeqz\t$%d\tL_%d", r, ll, ll);

        if (NodeOp(s) == StmtOp) {
            gen_op_code(s);
            EMIT("\tb\tL_%d", lbl);
        }
        EMIT("L_%d:", ll);

    } else {
        if (NodeOp(right_child) == StmtOp) {
            gen_op_code(right_child);
            EMIT("\tb\tL_%d", lbl);
        }
    }
}

void gen_op_code(tree treenode) {
    if (IsNull(treenode)) return;

    int end_if, end_while;

    gen_op_code(GET_LEFT_CHILD(treenode));
    tree right_child = GET_RIGHT_CHILD(treenode);

    switch(NodeOp(right_child)){
        case LoopOp:
            end_while = label_counter++;
            int loop_begin = label_counter++;
            EMIT("L_%d:", loop_begin);
            emit_expr_code(GET_LEFT_CHILD(right_child));
            int nr = get_next_reg();
            EMIT("\tlw\t$%d\t4($sp)", nr);
            EMIT("\tbeqz\t$%d\tL_%d", nr, end_while);
            gen_op_code(GET_RIGHT_CHILD(right_child));
            EMIT("\tb\tL_%d", loop_begin);
            EMIT("L_%d:", end_while);
            break;

        case IfElseOp:
            end_if = label_counter;
            label_counter++;
            emit_cnd_code(right_child, end_if);
            EMIT("L_%d:", end_if);
            break;

        case AssignOp:
            generate_var_op(GET_RIGHT_CHILD(LeftChild(right_child)), 0);
            emit_expr_code(GET_RIGHT_CHILD(right_child));
            EMIT("\tlw\t$v0\t4($sp)");
            EMIT("\tsw\t$v0\t0($t0)");
            EMIT("\taddi\t$sp\t$sp\t4");
            break;

        case RoutineCallOp:
            if (IntVal(GET_LEFT_CHILD(GET_LEFT_CHILD(right_child))) == 1) {
                tree comma = GET_RIGHT_CHILD(treenode);
                while (! IsNull(comma)) {
                    tree A = GET_LEFT_CHILD(comma);
                    if (NodeKind(A) == STRINGNode) {
                        EMIT(".data");
                        EMIT(".align 2");
                        EMIT("S_%d:\t.asciiz\t\"%s\"", IntVal(A), getname(IntVal(A)));
                        int len = strlen((char*)getname(IntVal(A)));
                        int remainder = (len + 1) & 3;
                        if (remainder > 0) {
                            g_off += len - remainder + 5;
                        }
                        EMIT(".text");
                    }
                    comma = GET_RIGHT_CHILD(comma);
                }
            }
            break;

        case ReturnOp:
            emit_expr_code(GET_LEFT_CHILD(right_child));
            EMIT("\tlw\t$v1\t4($sp)");
            break;

        default:
            break;
    }
}

void emit_expr_code(tree treenode) {
    int r1, r2;

    if (IsNull(treenode)) {
        EMIT("\tsw\t$0\t0($sp)");
        EMIT("\taddi\t$sp\t$sp\t-4");
        return;
    }

    if (NodeKind(treenode) == NUMNode) {
        r1 = get_next_reg();
        EMIT("\tli\t$%d\t%d", r1, IntVal(treenode));
        EMIT("\tsw\t$%d\t0($sp)", r1);
        EMIT("\taddi\t$sp\t$sp\t-4");
    }

    switch(NodeOp(treenode)) {
        case RoutineCallOp:
            EMIT("\tsw\t$v1\t0($sp)");
            EMIT("\taddi\t$sp\t$sp\t-4");
            break;
        case VarOp:
            generate_var_op(treenode,1);
            break;
        case UnaryNegOp:
        case NotOp:
            emit_expr_code(GET_LEFT_CHILD(treenode));
            r1 = get_next_reg();
            EMIT("\tlw\t$%d\t4($sp)", r1);
            if (NodeOp(treenode) == UnaryNegOp) {
                EMIT("\tneg\t$%d\t$%d", r1, r1);
            } else {
                EMIT("\tnot\t$%d\t$%d", r1, r1);
            }
            EMIT("\tsw\t$%d\t4($sp)", r1);
            break;
    }

    char asm_op[16];
    switch(NodeOp(treenode)) {
        case AndOp:
            strcpy(asm_op, "and");
            break;
        case OrOp:
            strcpy(asm_op, "or");
            break;
        case AddOp:
            strcpy(asm_op, "add");
            break;
        case SubOp:
            strcpy(asm_op, "sub");
            break;
        case MultOp:
            strcpy(asm_op, "mul");
            break;
        case DivOp:
            strcpy(asm_op, "div");
            break;
        case LTOp:
            strcpy(asm_op, "slt");
            break;
        case LEOp:
            strcpy(asm_op, "sle");
            break;
        case GTOp:
            strcpy(asm_op, "sgt");
            break;
        case GEOp:
            strcpy(asm_op, "sge");
            break;
        case EQOp:
            strcpy(asm_op, "seq");
            break;
        case NEOp:
            strcpy(asm_op, "sne");
            break;
    }

    switch(NodeOp(treenode)) {
        case AndOp:
        case OrOp:
        case AddOp:
        case SubOp:
        case MultOp:
        case DivOp:
        case LTOp:
        case LEOp:
        case GTOp:
        case GEOp:
        case EQOp:
        case NEOp:
            emit_expr_code(GET_LEFT_CHILD(treenode));
            emit_expr_code(GET_RIGHT_CHILD(treenode));
            r2 = get_next_reg();
            EMIT("\tlw\t$%d\t4($sp)", r2);
            EMIT("\taddi\t$sp\t$sp\t4");
            l_reg |= (1<<r2);

            r1 = get_next_reg();
            EMIT("\tlw\t$%d\t4($sp)", r1);
            EMIT("\t%s\t$%d\t$%d\t$%d", asm_op, r2, r1, r2);
            EMIT("\tsw\t$%d\t4($sp)", r2);
            l_reg &= ~(1<<r2);
            break;
    }

}

int generate_var_op(tree treenode, int val_addr) {
    int num_s, num_s_ind, kind;
    int add_label, aft_label;
    int nr;

    tree s_op = GET_RIGHT_CHILD(treenode);
    num_s_ind = IntVal(GET_LEFT_CHILD(treenode));
    num_s = num_s_ind;

    int off = GetAttr(num_s_ind, OFFSET_ATTR);
    int offr = get_next_reg();
    EMIT("\tli\t$%d\t%d", offr, off);

    l_reg |= (1 << offr);

    while (!IsNull(s_op)) {
        tree lselect = GET_LEFT_CHILD(s_op);
        if (NodeOp(lselect) == IndexOp) {
            tree lindex = GET_LEFT_CHILD(lselect);
            emit_expr_code(lindex);
            EMIT("\tlw\t$v0\t4($sp)");
            EMIT("\tsll\t$v0\t$v0\t2");
            EMIT("\taddi\t$sp\t$sp\t4");

            if (GetAttr(num_s_ind, DIMEN_ATTR) == 1) {
                EMIT("\tadd\t$%d\t$%d\t$v0", offr, offr);
                l_reg |= 0x4;
            } else {
                lselect = GET_RIGHT_CHILD(lselect);
                if (!IsNull(lselect)) {
                    off = GetAttr(num_s_ind, 12);
                    EMIT("\tmul\t$v0\t$v0\t%d", off);
                    EMIT("\tadd\t$%d\t$%d\t$v0", offr, offr);
                    lindex = GET_LEFT_CHILD(lselect);
                    emit_expr_code(lindex);
                    EMIT("\tlw\t$v0\t4($sp)");
                    EMIT("\tsll\t$v0\t$v0\t2");
                    EMIT("\tadd\t$%d\t$%d\t$v0", offr, offr);

                    l_reg |= 0x4;

                }
                s_op = GET_RIGHT_CHILD(s_op);
                lselect = GET_LEFT_CHILD(s_op);
                if (NodeOp(lselect) == IndexOp) {
                    off = GetAttr(num_s_ind,12);
                    EMIT("\tmul\t$v0\t$v0\t%d", off);
                    EMIT("\tadd\t$%d\t$%d\t$v0", offr, offr);
                    emit_expr_code(GET_LEFT_CHILD(lselect));
                    EMIT("\tlw\t$v0\t4($sp)");
                    EMIT("\tsll\t$v0\t$v0\t2");
                    EMIT("\tadd\t$%d\t$%d\t$v0", offr, offr);

                    l_reg |= 0x4;
                }
            }

        } else {
            tree lfield = GET_LEFT_CHILD(lselect);
            if (NodeKind(lfield) == IDNode) {
                if ((strcmp((char*)getname(IntVal(lfield)), "length") == 0) && GetAttr(num_s, KIND_ATTR) == ARR) {
                    if (GetAttr(num_s, DIMEN_ATTR) == 1) {
                        EMIT("\tli\t$v0\t%d", GetAttr(num_s, 11));
                    } else if (GetAttr(num_s, DIMEN_ATTR) == 2) {
                        EMIT("\tli\t$v0\t%d", GetAttr(num_s, 11) * GetAttr(num_s, 12));
                    }
                    EMIT("\tsw\t$v0\t0($sp)");
                    EMIT("\taddi\t$sp\t$sp\t-4");
                    l_reg &= ~(1 << offr);
                    return;
                }
            }
            num_s_ind = IntVal(lfield);
            off = GetAttr(num_s_ind,OFFSET_ATTR);
            EMIT("\tadd\t$%d\t$%d\t%d", offr, offr, off);
        }

        s_op = GET_RIGHT_CHILD(s_op);
    }

    switch(GetAttr(num_s, NEST_ATTR)) {
        case 0:
            EMIT("\tadd\t$%d\t$%d\t$gp", offr, offr);

            break;
        case 1:
            add_label = label_counter++;
            aft_label = label_counter++;
            EMIT("\tbeqz\t$t2\tL_%d", add_label);
            EMIT("\tsub\t$%d\t$t1\t$%d", offr, offr);

            EMIT("\tb\tL_%d", aft_label);
            EMIT("L_%d:", add_label);
            EMIT("\tadd\t$%d\t$%d\t$t1", offr, offr);
            EMIT("L_%d:", aft_label);
            break;
        case 2:
            kind = GetAttr(num_s_ind, KIND_ATTR);
            if (kind == REF_ARG) {
                EMIT("\tadd\t$%d\t$fp\t$%d", offr, offr);
                EMIT("\tlw\t$%d\t($%d)", offr, offr);
            } else if (kind == VALUE_ARG) {
                EMIT("\tadd\t$%d\t$fp\t$%d", offr, offr);
            } else {
                EMIT("\tsub\t$%d\t$fp\t$%d", offr, offr);
            }
            break;
    }

    switch(val_addr) {
        case 0:
            EMIT("\tmove\t$t0\t$%d", offr);
            break;
        case 1:
            nr = get_next_reg();
            EMIT("\tlw\t$%d\t($%d)", nr, offr);
            EMIT("\tsw\t$%d\t0($sp)", nr);
            EMIT("\taddi\t$sp\t$sp\t-4");
            break;
        case 2:
            EMIT("\tmove\t$25\t$%d", offr);

            if (GetAttr(num_s, NEST_ATTR) == 2) {
                EMIT("\tli\t$24\t1");
            } else {
                EMIT("\tmove\t$24\t$t2");
            }

            EMIT("\tsw\t$24\t0($sp)");
            EMIT("\taddi\t$sp\t$sp\t-4");
            EMIT("\tsw\t$25\t0($sp)");
            EMIT("\taddi\t$sp\t$sp\t-4");
            l_reg &= ~(1 << offr);
                return num_s_ind;
    }

    l_reg &= ~(1 << offr);
}
