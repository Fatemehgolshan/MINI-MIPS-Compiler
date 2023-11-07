#!/usr/bin/make

all:
	flex lex.l
	yacc -v grammar.y
	gcc -w -o go y.tab.c table.c seman.c proj2.c proj3.c code_generator.c -lfl

clean:
	rm -rf lex.yy.o lex.yy.c y.tab.c y.tab.o y.output proj3.o proj4.o seman.o go code*.s *.o || true
