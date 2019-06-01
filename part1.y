%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *token;
    struct node *left;
    struct node *middle;
    struct node *right;
    char *token2;
} node;

node *mknode (char *token, node *left, node* middle, node *right, char *token2);
void printtree (node *tree, int tab);
#define YYSTYPE struct node *
%}
%token BOOL, CHAR, INT, STRING, INTPTR, CHARPTR, ID, VOID, QUOTES
%token IF, ELSE, WHILE, FOR, DO, VAR
%token MAIN, RETURN, PROC, FUNC
%token BOOLTRUE, BOOLFALSE, CSNULL, INTEGER_POS, INTEGER_NEG, CHAR, STRING, HEX, REAL
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
code:       procs { $$ = mknode("(CODE", $1,NULL,NULL, ")"); } ;
procs:      routine { $$ = mknode("", $1,NULL,NULL, ""); } | routine procs { $$ = mknode("", $1,$2,NULL, ""); } ;
       
routine: proc | func ;
       /*________________________________________________PROCEDURES________________________________________________*/
// procedures: proc {$$ = mknode ("", $1, NULL, NULL, ""); }
//           | proc procedures {$$ = mknode ("", $1, $2, NULL, ""); };

proc:       procReg | procMain ;

procReg:    PROC id LEFTPAREN params RIGHTPAREN voidBlock {$$ = mknode ("(PROC", $2, mknode ("", $4, $6, NULL, ""), NULL, ")"); } ;

procMain:   PROC MAIN LEFTPAREN RIGHTPAREN voidBlock {$$ = mknode ("(PROC MAIN", NULL, NULL, mknode ("", $5, NULL, NULL, ""), ")"); };

func:       FUNC id LEFTPAREN params RIGHTPAREN RETURN varType valueBlock 
{$$ = mknode ("(FUNC", $2, mknode ("", $4, mknode("(RET", $7, NULL, NULL, ")"), $8, ""), NULL, ")"); } ;

//procID:     varType id {$$ = mknode (yytext, $1, $2, NULL, ""); } ;


      /*________________________________________________PARAMS DECLARE______________________________________________*/
params:     {$$ = mknode ("(ARGS NONE)", NULL, NULL, NULL, ""); }
          | parDec {$$ = mknode ("(ARGS", $1, NULL, NULL, ")"); };
parDec:     param SEMICOLON parDec {$$ = mknode ("", $1, NULL, $3, ""); }   
          | param {$$ = mknode ("", $1, NULL,NULL, ""); } ;
/* to change tree design\print, toggle between following: 1) [type id] 2) [][type][id] */
/*param: varType id {char *s = " "; s=  strcat ($1->token,s);  $$ = mknode (strcat($1->token,$2->token), NULL, NULL, NULL); }   ;*/
param:      id COMMA param    {$$ = mknode ("(VAR", $1, $3, NULL, ")"); }
          | id COLON varType {$$ = mknode ("", $1, $3, NULL, ""); };
  
       /*______________________________________________EXPR____________________________________________________________*/
expr:       expr PLUS expr    {$$ = mknode ("(+", $1, $3, NULL, ")"); }
          | expr MINUS expr {$$ = mknode ("(-", $1, $3, NULL, ")"); }
          | expr MULTI expr {$$ = mknode ("(*", $1, $3, NULL, ")"); }
          | expr DIVISION expr  {$$ = mknode ("(/", $1, $3, NULL, ")"); }
          | expr EQUAL expr  { $$ = mknode ("(==", $1, $3, NULL, ")"); }
          | expr GREATER expr  { $$ = mknode ("(>", $1, $3, NULL, ")"); }
          | expr GREATEREQUAL expr { $$ = mknode ("(>=", $1, $3, NULL, ")"); }
          | expr LESS expr { $$ = mknode ("(<", $1, $3, NULL, ")"); }
          | expr LESSEQUAL expr { $$ = mknode ("(<=", $1, $3, NULL, ")"); }
          | expr NOTEQUAL expr { $$ = mknode ("(!=", $1, $3, NULL, ")"); }
          | expr AND expr {$$ = mknode ("(&&", $1, $3, NULL, ")"); }
          | expr OR expr {$$ = mknode ("(||", $1, $3, NULL, ")"); }
          | NOT expr {$$ = mknode ("(!", $2, NULL,NULL, ")"); }
          | ADDRESS id  {$$ = mknode ("(&", $2, NULL,NULL, ")" ); }
          | derefID 
          | Pexpr
          | consts ;

        
        /*______________________________________________________BLOCKS_____________________________________________________*/
