%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *token;
    struct node *left;
    struct node *middle;
    struct node *right;
} node;

node *mknode (char *token, node *left, node* middle, node *right);
void printtree (node *tree, int tab);
#define YYSTYPE struct node *
%}
%token BOOL, CHAR, INT, STRING, INTPTR, CHARPTR, ID, VOID, QUOTES
%token IF, ELSE, WHILE, FOR, DO, VAR
%token MAIN, RETURN, PROC, FUNC
%token BOOLTRUE, BOOLFALSE, CSNULL, INTEGER, CHAR, STRING, HEX, REAL
%token ASSIGNMENT, AND, DIVISION, EQUAL, GREATER, GREATEREQUAL, LESS, LESSEQUAL, MINUS, NOT, NOTEQUAL, OR, PLUS, MULTI
%token ADDRESS, DEREFERENCE, SEMICOLON, COLON, COMMA, LEFTBRACE, RIGHTBRACE, LEFTPAREN, RIGHTPAREN, LEFTBRACKET, RIGHTBRACKET, PERCENT, QUOTES

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right ASSIGNMENT NOT SEMICOLON MAIN
%left LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN
%left EQUAL GREATER GREATEREQUAL LESSEQUAL LESS NOTEQUAL
%left PLUS MINUS AND OR
%left MULTI DIVISION
%start s
%%
s:          code { printtree ($1,0); } ;
code:       procs { $$ = mknode("(CODE", $1,NULL,mknode (")", NULL, NULL, NULL)); } ;
procs:      procedures procMain { $$ = mknode("", $1,$2,NULL); }
          | procMain { $$ = mknode("", $1,NULL,NULL); } ;
       
       
       /*________________________________________________PROCEDURES________________________________________________*/
procedures: proc procedures {$$ = mknode ("", $1, $2, NULL); }
          | proc {$$ = mknode ("", $1, NULL, NULL); };

proc:       procReg
          | func       
procReg:    PROC id LEFTPAREN params RIGHTPAREN voidBlock {$$ = mknode ("(PROC", $2, $4, mknode ("", $6, NULL, mknode (")", NULL, NULL, NULL))); } ;
func:       FUNC id LEFTPAREN params RIGHTPAREN valueBlock {$$ = mknode ("(PROC", $2, $4, mknode ("", $6, NULL, mknode (")", NULL, NULL, NULL))); } ;
procMain:   PROC MAIN LEFTPAREN RIGHTPAREN voidBlock {$$ = mknode ("(PROC MAIN", NULL, NULL, mknode ("", $5, NULL, mknode (")", NULL, NULL, NULL))); };
procID:     varType id {$$ = mknode ("procID", $1, $2, NULL); } ;


      /*________________________________________________PARAMS DECLARE______________________________________________*/
params:   | parDec {$$ = mknode ("(ARGS", $1, NULL, mknode (")", NULL, NULL,NULL )); };
parDec:     param COMMA parDec {$$ = mknode ("", $1, NULL, $3); }   
          | param ;
/* to change tree design\print, toggle between following: 1) [type id] 2) [][type][id] */
/*param: varType id {char *s = " "; s=  strcat ($1->token,s);  $$ = mknode (strcat($1->token,$2->token), NULL, NULL, NULL); }   ;*/
param:      varType id {$$ = mknode ("", $1, NULL, $2); }   ;
  
       /*______________________________________________EXPR____________________________________________________________*/
expr:       expr PLUS expr    {$$ = mknode ("(+", $1, $3, mknode (")", NULL, NULL, NULL)); }
          | expr MINUS expr {$$ = mknode ("-", $1, NULL, $3); }
          | expr MULTI expr {$$ = mknode ("*", $1, NULL, $3); }
          | expr DIVISION expr  {$$ = mknode ("/", $1, NULL, $3); }
          | expr EQUAL expr  { $$ = mknode ("==", $1, NULL, $3); }
          | expr GREATER expr  { $$ = mknode (">", $1, NULL, $3); }
          | expr GREATEREQUAL expr { $$ = mknode (">=", $1, NULL, $3); }
          | expr LESS expr { $$ = mknode ("<", $1, NULL, $3); }
          | expr LESSEQUAL expr { $$ = mknode ("<=", $1, NULL, $3); }
          | expr NOTEQUAL expr { $$ = mknode ("!=", $1, NULL, $3); }
          | expr AND expr {$$ = mknode ("&&", $1, NULL, $3); }
          | expr OR expr {$$ = mknode ("||", $1, NULL, $3); }
          | NOT expr {$$ = mknode ("!", NULL, NULL, $2); }
          | ADDRESS id  {$$ = mknode ("&", $2, NULL,NULL ); }
          | derefID 
          | Pexpr
          | consts ;

        
        /*______________________________________________________BLOCKS_____________________________________________________*/
