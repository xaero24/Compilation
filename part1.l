
%{
	int counter=1;
        #include <string.h> 
%}
%x String 
%x comment
%%
[ ]+ ;
"bool" return BOOL;
"char" return CHAR;
"int" return INT;
"string" return STRING;
"real" return REAL;
"intptr" return INTPTR;
"charptr" return CHARPTR;
"void" return VOID;
"if" return IF;
"else" return ELSE;
"do" return DO;
"while" return WHILE;
"proc" return PROC;
"func" return FUNC;
"for" return FOR;
"Main" return MAIN;
"return" return RETURN;
"true" return BOOLTRUE;
"false" return BOOLFALSE;
"null" return CSNULL;
"var" return VAR;
"=" return ASSIGNMENT;
"&&" return AND;
\/ return DIVISION;
"==" return EQUAL;
">" return GREATER;
">=" return GREATEREQUAL;
"<" return LESS;
"<=" return LESSEQUAL;
"-" return MINUS;
"!" return NOT;
"!=" return NOTEQUAL;
"||" return OR;
"+" return PLUS;
"*" return MULTI;
"&" return ADDRESS;
"^" return DEREFERENCE;
";" return SEMICOLON;
":" return COLON;
"," return COMMA;
"{" return LEFTBRACE;
"}" return RIGHTBRACE;
"(" return LEFTPAREN;
")" return RIGHTPAREN;
"[" return LEFTBRACKET;
"]" return RIGHTBRACKET;
"%" return PERCENT;
"'"  return QUOTES;
"/%" BEGIN comment;
<comment>[^\n] ;
<comment>\n     ;/*counter++;*/
<comment>"%/" BEGIN 0;
[a-zA-Z][a-zA-Z0-9_]* return ID;
0|[1-9][0-9]* return INTEGER_POS;
-[1-9][0-9]* return INTEGER_NEG;
-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) return REAL;
[\'].[\'] return CHAR;
[\"][^\"]*[\"] return STRING;
0(x|X)[0-9A-Fa-f]+ return HEX;
\n      ;counter++;
[ \t] ;
. return yytext[0]; ;
%%