Pexpr:      LEFTPAREN expr RIGHTPAREN { $$ = mknode ("(", $2, NULL, NULL, ")"); };
valueBlock: LEFTBRACE newline RETURN expr SEMICOLON RIGHTBRACE { $$ = mknode ("(BODY", $2, mknode ("(RET", $4, NULL, NULL, ")"), NULL, ")"); }
          | LEFTBRACE RETURN expr SEMICOLON RIGHTBRACE { $$ = mknode ("(BODY", mknode ("(RET", $3, NULL, NULL, ")"), NULL, NULL, ")"); };
            
voidBlock:  emptyBlock 
          | LEFTBRACE newline RIGHTBRACE {$$ = mknode ("(BODY", $2, NULL, NULL, ")"); };

block_statements:
            emptyBlock
          | LEFTBRACE newline RIGHTBRACE {$$ = mknode ("(BLOCK", $2, NULL, NULL, ")"); };

emptyBlock: LEFTBRACE RIGHTBRACE {$$ = mknode ("(BLOCK", $2, NULL, NULL, ")"); };

              /*_________________________________________________TYPES________________________________________________*/
consts:     id
          | numbers
          | booleans
          | csnull
          | strings
          | chars
          | procCall;

id:         ID {$$ = mknode (yytext, NULL, NULL, NULL, ""); }  ;

numbers:    INTEGER_POS { $$ = mknode (yytext, NULL, NULL, NULL, ""); }
          | INTEGER_NEG{ $$ = mknode (yytext, NULL, NULL, NULL, ""); }
          | HEX { $$ = mknode (yytext, NULL, NULL, NULL, ""); }
          | REAL { $$ = mknode (yytext, NULL, NULL, NULL, ""); };

csnull:     CSNULL  { $$ = mknode (yytext, NULL, NULL, NULL, ""); };

booleans:   BOOLTRUE { $$ = mknode (yytext, NULL, NULL, NULL, ""); }
          | BOOLFALSE { $$ = mknode (yytext, NULL, NULL, NULL, ""); };

strings:    STRING { $$ = mknode (yytext, NULL, NULL, NULL, ""); };

chars:      CHAR { $$ = mknode (yytext, NULL, NULL, NULL, ""); };

procCall:   id LEFTPAREN args RIGHTPAREN { $$ = mknode ("", $1, $3, NULL, ""); };

args:     | argsDec {$$ = mknode ("", $1, NULL, NULL, ""); };
argsDec:    consts COMMA argsDec  {$$ = mknode ("", $1, $3, NULL, ""); } | consts ;

              /*_________________________________________________________________________________________________________*/
derefID:    DEREFERENCE id  {char* t = $2->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); $$ = mknode (s,NULL, NULL, NULL, ""); } ;

newline:    decs newline   {$$ = mknode ("", $1, $2, NULL, ""); }
          | statements
          | decs;
           
decs:       variable_declare_statements SEMICOLON;
            
            /*_________________________________________________________STATEMENTS___________________________________________________*/
statements: statement statements {$$ = mknode ("", $1, $2,NULL, ""); }
          | statement;

statement:  IF_statements 
          | LOOP_statements  
          | proc
          | procCall SEMICOLON
          | ASSIGNMENT_statement SEMICOLON;
                    
IF_statements:
            IF cond block_statements {$$ = mknode ("(IF", $2,$3,NULL, ")"); } %prec LOWER_THAN_ELSE
          | IF cond block_statements ELSE block_statements {$$ = mknode ("(IF-ELSE", $2,$3, mknode("", $5, NULL, NULL, ""), ")"); };

            /*_______________________________________LOOP STATEMENTS___________________________________*/
LOOP_statements:
            while
          | for;