Pexpr:      LEFTPAREN expr RIGHTPAREN { $$ = mknode ("(", $2, NULL, mknode (")", NULL, NULL,NULL )); };
valueBlock: LEFTBRACE newline RETURN expr SEMICOLON RIGHTBRACE { $$ = mknode ("(BLOCK", $2, $4, mknode (")", NULL, NULL,NULL )); }
          | LEFTBRACE RETURN expr SEMICOLON RIGHTBRACE { $$ = mknode ("(BLOCK", $3, NULL, mknode (")", NULL, NULL,NULL )); };
            
voidBlock:  emptyBlock 
          | LEFTBRACE newline RETURN SEMICOLON RIGHTBRACE {$$ = mknode ("(BLOCK", $2, NULL, mknode (")", NULL, NULL,NULL )); }
          | LEFTBRACE RETURN SEMICOLON RIGHTBRACE {$$ = mknode ("(BLOCK", $2, NULL, mknode (")", NULL, NULL,NULL )); }
          | LEFTBRACE newline RIGHTBRACE {$$ = mknode ("(BLOCK", $2, NULL, mknode (")", NULL, NULL,NULL )); };

block_statements:
            emptyBlock
          | LEFTBRACE newline RIGHTBRACE {$$ = mknode ("(BLOCK", $2, NULL, mknode (")", NULL, NULL,NULL )); };

emptyBlock: LEFTBRACE RIGHTBRACE {$$ = mknode ("(BLOCK", $2, NULL, mknode (")", NULL, NULL,NULL )); };

              /*_________________________________________________TYPES________________________________________________*/
consts:     id
          | numbers
          | booleans
          | csnull
          | strings
          | chars
          | procCall;

id:         ID {$$ = mknode (yytext, NULL, NULL, NULL); }  ;

numbers:    INTEGER { $$ = mknode (yytext, NULL, NULL, NULL); }
          | HEX { $$ = mknode (yytext, NULL, NULL, NULL); };

csnull:     CSNULL  { $$ = mknode (yytext, NULL, NULL, NULL); };

booleans:   BOOLTRUE { $$ = mknode (yytext, NULL, NULL, NULL); }
          | BOOLFALSE { $$ = mknode (yytext, NULL, NULL, NULL); };

strings:    STRING { $$ = mknode (yytext, NULL, NULL, NULL); };

chars:      CHAR { $$ = mknode (yytext, NULL, NULL, NULL); };

procCall:   id LEFTPAREN args RIGHTPAREN { $$ = mknode ("func call", $1, NULL, $3); };

args:     | argsDec {$$ = mknode ("args:", $1, NULL, NULL); };
argsDec:    consts COMMA argsDec  {$$ = mknode ("", $1, NULL, $3); } | consts ;

              /*_________________________________________________________________________________________________________*/
derefID:    DEREFERENCE id  {char* t = $2->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); $$ = mknode (s,NULL, NULL, NULL); } ;

newline:    decs newline   {$$ = mknode ("", $1, NULL,$2); }
          | statements
          | decs;
           
decs:       variable_declare_statements SEMICOLON;
            
            /*_________________________________________________________STATEMENTS___________________________________________________*/
statements: statement statements {$$ = mknode ("STATEMENT", $1, NULL,$2); }
          | statement;

statement:  IF_statements 
          | LOOP_statements  
          | proc
          | procCall SEMICOLON
          | ASSIGNMENT_statement SEMICOLON;
        

