%%
#include "lex.yy.c"

%token BOOL, CHAR, INT, REAL, STRING
%token INTVAL, HEXVAL, REALVAL
%token INTPTR, CHARPTR, REALPTR, ADDROF, DEREF
%token IF, ELSE, WHILE, FOR, VAR, ID, FUNC, PROC, RETURN
%token NUL, ASSGN, UNEQUAL, EQUAL, GR, GREQ, LS, LSEQ
%token AND, OR, NOT
%token ADD, SUB, DIV, MUL
%start prog

prog: 

func: FUNC ID '(' params ')' RETURN varType '{' body '}'

body: 

decVar: VAR 

params: | IDlist ':' varType ';' params | IDlist ':' varType

IDlist: ID ',' IDlist | ID

varType: BOOL | CHAR | INT | REAL | STRING | INTPTR | CHARPTR | REALPTR