while:      WHILE cond block_statements {$$=mknode("(WHILE", $2, $3, NULL, ")");} ;
//note: for right paren is its right child
for:        FOR LEFTPAREN preCondition SEMICOLON postCondition SEMICOLON iteration RIGHTPAREN block_statements {$$=mknode("(FOR", $3, mknode(";",$5, mknode(";",$7,$9,NULL, ""),NULL, ""),NULL, ")");};

preCondition:
          | expr
          | ASSIGNMENT_statement;
postCondition:
          | expr;
iteration:
          | ASSIGNMENT_statement;
cond:       LEFTPAREN expr RIGHTPAREN {$$ = mknode ("(COND", $2, NULL, NULL, ")"); };


            /*________________________________ASSIGNMENT STATEMENTS____________________________________*/
ASSIGNMENT_statement:
            id ASSIGNMENT expr  {$$ = mknode ("(=", $1, $3, NULL, ")"); } 
          | derefID ASSIGNMENT expr  {$$ = mknode ("(=", $1, $3, NULL, ")"); } ;

str_ASSIGNMENT_statement:
            id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT strings  {$$ = mknode ("(=", $1, $6, NULL, ")"); };

                            
                              

varType:    BOOL {$$ = mknode ("BOOL", NULL, NULL, NULL, ""); }
          | CHAR {$$ = mknode ("CHAR", NULL, NULL, NULL, ""); }
          | INT {$$ = mknode ("INT", NULL, NULL, NULL, ""); }
          | INTPTR {$$ = mknode ("INTPTR", NULL, NULL, NULL, ""); }
          | CHARPTR {$$ = mknode ("CHARPTR", NULL, NULL, NULL, ""); };

            /*____________________________________DECLARATIONS_______________________________________*/
            
StringDeclare:
            id LEFTBRACKET numbers RIGHTBRACKET COMMA StringDeclare {$$ = mknode ("STRING", $1, $6, NULL, ""); }
          | str_ASSIGNMENT_statement {$$ = mknode ("STRING", $1, NULL,NULL, ""); }
          | str_ASSIGNMENT_statement COMMA StringDeclare {$$ = mknode ("STRING", $1,$3, NULL, ""); }
          | id LEFTBRACKET numbers RIGHTBRACKET {$$ = mknode ("STRING", $1,NULL, NULL, ""); };
                          

variable_declare_statements:
            VAR id COMMA variable_declare_statements    {$$ = mknode ("(VAR", $2, $4, NULL, ")"); }
          | id COLON varType {$$ = mknode ("", $1, $3, NULL, ""); }
          | id COMMA variable_declare_statements {$$ = mknode ("", $1, $3, NULL, ""); }
          | VAR id COLON varType {$$ = mknode ("(VAR", $2, $4, NULL, ")"); }
          | STRING StringDeclare {$$ = mknode ("(VAR", $2, NULL, NULL, ")"); };
  
%%
#include "lex.yy.c"
int main(){
    return yyparse();
}

node *mknode    (char *token, node *left, node* middle, node *right, char *token2){
    node *newnode = (node*)malloc (sizeof(node));
    char *newstr = (char*)malloc (sizeof(token)+1);
    char *newstr2 = (char*)malloc (sizeof(token2)+1);
    strcpy (newstr, token);
    strcpy (newstr2, token2);
    newnode -> left = left;
    newnode -> right = right;
    newnode -> middle = middle;
    newnode -> token = newstr;
    newnode -> token2 = newstr2;
    return newnode;
}

void printtree (node *tree, int tab){
    int i; 
    char* token = tree->token;
    char* token2 = tree->token2;
    
    for (i = 0; i< tab; i++)
        printf ("  ");
    printf ("%s\n", token);
    if (tree -> left)
        printtree (tree-> left, tab + 1);
    if (tree -> middle)
        printtree (tree-> middle, tab + 1);     
    if (tree -> right)
        printtree (tree-> right, tab + 1); 
    for (i = 0; i< tab; i++)
        printf ("  ");
    printf ("%s\n", token2);
}
int yyerror(char* s){
    printf ("%s: at line %d found token [%s]\n",  s,counter, yytext);
    return 0;
}