statements_type:
            statement
          | block_statements;
                    
IF_statements:
            IF cond statements_type {$$ = mknode ("(IF", $2,$3,mknode(")", NULL, NULL, NULL)); } %prec LOWER_THAN_ELSE
          | IF cond statements_type ELSE statements_type {$$ = mknode ("(IF-ELSE", $2,$3, mknode("", $5, NULL, mknode(")", NULL, NULL, NULL))); };

            /*_______________________________________LOOP STATEMENTS___________________________________*/
LOOP_statements:
            while
          | for;

while:      WHILE cond statements_type {$$=mknode("(WHILE", $2, $3, mknode(")", NULL, NULL, NULL));} ;
//note: for right paren is its right child
for:        FOR LEFTPAREN preCondition SEMICOLON postCondition SEMICOLON iteration RIGHTPAREN statements_type {$$=mknode("(FOR", $3,mknode(";",$5,mknode(";",$7,$9,NULL),NULL),mknode(")",NULL,NULL,NULL));};

preCondition:
          | expr
          | ASSIGNMENT_statement;
postCondition:
          | expr;
iteration:
          | ASSIGNMENT_statement;
cond:       LEFTPAREN expr RIGHTPAREN {$$ = mknode ("(COND", $2, NULL, mknode(")", NULL, NULL, NULL)); };


            /*________________________________ASSIGNMENT STATEMENTS____________________________________*/
ASSIGNMENT_statement:
            id ASSIGNMENT expr  {$$ = mknode ("=", $1, NULL, $3); } 
          | derefID ASSIGNMENT expr  {$$ = mknode ("=", $1, NULL, $3); } ;

str_ASSIGNMENT_statement:
            id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT strings  {$$ = mknode ("=", $1, NULL, $6); };

                            
                              

varType:    BOOL {$$ = mknode ("BOOL", NULL, NULL, NULL); }
          | CHAR {$$ = mknode ("CHAR", NULL, NULL, NULL); }
          | INT {$$ = mknode ("INT", NULL, NULL, NULL); }
          | INTPTR {$$ = mknode ("INTPTR", NULL, NULL, NULL); }
          | CHARPTR {$$ = mknode ("CHARPTR", NULL, NULL, NULL); };

            /*____________________________________DECLARATIONS_______________________________________*/
            
StringDeclare:
            id LEFTBRACKET numbers RIGHTBRACKET COMMA StringDeclare {$$ = mknode ("STRING", $1, NULL, $6); }
          | str_ASSIGNMENT_statement {$$ = mknode ("STRING", $1, NULL,NULL); }
          | str_ASSIGNMENT_statement COMMA StringDeclare {$$ = mknode ("STRING", $1,$3, NULL); }
          | id LEFTBRACKET numbers RIGHTBRACKET {$$ = mknode ("STRING", $1,NULL, NULL); };
                          

variable_declare_statements:
            VAR id COMMA variable_declare_statements    {$$ = mknode ("", $2, NULL, $4); }
          | VAR id COLON varType {$$ = mknode ("", $2, NULL, $4); }
          | STRING StringDeclare {$$ = mknode ("VAR", $2, NULL, NULL); };
  
%%
#include "lex.yy.c"
int main(){
    return yyparse();
}

node *mknode    (char *token, node *left, node* middle, node *right){
    node *newnode = (node*)malloc (sizeof(node));
    char    *newstr = (char*)malloc (sizeof(token)+1);
    strcpy (newstr, token);
    newnode -> left = left;
    newnode -> right = right;
    newnode -> middle = middle;
    newnode -> token = newstr;
    return newnode;
}

void printtree (node *tree, int tab){
    int i; 
    for (i = 0; i< tab; i++)
        printf ("\t");
    char* token = tree->token;
        printf (" %s \n", token);
    if (tree -> left)
        printtree (tree-> left, tab + 1);
    if (tree -> middle)
        printtree (tree-> middle, tab + 1);     
    if (tree -> right)
        printtree (tree-> right, tab + 1); 
}
int yyerror(char* s){
    printf ("%s: at line %d found token [%s]\n",  s,counter, yytext);
    return 0;
}