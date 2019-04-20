%%
"bool" return BOOL
"char" return CHAR
"int" return INT
"real" return REAL
"string" return STRING
"int*" return INTPTR
"char*" return CHARPTR
"real*" return REALPTR
"if" return IF
"else" return ELSE
"while" return WHILE
"for" return FOR
"var" return VAR
"func" return FUNC
"proc" return PROC
"return" return RETURN
"null" return NUL
"&&" return AND
"/" return DIV
"=" return ASSGN
"==" return EQUAL
">" return GR
">=" return GREQ
"<" return LS
"<=" return LSEQ
"-" return SUB
"!" return NOT
"!=" return UNEQAL
"||" return OR
"+" return ADD
"*" return MUL
"&" return ADDROF
"^" return DEREF
\n ;

[a-zA-Z][a-zA-Z0-9_]* return ID;
-?[1-9][0-9]*|-?0 return INTVAL
0(x|X)[0-9A-Fa-f]+ return HEXVAL;
-?[0-9]*.[0-9]*|(+|-)?[0-9]*.[0-9]*[Ee](+|-)?[1-9][0-9]* return REALVAL
. return yytext[0]
%%