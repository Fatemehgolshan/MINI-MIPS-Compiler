#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "grammar.y"
#include  "proj2.h"
#include  <stdio.h>

  tree type_record, type_method, argtype;  /* globals used to store treenode pointers */

extern  tree  SyntaxTree;
#line 10 "grammar.y"
typedef union{
  int intg;
  tree tptr;
  } YYSTYPE;
#line 35 "y.tab.c"
#define PROGRAMnum 257
#define IDnum 258
#define SEMInum 259
#define CLASSnum 260
#define DECLARATIONSnum 261
#define ENDDECLARATIONSnum 262
#define COMMAnum 263
#define EQUALnum 264
#define LBRACEnum 265
#define RBRACEnum 266
#define LBRACnum 267
#define RBRACnum 268
#define LPARENnum 269
#define RPARENnum 270
#define VOIDnum 271
#define INTnum 272
#define METHODnum 273
#define VALnum 274
#define DOTnum 275
#define ASSGNnum 276
#define RETURNnum 277
#define IFnum 278
#define ELSEnum 279
#define WHILEnum 280
#define LTnum 281
#define LEnum 282
#define EQnum 283
#define NEnum 284
#define GEnum 285
#define GTnum 286
#define PLUSnum 287
#define MINUSnum 288
#define ORnum 289
#define TIMESnum 290
#define DIVIDEnum 291
#define ANDnum 292
#define NOTnum 293
#define ICONSTnum 294
#define SCONSTnum 295
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    3,    3,    4,    4,    5,    5,
    6,    6,    7,    7,   49,    8,    9,    9,   10,   10,
   11,   11,   12,   12,   14,   14,   14,   15,   16,   16,
   17,   18,   18,   50,   19,   51,   19,   20,   20,   21,
   21,   52,   22,   53,   22,   23,   23,   24,   24,   25,
   25,   25,   26,   26,   13,   13,   27,   28,   28,   29,
   29,   29,   29,   29,   29,   30,   31,   32,   32,   33,
   33,   34,   34,   35,   35,   35,   36,   36,   37,   38,
   38,   39,   39,   39,   39,   39,   39,   40,   40,   40,
   40,   40,   40,   41,   41,   41,   41,   42,   42,   42,
   42,   42,   44,   44,   45,   46,   46,   47,   47,   48,
   48,   43,   43,
};
short yylen[] = {                                         2,
    4,    1,    2,    3,    3,    4,    0,    1,    1,    2,
    2,    3,    1,    2,    0,    4,    1,    3,    1,    3,
    1,    2,    2,    3,    1,    1,    1,    3,    1,    3,
    2,    3,    4,    0,    8,    0,    8,    0,    1,    1,
    3,    0,    3,    0,    4,    1,    3,    1,    2,    1,
    2,    4,    1,    1,    2,    3,    3,    1,    3,    0,
    1,    1,    1,    1,    1,    3,    2,    3,    2,    1,
    3,    1,    2,    3,    2,    4,    4,    5,    3,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    3,    3,    3,    1,    3,    3,    3,    1,    1,    1,
    3,    2,    1,    1,    2,    0,    1,    1,    2,    3,
    2,    1,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    2,    0,    3,    0,
    4,    0,    0,    0,    0,    0,    9,   53,   11,   54,
    0,   13,   15,    0,   36,   34,    5,   10,    0,   12,
   14,    0,    0,    0,    0,    0,    6,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    0,   16,    0,    0,
   56,   52,    0,    0,   23,    0,   20,    0,    0,    0,
    0,    0,    0,    0,  103,  104,   18,   26,   27,  100,
   25,    0,    0,   94,   98,    0,   42,    0,    0,    0,
   40,    0,   24,    0,    0,  105,  107,    0,   29,    0,
    0,    0,    0,    0,    0,  102,   82,   83,   84,   85,
   86,   87,    0,    0,    0,    0,    0,    0,    0,    0,
   67,    0,   44,    0,    0,    0,    0,    0,  111,  109,
    0,   28,  101,    0,    0,    0,    0,    0,    0,   95,
   96,   97,   69,    0,    0,   46,    0,    0,    0,    0,
   37,   48,   41,   35,    0,  110,   30,   32,    0,   68,
    0,    0,    0,    0,    0,    0,    0,   58,   61,   62,
   63,   64,    0,   65,    0,   49,  113,   33,   71,   47,
   73,    0,    0,    0,   57,    0,   75,    0,    0,   79,
   59,    0,   66,   77,    0,   78,
};
short yydgoto[] = {                                       2,
    6,    7,   11,   14,   15,  140,   21,   22,   39,   40,
   41,   47,   34,   67,   68,   90,   69,   93,   17,   79,
   80,   81,  137,  141,   23,   24,  142,  157,  158,  159,
   70,  111,  134,  161,  162,  163,  164,   71,  106,   72,
   73,   74,  118,   75,   76,   86,   87,   88,   32,   36,
   35,  112,  138,
};
short yysindex[] = {                                   -227,
 -254,    0, -228, -211, -169, -211,    0, -175,    0, -195,
    0, -245, -191, -165, -166, -166,    0,    0,    0,    0,
 -244,    0,    0, -146,    0,    0,    0,    0, -128,    0,
    0, -119, -117, -103, -106, -101,    0,  -94,    0,  -88,
  -84, -146, -251,  -86,  -78,  -80,  -61,    0, -119, -253,
    0,    0,  -50,  -50,    0,  -56,    0, -252, -253, -190,
  -51, -236, -236, -236,    0,    0,    0,    0,    0,    0,
    0,   58, -219,    0,    0,  -34,    0,  -65,  -53,  -40,
    0,  -20,    0, -190,   -5,    0,    0, -252,    0, -143,
  -13, -190,   -9, -219, -219,    0,    0,    0,    0,    0,
    0,    0, -236, -236, -236, -190, -236, -236, -236, -233,
    0,    2,    0,  -75,  -50,  -75,   24,   -3,    0,    0,
 -253,    0,    0,    8, -190, -219, -219, -219,  -41,    0,
    0,    0,    0,   -7,   25,    0,   26,    2, -194,   29,
    0,    0,    0,    0, -190,    0,    0,    0,   23,    0,
 -190,   40,   26, -190, -190, -190, -167,    0,    0,    0,
    0,    0, -196,    0, -176,    0,    0,    0,    0,    0,
    0,   29,   29, -194,    0, -190,    0, -190,   20,    0,
    0,   29,    0,    0,   22,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,  304,    0,    0,    0,   51,
    0,    0,    0,    0,   62,   51,    0,    0,    0,    0,
    0,    0,    0,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   71,    0,    0,    0, -189,    0,    0,
  -54, -255,    0,    0,    0,    0, -109,    0,    0,    0,
    0,    0,   60,   60,    0,    0,    0, -157,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -81,  -55,    0,    0,  -89,    0,    0,    0,   65,
    0,    0,    0,    0,    0,    0,    0, -123,    0,    0,
    0,    0, -149,  -45,  -14,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   64,    0,    0,    0,
    0,    0,    0,    0,    0,   -4,   27,   37,   68,    0,
    0,    0,    0,    0,   67,    0, -183,    0, -144,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -182, -122,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -144,    0,    0,    0,    0, -118,    0,
    0,    0,    0,    0, -110,    0,
};
short yygindex[] = {                                      0,
    0,  342,    0,  333,    0,  340,    0,  330,  303,    0,
    0,    0,  311,  -58,    0,    0,    0,    0,  339,  301,
    0,  241,  219,  242,   13,    0, -134,    0,  185,    0,
 -131,    0,  209,    0,    0,    0,    0,  -60,    0,  255,
  -52,  -62,  217,    0, -130,    0,  275,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 363
short yytable[] = {                                      91,
   89,   96,   55,    3,   58,  166,   18,  160,  165,   94,
   95,   59,   18,   18,   84,   60,   19,   30,   61,   55,
   20,   58,   85,  117,   58,   26,   20,   20,  177,    1,
    4,  124,   60,   62,   63,   60,  133,  179,  180,   64,
   65,   66,  160,  165,  130,  131,  132,  185,    5,  135,
  126,  127,  128,   62,   63,   52,   64,   65,   66,   64,
   65,   66,  147,   58,  149,   12,   18,   58,  139,   21,
  107,  108,  109,   21,   21,   43,   45,   13,   60,   25,
   20,  176,  154,  155,  117,  156,   43,   45,    8,   10,
  135,  174,  110,  171,  172,  173,   62,   63,  175,  178,
   27,  106,   64,   65,   66,  106,   13,  106,  106,   31,
  106,  106,  106,   31,   60,  182,   31,  183,  106,  121,
   33,   60,  122,  106,  106,  106,  106,  106,  106,  106,
  106,  106,  106,  106,  106,  108,   72,   37,   38,  108,
   74,  108,  108,   72,  108,  108,  108,   74,   76,   22,
   42,   44,  108,   22,   22,   76,   45,  108,  108,  108,
  108,  108,  108,  108,  108,  108,  108,  108,  108,   99,
   48,   43,   46,   99,   49,   99,   99,   80,   99,   50,
   99,   80,   53,   80,   80,   12,   80,   55,   80,  139,
   54,   99,   99,   99,   99,   99,   99,   99,   99,   99,
   99,   99,   99,   88,   17,   56,  113,   88,   17,   88,
   88,   83,   88,   89,   88,   92,  114,   89,  115,   89,
   89,   77,   89,   78,   89,   88,   88,   88,   88,   88,
   88,   88,   88,   88,  110,   89,   89,   89,   89,   89,
   89,   89,   89,   89,   90,  103,  104,  105,   90,  116,
   90,   90,  119,   90,   91,   90,  123,  125,   91,  136,
   91,   91,  150,   91,  146,   91,   90,   90,   90,   90,
   90,   90,   90,   90,   90,  148,   91,   91,   91,   91,
   91,   91,   91,   91,   91,   92,  145,  151,  152,   92,
  168,   92,   92,  139,   92,   93,   92,  170,  184,   93,
  186,   93,   93,    1,   93,   50,   93,   92,   92,   92,
   92,   92,   92,   92,   92,   92,    7,   93,   93,   93,
   93,   93,   93,   93,   93,   93,   81,    8,   51,   38,
   81,  112,   81,   81,   39,   81,   70,   81,   97,   98,
   99,  100,  101,  102,  103,  104,  105,    9,   29,   16,
   31,   57,   51,   28,   82,  143,  153,  144,  181,  169,
  129,  167,  120,
};
short yycheck[] = {                                      60,
   59,   64,  258,  258,  258,  140,  258,  139,  139,   62,
   63,  265,  258,  258,  267,  269,  262,  262,  272,  275,
  272,  258,  275,   84,  258,   13,  272,  272,  163,  257,
  259,   92,  269,  287,  288,  269,  270,  172,  173,  293,
  294,  295,  174,  174,  107,  108,  109,  182,  260,  110,
  103,  104,  105,  287,  288,   43,  293,  294,  295,  293,
  294,  295,  121,  258,  125,  261,  258,  258,  265,  259,
  290,  291,  292,  263,  264,  259,  259,  273,  269,  271,
  272,  278,  277,  278,  145,  280,  270,  270,  258,  265,
  151,  259,  269,  154,  155,  156,  287,  288,  266,  276,
  266,  259,  293,  294,  295,  263,  273,  265,  266,  259,
  268,  269,  270,  263,  259,  176,  266,  178,  276,  263,
  267,  266,  266,  281,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  259,  259,  266,  258,  263,
  259,  265,  266,  266,  268,  269,  270,  266,  259,  259,
  268,  258,  276,  263,  264,  266,  258,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  259,
  259,  275,  267,  263,  263,  265,  266,  259,  268,  264,
  270,  263,  269,  265,  266,  261,  268,  268,  270,  265,
  269,  281,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  259,  259,  267,  272,  263,  263,  265,
  266,  268,  268,  259,  270,  267,  270,  263,  259,  265,
  266,  272,  268,  274,  270,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  269,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  259,  287,  288,  289,  263,  270,
  265,  266,  258,  268,  259,  270,  270,  267,  263,  258,
  265,  266,  270,  268,  268,  270,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  268,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  259,  263,  263,  263,  263,
  268,  265,  266,  265,  268,  259,  270,  258,  279,  263,
  279,  265,  266,    0,  268,  258,  270,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  266,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  259,  266,  258,  270,
  263,  268,  265,  266,  270,  268,  270,  270,  281,  282,
  283,  284,  285,  286,  287,  288,  289,    6,   16,   10,
   21,   49,   42,   15,   54,  115,  138,  116,  174,  151,
  106,  145,   88,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 295
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PROGRAMnum","IDnum","SEMInum",
"CLASSnum","DECLARATIONSnum","ENDDECLARATIONSnum","COMMAnum","EQUALnum",
"LBRACEnum","RBRACEnum","LBRACnum","RBRACnum","LPARENnum","RPARENnum","VOIDnum",
"INTnum","METHODnum","VALnum","DOTnum","ASSGNnum","RETURNnum","IFnum","ELSEnum",
"WHILEnum","LTnum","LEnum","EQnum","NEnum","GEnum","GTnum","PLUSnum","MINUSnum",
"ORnum","TIMESnum","DIVIDEnum","ANDnum","NOTnum","ICONSTnum","SCONSTnum",
};
char *yyrule[] = {
"$accept : Program",
"Program : PROGRAMnum IDnum SEMInum ClassDecl_rec",
"ClassDecl_rec : ClassDecl",
"ClassDecl_rec : ClassDecl_rec ClassDecl",
"ClassDecl : CLASSnum IDnum ClassBody",
"ClassBody : LBRACEnum MethodDecl_z1 RBRACEnum",
"ClassBody : LBRACEnum Decls MethodDecl_z1 RBRACEnum",
"MethodDecl_z1 :",
"MethodDecl_z1 : MethodDecl_rec",
"MethodDecl_rec : MethodDecl",
"MethodDecl_rec : MethodDecl_rec MethodDecl",
"Decls : DECLARATIONSnum ENDDECLARATIONSnum",
"Decls : DECLARATIONSnum FieldDecl_rec ENDDECLARATIONSnum",
"FieldDecl_rec : FieldDecl",
"FieldDecl_rec : FieldDecl_rec FieldDecl",
"$$1 :",
"FieldDecl : Type $$1 FieldDecl_body SEMInum",
"Tail : VariableDeclId",
"Tail : VariableDeclId EQUALnum VariableInitializer",
"FieldDecl_body : Tail",
"FieldDecl_body : FieldDecl_body COMMAnum Tail",
"VariableDeclId : IDnum",
"VariableDeclId : IDnum Bracket_rec1",
"Bracket_rec1 : LBRACnum RBRACnum",
"Bracket_rec1 : Bracket_rec1 LBRACnum RBRACnum",
"VariableInitializer : Expression",
"VariableInitializer : ArrayInitializer",
"VariableInitializer : ArrayCreationExpression",
"ArrayInitializer : LBRACEnum ArrayInitializer_body RBRACEnum",
"ArrayInitializer_body : VariableInitializer",
"ArrayInitializer_body : ArrayInitializer_body COMMAnum VariableInitializer",
"ArrayCreationExpression : INTnum ArrayCreationExpression_tail",
"ArrayCreationExpression_tail : LBRACnum Expression RBRACnum",
"ArrayCreationExpression_tail : ArrayCreationExpression_tail LBRACnum Expression RBRACnum",
"$$2 :",
"MethodDecl : METHODnum Type $$2 IDnum LPARENnum FormalParameterList_z1 RPARENnum Block",
"$$3 :",
"MethodDecl : METHODnum VOIDnum $$3 IDnum LPARENnum FormalParameterList_z1 RPARENnum Block",
"FormalParameterList_z1 :",
"FormalParameterList_z1 : FormalParameterList",
"FormalParameterList : FormalParameterList_rec",
"FormalParameterList : FormalParameterList SEMInum FormalParameterList_rec",
"$$4 :",
"FormalParameterList_rec : INTnum $$4 IDENTIFIER_rec",
"$$5 :",
"FormalParameterList_rec : VALnum INTnum $$5 IDENTIFIER_rec",
"IDENTIFIER_rec : IDnum",
"IDENTIFIER_rec : IDENTIFIER_rec COMMAnum IDnum",
"Block : StatementList",
"Block : Decls StatementList",
"Type : Type_front",
"Type : Type_front Bracket_rec2",
"Type : Type_front Bracket_rec2 DOTnum Type",
"Type_front : IDnum",
"Type_front : INTnum",
"Bracket_rec2 : LBRACnum RBRACnum",
"Bracket_rec2 : LBRACnum RBRACnum Bracket_rec2",
"StatementList : LBRACEnum Statement_rec RBRACEnum",
"Statement_rec : Statement",
"Statement_rec : Statement_rec SEMInum Statement",
"Statement :",
"Statement : AssignmentStatement",
"Statement : MethodCallStatement",
"Statement : ReturnStatement",
"Statement : IfStatement",
"Statement : WhileStatement",
"AssignmentStatement : Variable ASSGNnum Expression",
"MethodCallStatement : Variable MethodCallStatement_tail",
"MethodCallStatement_tail : LPARENnum Expression_rec RPARENnum",
"MethodCallStatement_tail : LPARENnum RPARENnum",
"Expression_rec : Expression",
"Expression_rec : Expression COMMAnum Expression_rec",
"ReturnStatement : RETURNnum",
"ReturnStatement : RETURNnum Expression",
"IfStatement : IFnum Expression StatementList",
"IfStatement : If_rec StatementList",
"IfStatement : If_rec IFnum Expression StatementList",
"If_rec : IFnum Expression StatementList ELSEnum",
"If_rec : If_rec IFnum Expression StatementList ELSEnum",
"WhileStatement : WHILEnum Expression StatementList",
"Expression : SimpleExpression",
"Expression : SimpleExpression Comp_op SimpleExpression",
"Comp_op : LTnum",
"Comp_op : LEnum",
"Comp_op : EQnum",
"Comp_op : NEnum",
"Comp_op : GEnum",
"Comp_op : GTnum",
"SimpleExpression : Term",
"SimpleExpression : PLUSnum Term",
"SimpleExpression : MINUSnum Term",
"SimpleExpression : SimpleExpression PLUSnum Term",
"SimpleExpression : SimpleExpression MINUSnum Term",
"SimpleExpression : SimpleExpression ORnum Term",
"Term : Factor",
"Term : Term TIMESnum Factor",
"Term : Term DIVIDEnum Factor",
"Term : Term ANDnum Factor",
"Factor : UnsignedConstant",
"Factor : Variable",
"Factor : MethodCallStatement",
"Factor : LPARENnum Expression RPARENnum",
"Factor : NOTnum Factor",
"UnsignedConstant : ICONSTnum",
"UnsignedConstant : SCONSTnum",
"Variable : IDnum Variable_tail",
"Variable_tail :",
"Variable_tail : Variable_rec",
"Variable_rec : Variable_1",
"Variable_rec : Variable_1 Variable_rec",
"Variable_1 : LBRACnum Expression_rec2 RBRACnum",
"Variable_1 : DOTnum IDnum",
"Expression_rec2 : Expression",
"Expression_rec2 : Expression COMMAnum Expression_rec2",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 396 "grammar.y"

int yycolumn, yyline;

FILE *treelst;

/*main()
{
  treelst = stdout;
  yyparse();
} */

yyerror(char *str)
{
  printf("yyerror: %s at line %d\n", str, yyline);
}

#include "lex.yy.c"


#line 452 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 34 "grammar.y"
{  
                          yyval.tptr = MakeTree(ProgramOp, yyvsp[0].tptr, NullExp()); 
                          SyntaxTree = yyval.tptr;
                          /* printtree($$, 0); */
                        }
break;
case 2:
#line 41 "grammar.y"
{  yyval.tptr = MakeTree(ClassOp, NullExp(), yyvsp[0].tptr); }
break;
case 3:
#line 43 "grammar.y"
{  yyval.tptr = MakeTree(ClassOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 4:
#line 46 "grammar.y"
{  yyval.tptr = MakeTree(ClassDefOp, yyvsp[0].tptr, MakeLeaf(IDNode, yyvsp[-1].intg)); }
break;
case 5:
#line 49 "grammar.y"
{  yyval.tptr = yyvsp[-1].tptr; }
break;
case 6:
#line 51 "grammar.y"
{  /*tree tt;
			       tt = MakeTree(BodyOp, NullExp(), $2);*/

                             if ( NodeKind(yyvsp[-1].tptr) == DUMMYNode )/* $3 is a NULL node */
                               yyval.tptr = yyvsp[-2].tptr;
                             else/* $2 is the left child of $3 */
			       yyval.tptr = MkLeftC(yyvsp[-2].tptr, yyvsp[-1].tptr);
			  }
break;
case 7:
#line 61 "grammar.y"
{  yyval.tptr = NullExp(); }
break;
case 8:
#line 63 "grammar.y"
{  yyval.tptr = yyvsp[0].tptr; }
break;
case 9:
#line 66 "grammar.y"
{  yyval.tptr = MakeTree(BodyOp, NullExp(), yyvsp[0].tptr); }
break;
case 10:
#line 68 "grammar.y"
{  yyval.tptr = MakeTree(BodyOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 11:
#line 71 "grammar.y"
{  yyval.tptr = MakeTree(BodyOp, NullExp(), NullExp()); }
break;
case 12:
#line 73 "grammar.y"
{  yyval.tptr = yyvsp[-1].tptr; }
break;
case 13:
#line 76 "grammar.y"
{  yyval.tptr = MakeTree(BodyOp, NullExp(), yyvsp[0].tptr); }
break;
case 14:
#line 78 "grammar.y"
{  yyval.tptr = MakeTree(BodyOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 15:
#line 80 "grammar.y"
{ type_record = yyvsp[0].tptr; }
break;
case 16:
#line 81 "grammar.y"
{  yyval.tptr = yyvsp[-1].tptr; /* $3 is FieldDecl_body */ }
break;
case 17:
#line 84 "grammar.y"
{ 
                              tree commat;
                              commat = MakeTree(CommaOp, type_record, NullExp());
                              yyval.tptr = MakeTree(CommaOp, yyvsp[0].tptr, commat);
                           }
break;
case 18:
#line 90 "grammar.y"
{
                              tree commat;
                              commat = MakeTree(CommaOp, type_record, yyvsp[0].tptr);
                              yyval.tptr = MakeTree(CommaOp, yyvsp[-2].tptr, commat);
                           }
break;
case 19:
#line 97 "grammar.y"
{  yyval.tptr = MakeTree(DeclOp, NullExp(), yyvsp[0].tptr);  }
break;
case 20:
#line 99 "grammar.y"
{  yyval.tptr = MakeTree(DeclOp, yyvsp[-2].tptr, yyvsp[0].tptr);  }
break;
case 21:
#line 102 "grammar.y"
{  yyval.tptr = MakeLeaf(IDNode, yyvsp[0].intg); }
break;
case 22:
#line 104 "grammar.y"
{   yyval.tptr = MakeLeaf(IDNode, yyvsp[-1].intg); /* "[]" do not construct tree */ }
break;
case 23:
#line 106 "grammar.y"
{ yyval.tptr = NullExp(); }
break;
case 24:
#line 107 "grammar.y"
{ yyval.tptr = NullExp(); }
break;
case 25:
#line 110 "grammar.y"
{  yyval.tptr = yyvsp[0].tptr; }
break;
case 26:
#line 112 "grammar.y"
{  yyval.tptr = yyvsp[0].tptr; }
break;
case 27:
#line 114 "grammar.y"
{  yyval.tptr = yyvsp[0].tptr; }
break;
case 28:
#line 117 "grammar.y"
{  yyval.tptr = MakeTree(ArrayTypeOp, yyvsp[-1].tptr, type_record); }
break;
case 29:
#line 120 "grammar.y"
{ yyval.tptr = MakeTree( CommaOp, NullExp(), yyvsp[0].tptr); }
break;
case 30:
#line 122 "grammar.y"
{ yyval.tptr = MakeTree( CommaOp, yyvsp[-2].tptr, yyvsp[0].tptr ); }
break;
case 31:
#line 125 "grammar.y"
{  yyval.tptr = MakeTree( ArrayTypeOp, yyvsp[0].tptr, MakeLeaf(INTEGERTNode, yyvsp[-1].intg) ); }
break;
case 32:
#line 128 "grammar.y"
{ yyval.tptr = MakeTree( BoundOp, NullExp(), yyvsp[-1].tptr ); }
break;
case 33:
#line 130 "grammar.y"
{ yyval.tptr = MakeTree( BoundOp, yyvsp[-3].tptr, yyvsp[-1].tptr ); }
break;
case 34:
#line 132 "grammar.y"
{type_method=yyvsp[0].tptr;}
break;
case 35:
#line 134 "grammar.y"
{ 
                        tree head;
                        head = MakeTree(HeadOp, MakeLeaf(IDNode, yyvsp[-4].intg), yyvsp[-2].tptr);
                        yyval.tptr = MakeTree(MethodOp, head, yyvsp[0].tptr);
                      }
break;
case 36:
#line 139 "grammar.y"
{type_method=NullExp();}
break;
case 37:
#line 140 "grammar.y"
{ 
                        tree head;
                        head = MakeTree(HeadOp, MakeLeaf(IDNode, yyvsp[-4].intg), yyvsp[-2].tptr);
                        yyval.tptr = MakeTree(MethodOp, head, yyvsp[0].tptr);
                      }
break;
case 38:
#line 147 "grammar.y"
{  yyval.tptr = MakeTree(SpecOp, NullExp(), type_method); }
break;
case 39:
#line 149 "grammar.y"
{  yyval.tptr = MakeTree(SpecOp, yyvsp[0].tptr, type_method); }
break;
case 40:
#line 153 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 41:
#line 155 "grammar.y"
{ yyval.tptr = MkRightC(yyvsp[0].tptr, yyvsp[-2].tptr); }
break;
case 42:
#line 158 "grammar.y"
{
                                      argtype = MakeTree(RArgTypeOp, NullExp(), NullExp());
                                      yyval.tptr = MakeTree(RArgTypeOp, NullExp(), argtype);/* lchild is unknown*/
                                    }
break;
case 43:
#line 163 "grammar.y"
{ 
                                      SetLeftChild(yyvsp[-1].tptr, yyvsp[0].tptr);
                                      if ( NodeKind(LeftChild(RightChild(yyvsp[-1].tptr))) == DUMMYNode )/* no comma */
                                         SetRightChild( yyvsp[-1].tptr, NullExp() );
                                      else
					{
					  tree t = yyvsp[-1].tptr; /* head of the tree */
                                          /* delete the tangling right most child */
                                          while ( t->RightC != argtype )
                                                 t = t->RightC;
                                          t->RightC = NullExp();
                                          free( argtype );
                                        }
                                      yyval.tptr = yyvsp[-1].tptr;  /* return to FormalParameterList_rec */                  
                                    }
break;
case 44:
#line 180 "grammar.y"
{
                                      argtype = MakeTree(VArgTypeOp, NullExp(), NullExp());
                                      yyval.tptr = MakeTree(VArgTypeOp, NullExp(), argtype);/* lchild is unknown*/
				    }
break;
case 45:
#line 185 "grammar.y"
{
                                      SetLeftChild(yyvsp[-1].tptr, yyvsp[0].tptr); 
                                      if ( NodeKind(LeftChild(RightChild(yyvsp[-1].tptr))) == DUMMYNode )/* no comma */
                                         SetRightChild( yyvsp[-1].tptr, NullExp() );  
                                      else
					{
					  tree t = yyvsp[-1].tptr; /* head of the tree */
                                          /* delete the tangling right most child */
                                          while ( t->RightC != argtype )
                                                 t = t->RightC;
                                          t->RightC = NullExp();
                                          free( argtype );
                                        }
                                      yyval.tptr = yyvsp[-1].tptr;  /* return to FormalParameterList_rec */                  
			            }
break;
case 46:
#line 203 "grammar.y"
{ yyval.tptr = MakeTree(CommaOp, MakeLeaf(IDNode,yyvsp[0].intg), MakeLeaf(INTEGERTNode,0)); }
break;
case 47:
#line 205 "grammar.y"
{ 
                                    tree comma, temp;

                                    yyval.tptr = yyvsp[-2].tptr;
                                    comma = MakeTree(CommaOp, MakeLeaf(IDNode,yyvsp[0].intg), MakeLeaf(INTEGERTNode,0));
                                    MkLeftC( comma, argtype );
                                    temp = MakeTree(NodeOp(argtype), NullExp(), NullExp());
                                    SetRightChild(argtype, temp);
                                    argtype = temp;
                                  }
break;
case 48:
#line 217 "grammar.y"
{ yyval.tptr = MakeTree(BodyOp, NullExp(), yyvsp[0].tptr); }
break;
case 49:
#line 219 "grammar.y"
{ yyval.tptr = MakeTree(BodyOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 50:
#line 222 "grammar.y"
{ yyval.tptr = MakeTree(TypeIdOp, yyvsp[0].tptr, NullExp()); }
break;
case 51:
#line 224 "grammar.y"
{ yyval.tptr = MakeTree(TypeIdOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 52:
#line 226 "grammar.y"
{ 
                         tree temp;
                         temp = MakeTree(TypeIdOp, yyvsp[-3].tptr, yyvsp[-2].tptr);
                         yyval.tptr = MkRightC( yyvsp[0].tptr, temp );
		       }
break;
case 53:
#line 233 "grammar.y"
{ yyval.tptr = MakeLeaf(IDNode, yyvsp[0].intg); }
break;
case 54:
#line 235 "grammar.y"
{ yyval.tptr = MakeLeaf(INTEGERTNode, yyvsp[0].intg);}
break;
case 55:
#line 238 "grammar.y"
{ yyval.tptr = MakeTree(IndexOp, NullExp(), NullExp()); }
break;
case 56:
#line 240 "grammar.y"
{ yyval.tptr = MakeTree(IndexOp, NullExp(), yyvsp[0].tptr); }
break;
case 57:
#line 243 "grammar.y"
{ yyval.tptr = yyvsp[-1].tptr; }
break;
case 58:
#line 246 "grammar.y"
{ yyval.tptr = MakeTree(StmtOp, NullExp(), yyvsp[0].tptr);  }
break;
case 59:
#line 248 "grammar.y"
{ 
                        if ( NodeKind(yyvsp[0].tptr) == DUMMYNode )
                           yyval.tptr = yyvsp[-2].tptr;
                        else
                           yyval.tptr = MakeTree(StmtOp, yyvsp[-2].tptr, yyvsp[0].tptr);
                      }
break;
case 60:
#line 256 "grammar.y"
{ yyval.tptr = NullExp(); }
break;
case 61:
#line 258 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 62:
#line 260 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 63:
#line 262 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 64:
#line 264 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 65:
#line 266 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 66:
#line 269 "grammar.y"
{ yyval.tptr = MakeTree(AssignOp, MakeTree(AssignOp, NullExp(), yyvsp[-2].tptr), yyvsp[0].tptr); }
break;
case 67:
#line 272 "grammar.y"
{ yyval.tptr = MakeTree(RoutineCallOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 68:
#line 275 "grammar.y"
{ yyval.tptr = yyvsp[-1].tptr; }
break;
case 69:
#line 277 "grammar.y"
{ yyval.tptr = NullExp(); }
break;
case 70:
#line 280 "grammar.y"
{  yyval.tptr = MakeTree( CommaOp, yyvsp[0].tptr, NullExp() ); }
break;
case 71:
#line 282 "grammar.y"
{  yyval.tptr = MakeTree( CommaOp, yyvsp[-2].tptr, yyvsp[0].tptr ); }
break;
case 72:
#line 285 "grammar.y"
{  yyval.tptr = MakeTree(ReturnOp, NullExp(), NullExp() ); }
break;
case 73:
#line 287 "grammar.y"
{  yyval.tptr = MakeTree(ReturnOp, yyvsp[0].tptr, NullExp()); }
break;
case 74:
#line 290 "grammar.y"
{ yyval.tptr = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yyvsp[-1].tptr, yyvsp[0].tptr)); }
break;
case 75:
#line 292 "grammar.y"
{ yyval.tptr = MakeTree(IfElseOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 76:
#line 294 "grammar.y"
{ 
                            tree temp;
                            temp = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yyvsp[-1].tptr, yyvsp[0].tptr)); 
                            yyval.tptr = MkLeftC( yyvsp[-3].tptr, temp);
                          }
break;
case 77:
#line 301 "grammar.y"
{ yyval.tptr = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yyvsp[-2].tptr, yyvsp[-1].tptr)); }
break;
case 78:
#line 303 "grammar.y"
{  
                            tree temp;
                            temp = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yyvsp[-2].tptr, yyvsp[-1].tptr));
                            yyval.tptr = MkLeftC( yyvsp[-4].tptr, temp);                          
                          }
break;
case 79:
#line 310 "grammar.y"
{  yyval.tptr = MakeTree(LoopOp, yyvsp[-1].tptr, yyvsp[0].tptr); }
break;
case 80:
#line 313 "grammar.y"
{yyval.tptr = yyvsp[0].tptr;}
break;
case 81:
#line 315 "grammar.y"
{
                            MkLeftC(yyvsp[-2].tptr, yyvsp[-1].tptr);
                            yyval.tptr = MkRightC(yyvsp[0].tptr, yyvsp[-1].tptr);
                          }
break;
case 82:
#line 321 "grammar.y"
{ yyval.tptr = MakeTree(LTOp, NullExp(), NullExp()); }
break;
case 83:
#line 323 "grammar.y"
{ yyval.tptr = MakeTree(LEOp, NullExp(), NullExp()); }
break;
case 84:
#line 325 "grammar.y"
{ yyval.tptr = MakeTree(EQOp, NullExp(), NullExp()); }
break;
case 85:
#line 327 "grammar.y"
{ yyval.tptr = MakeTree(NEOp, NullExp(), NullExp()); }
break;
case 86:
#line 329 "grammar.y"
{ yyval.tptr = MakeTree(GEOp, NullExp(), NullExp()); }
break;
case 87:
#line 331 "grammar.y"
{ yyval.tptr = MakeTree(GTOp, NullExp(), NullExp()); }
break;
case 88:
#line 334 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 89:
#line 336 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 90:
#line 338 "grammar.y"
{ yyval.tptr = MakeTree(UnaryNegOp, yyvsp[0].tptr, NullExp()); }
break;
case 91:
#line 340 "grammar.y"
{ yyval.tptr = MakeTree(AddOp, yyvsp[-2].tptr, yyvsp[0].tptr); }
break;
case 92:
#line 342 "grammar.y"
{ yyval.tptr = MakeTree(SubOp, yyvsp[-2].tptr, yyvsp[0].tptr); }
break;
case 93:
#line 344 "grammar.y"
{ yyval.tptr = MakeTree(OrOp, yyvsp[-2].tptr, yyvsp[0].tptr); }
break;
case 94:
#line 347 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 95:
#line 349 "grammar.y"
{ yyval.tptr = MakeTree(MultOp, yyvsp[-2].tptr, yyvsp[0].tptr); }
break;
case 96:
#line 351 "grammar.y"
{ yyval.tptr = MakeTree(DivOp, yyvsp[-2].tptr, yyvsp[0].tptr); }
break;
case 97:
#line 353 "grammar.y"
{ yyval.tptr = MakeTree(AndOp, yyvsp[-2].tptr, yyvsp[0].tptr); }
break;
case 98:
#line 356 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 99:
#line 358 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 100:
#line 360 "grammar.y"
{ yyval.tptr = yyvsp[0].tptr; }
break;
case 101:
#line 362 "grammar.y"
{ yyval.tptr = yyvsp[-1].tptr; }
break;
case 102:
#line 364 "grammar.y"
{ yyval.tptr = MakeTree(NotOp, yyvsp[0].tptr, NullExp()); }
break;
case 103:
#line 367 "grammar.y"
{ yyval.tptr = MakeLeaf(NUMNode, yyvsp[0].intg); }
break;
case 104:
#line 369 "grammar.y"
{ yyval.tptr = MakeLeaf(STRINGNode, yyvsp[0].intg); }
break;
case 105:
#line 372 "grammar.y"
{ yyval.tptr = MakeTree( VarOp, MakeLeaf(IDNode, yyvsp[-1].intg), yyvsp[0].tptr); }
break;
case 106:
#line 375 "grammar.y"
{  yyval.tptr = NullExp(); }
break;
case 107:
#line 377 "grammar.y"
{  yyval.tptr = yyvsp[0].tptr; }
break;
case 108:
#line 380 "grammar.y"
{ yyval.tptr = MakeTree( SelectOp, yyvsp[0].tptr, NullExp() ); }
break;
case 109:
#line 382 "grammar.y"
{ yyval.tptr = MakeTree( SelectOp, yyvsp[-1].tptr, yyvsp[0].tptr ); }
break;
case 110:
#line 385 "grammar.y"
{  yyval.tptr = yyvsp[-1].tptr; }
break;
case 111:
#line 387 "grammar.y"
{  yyval.tptr = MakeTree(FieldOp, MakeLeaf(IDNode, yyvsp[0].intg), NullExp() ); }
break;
case 112:
#line 390 "grammar.y"
{ yyval.tptr = MakeTree(IndexOp, yyvsp[0].tptr, NullExp()); }
break;
case 113:
#line 392 "grammar.y"
{ yyval.tptr = MakeTree(IndexOp, yyvsp[-2].tptr, yyvsp[0].tptr); }
break;
#line 1175 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
