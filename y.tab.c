/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"

typedef enum {false,true} bool;
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;


	typedef struct Varaiables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * length;
	}Varaiable;

    typedef struct Function 
	{
        char * name;
		struct Varaiables * arguments;
        char *returnType; 
		int argNum;
		bool findreturn;
    } Function;

		typedef struct SCOPE
	{	
		char *name;
		Varaiable * var;
		int VarCount;
		int Fcount;
		Function ** func;
		struct SCOPE * nextScope;
		struct SCOPE * preScope;
	}SCOPE;
	//part 1
	int yylex();
	int yyerror(char *e);
	
	//part 2
	static int scope=0;
	SCOPE* mkScope(char *);
	SCOPE* finScope(SCOPE * scopes);
	SCOPE* globalScope=NULL;
	void addFunc(char * name,Varaiable * arguments,node *returnType,int argNum,SCOPE*);
	void addVar(Varaiable * arguments,int,int,SCOPE * MYscope);
	void syntaxAnalyzer(node *tree,SCOPE * scope);
	void pushScopes(SCOPE* from,char*);
	char* getExpType(node *,SCOPE*);
	char* findFunc(node * tree,SCOPE * MYscope);
	char* findVar(node * tree,SCOPE * MYscope);
	node* mkNode(char* token, node *left, node *right);
	Varaiable* mkArguments(node *,int *);
	Varaiable* callFuncArguments(SCOPE *,node *tree,int * count);
	

#line 130 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMENT = 258,
    DO = 259,
    WHILE = 260,
    IF = 261,
    ELSE = 262,
    FOR = 263,
    RETURN = 264,
    BOOL = 265,
    STRING = 266,
    CHARPTR = 267,
    CHAR = 268,
    INT = 269,
    INTPTR = 270,
    PROCEDUR = 271,
    AND = 272,
    ADDRESS = 273,
    EQL = 274,
    ASSINGMENT = 275,
    OR = 276,
    LENGTH = 277,
    GREATEREQL = 278,
    GREATER = 279,
    LESSEQL = 280,
    LESS = 281,
    NOTEQL = 282,
    NOT = 283,
    DIVISION = 284,
    PLUS = 285,
    MINUS = 286,
    MULTI = 287,
    VARIABLE = 288,
    STRING_LTL = 289,
    REAL_LTL = 290,
    CHAR_LTL = 291,
    CSNULL = 292,
    MAIN = 293,
    IDENTIFIER = 294,
    SEMICOLON = 295,
    COMMA = 296,
    OPENPAREN = 297,
    CLOSEPAREN = 298,
    OPENBRACKET = 299,
    CLOSEBRACKET = 300,
    OPENBRACE = 301,
    CLOSEBRACE = 302,
    DECIMAL_LTL = 303,
    HEX_LTL = 304,
    BOOLTRUE = 305,
    BOOLFALSE = 306,
    REAL = 307,
    REALPTR = 308,
    FUNCTION = 309,
    COLON = 310,
    DEREFERENCE = 311,
    QUOTE = 312,
    DOUBLE_QUOTES = 313,
    BEGIN_COMMENT = 314,
    END_COMMENT = 315
  };
#endif
/* Tokens.  */
#define COMMENT 258
#define DO 259
#define WHILE 260
#define IF 261
#define ELSE 262
#define FOR 263
#define RETURN 264
#define BOOL 265
#define STRING 266
#define CHARPTR 267
#define CHAR 268
#define INT 269
#define INTPTR 270
#define PROCEDUR 271
#define AND 272
#define ADDRESS 273
#define EQL 274
#define ASSINGMENT 275
#define OR 276
#define LENGTH 277
#define GREATEREQL 278
#define GREATER 279
#define LESSEQL 280
#define LESS 281
#define NOTEQL 282
#define NOT 283
#define DIVISION 284
#define PLUS 285
#define MINUS 286
#define MULTI 287
#define VARIABLE 288
#define STRING_LTL 289
#define REAL_LTL 290
#define CHAR_LTL 291
#define CSNULL 292
#define MAIN 293
#define IDENTIFIER 294
#define SEMICOLON 295
#define COMMA 296
#define OPENPAREN 297
#define CLOSEPAREN 298
#define OPENBRACKET 299
#define CLOSEBRACKET 300
#define OPENBRACE 301
#define CLOSEBRACE 302
#define DECIMAL_LTL 303
#define HEX_LTL 304
#define BOOLTRUE 305
#define BOOLFALSE 306
#define REAL 307
#define REALPTR 308
#define FUNCTION 309
#define COLON 310
#define DEREFERENCE 311
#define QUOTE 312
#define DOUBLE_QUOTES 313
#define BEGIN_COMMENT 314
#define END_COMMENT 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 65 "parser.y" /* yacc.c:355  */

    struct node *node;
    char *string;

#line 295 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 312 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   578

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   104,   107,   107,   110,   116,   117,   120,
     125,   132,   133,   137,   138,   141,   148,   148,   151,   157,
     158,   162,   163,   164,   165,   166,   167,   168,   169,   174,
     175,   176,   177,   178,   179,   180,   181,   185,   185,   188,
     188,   188,   188,   191,   197,   203,   211,   217,   225,   226,
     227,   228,   234,   241,   245,   246,   247,   252,   254,   255,
     256,   257,   258,   259,   260,   261,   263,   264,   265,   266,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   285,   287,   288,   294,   295,   296,   298,   308,
     309,   310,   314,   315,   316,   318,   320
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "DO", "WHILE", "IF", "ELSE",
  "FOR", "RETURN", "BOOL", "STRING", "CHARPTR", "CHAR", "INT", "INTPTR",
  "PROCEDUR", "AND", "ADDRESS", "EQL", "ASSINGMENT", "OR", "LENGTH",
  "GREATEREQL", "GREATER", "LESSEQL", "LESS", "NOTEQL", "NOT", "DIVISION",
  "PLUS", "MINUS", "MULTI", "VARIABLE", "STRING_LTL", "REAL_LTL",
  "CHAR_LTL", "CSNULL", "MAIN", "IDENTIFIER", "SEMICOLON", "COMMA",
  "OPENPAREN", "CLOSEPAREN", "OPENBRACKET", "CLOSEBRACKET", "OPENBRACE",
  "CLOSEBRACE", "DECIMAL_LTL", "HEX_LTL", "BOOLTRUE", "BOOLFALSE", "REAL",
  "REALPTR", "FUNCTION", "COLON", "DEREFERENCE", "QUOTE", "DOUBLE_QUOTES",
  "BEGIN_COMMENT", "END_COMMENT", "$accept", "project", "program", "cmmnt",
  "main", "procedures", "procedure", "para_pro", "para_list", "pro_body",
  "declares", "declear", "var_id", "type_id", "type_pro", "stmnts",
  "stmnt_block", "new_block", "stmnt", "assmnt_stmnt", "lhs", "expr",
  "address_expr", "DEREFERENCE_expr", "expr_list", "paren_expr",
  "call_func", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    27,    36,  -133,  -133,  -133,  -133,     7,     9,    -5,
    -133,  -133,    38,    51,    54,    14,    56,    56,    27,    59,
      61,    57,    44,    64,    62,    56,    63,    27,    53,    27,
      27,  -133,    27,    56,  -133,    66,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,   102,  -133,    67,    78,  -133,    65,    71,
      15,  -133,  -133,    81,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,    82,    88,    96,  -133,    27,    56,  -133,   226,
      90,    83,    27,   100,    27,   251,   -25,   105,   251,  -133,
    -133,  -133,  -133,    50,   251,  -133,  -133,  -133,  -133,  -133,
     -23,  -133,  -133,   106,   128,   492,   131,   132,    27,  -133,
      53,   111,   251,   112,    -9,   510,  -133,  -133,   126,   117,
     149,  -133,   251,   251,  -133,   389,     8,   130,   251,    27,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,    27,  -133,    27,   251,   410,     3,   251,
      27,   251,    34,  -133,   473,   129,   287,  -133,  -133,   251,
     431,  -133,   546,    58,    58,    58,    58,    58,    58,    58,
      58,  -133,    -4,    -4,  -133,  -133,   135,   452,     4,   133,
     141,  -133,  -133,   304,  -133,   321,  -133,   251,   251,  -133,
     165,    96,   338,  -133,    27,     4,  -133,  -133,  -133,   180,
    -133,   251,   251,  -133,  -133,   355,  -133,   174,  -133,  -133,
    -133,     4,   372,   528,   145,    27,  -133,  -133,     3,  -133,
    -133,   146,     4,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     5,     0,     8,     4,     1,     2,     0,     0,     0,
       3,     7,     0,     0,     0,     0,    12,    12,     5,    20,
       0,    11,     0,     0,     0,     0,     0,     5,     0,     5,
       5,    19,     5,     0,    21,     0,    27,    23,    24,    26,
      25,    28,    13,     0,     8,     0,     0,    14,     0,     0,
      17,     6,    10,     0,    29,    30,    35,    31,    32,    34,
      33,    36,     0,     0,    38,    22,     5,     0,    16,    15,
       0,     0,     5,     0,     5,     0,     0,     0,     0,    78,
      77,    76,    84,    83,     0,     8,    74,    75,    80,    79,
       0,    51,    37,     0,     0,     0,    71,    72,     5,     9,
       0,     0,     0,     0,    83,     0,    71,    72,    85,     0,
       0,    70,    94,     0,    96,     0,     5,    89,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,    73,     5,     0,     0,     0,     0,
       5,     0,     0,    81,    93,     0,     0,    57,    17,     0,
       0,    48,    52,    64,    58,    65,    60,    61,    62,    63,
      59,    69,    66,    67,    68,    49,     0,     0,     0,    54,
       0,    55,    56,     0,    50,     0,    86,     0,    94,    95,
      82,    38,     0,    90,     5,     0,    42,    41,    40,    44,
      39,     0,     0,    82,    87,     0,    92,     0,    91,    18,
      46,     0,     0,     0,     0,     5,    45,    53,     0,    88,
      43,     0,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,     0,  -133,   -29,     1,   173,   158,    13,
      45,   -59,   -18,    94,  -133,    16,  -110,  -133,   -66,  -132,
    -133,    37,   -67,   -65,    17,  -133,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    44,    10,     7,   187,    20,    21,    45,
      64,   188,    22,    42,    62,    69,   189,    91,   190,    93,
      94,    95,   106,   107,   145,   114,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       3,     4,    96,    92,    97,    68,   170,    31,    11,    72,
      73,     1,    74,    75,   108,    50,   117,   109,    24,   118,
      63,    76,    76,     8,    63,   129,    77,    33,   132,    43,
       1,    63,    78,   112,    14,   139,     5,    67,    79,    80,
      81,    82,   169,    83,   186,    46,    84,    12,    13,    71,
      85,    11,    86,    87,    88,    89,   116,    18,     9,    90,
      90,     9,     9,    34,    35,    36,    37,    38,    39,     9,
     -54,   171,   101,   172,   103,   200,   211,   176,   177,    70,
      15,    54,    55,    56,    57,    58,    59,   129,   130,   131,
     132,   206,   112,    16,   113,    19,    17,    27,   134,    28,
      25,    96,   213,    97,    26,    40,    41,    29,    30,    32,
      48,    49,   105,    53,    51,   111,   148,    11,    96,   151,
      97,   115,    68,    60,    61,    52,    65,    13,    66,    67,
      96,    92,    97,   165,    96,   166,    97,    99,   100,   137,
     174,   171,   102,   172,   110,    96,   119,    97,   120,   144,
     146,   -55,   -56,   136,   138,   150,   142,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     141,   143,   179,   167,   149,   184,   173,   191,   175,    72,
      73,   192,    74,    75,   199,   -53,   182,   201,   209,   212,
      23,    47,    76,   181,   135,   196,    77,   197,     0,     0,
       0,     0,    78,     0,     0,   210,     0,     0,    79,    80,
      81,    82,     0,    83,   195,   144,    84,     0,     0,     0,
      85,   205,    86,    87,    88,    89,     0,     0,   202,   203,
      90,    72,    73,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,    77,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
      79,    80,    81,    82,     0,    83,     0,     0,    84,    76,
       0,     0,    85,    77,    86,    87,    88,    89,     0,    78,
       0,     0,    90,     0,     0,    79,    80,    81,    82,     0,
     104,     0,     0,    84,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,   121,     0,   122,    90,   123,     0,
     124,   125,   126,   127,   128,     0,   129,   130,   131,   132,
       0,   121,     0,   122,     0,   123,     0,   124,   125,   126,
     127,   128,   180,   129,   130,   131,   132,     0,   121,     0,
     122,     0,   123,     0,   124,   125,   126,   127,   128,   193,
     129,   130,   131,   132,     0,   121,     0,   122,     0,   123,
       0,   124,   125,   126,   127,   128,   194,   129,   130,   131,
     132,     0,   121,     0,   122,     0,   123,     0,   124,   125,
     126,   127,   128,   198,   129,   130,   131,   132,     0,   121,
       0,   122,     0,   123,     0,   124,   125,   126,   127,   128,
     204,   129,   130,   131,   132,     0,   121,     0,   122,     0,
     123,     0,   124,   125,   126,   127,   128,   207,   129,   130,
     131,   132,     0,     0,     0,     0,     0,   121,     0,   122,
       0,   123,   147,   124,   125,   126,   127,   128,     0,   129,
     130,   131,   132,     0,     0,     0,     0,     0,   121,     0,
     122,     0,   123,   168,   124,   125,   126,   127,   128,     0,
     129,   130,   131,   132,     0,     0,     0,     0,     0,   121,
       0,   122,     0,   123,   183,   124,   125,   126,   127,   128,
       0,   129,   130,   131,   132,     0,     0,     0,     0,     0,
     121,     0,   122,     0,   123,   185,   124,   125,   126,   127,
     128,     0,   129,   130,   131,   132,     0,     0,     0,   121,
       0,   122,     0,   123,   178,   124,   125,   126,   127,   128,
       0,   129,   130,   131,   132,     0,     0,   121,     0,   122,
       0,   123,   133,   124,   125,   126,   127,   128,     0,   129,
     130,   131,   132,     0,     0,   121,     0,   122,     0,   123,
     140,   124,   125,   126,   127,   128,     0,   129,   130,   131,
     132,     0,     0,   121,     0,   122,     0,   123,   208,   124,
     125,   126,   127,   128,     0,   129,   130,   131,   132
};

static const yytype_int16 yycheck[] =
{
       0,     1,    69,    69,    69,    64,   138,    25,     7,     5,
       6,     3,     8,     9,    39,    44,    39,    42,    18,    42,
      16,    18,    18,    16,    16,    29,    22,    27,    32,    29,
       3,    16,    28,    42,    39,    44,     0,    33,    34,    35,
      36,    37,    39,    39,    40,    32,    42,    38,    39,    67,
      46,    50,    48,    49,    50,    51,    85,    43,    54,    56,
      56,    54,    54,    10,    11,    12,    13,    14,    15,    54,
      20,   138,    72,   138,    74,   185,   208,    43,    44,    66,
      42,    10,    11,    12,    13,    14,    15,    29,    30,    31,
      32,   201,    42,    42,    44,    39,    42,    40,    98,    55,
      41,   168,   212,   168,    43,    52,    53,    43,    46,    46,
      44,     9,    75,    48,    47,    78,   116,   116,   185,   119,
     185,    84,   181,    52,    53,    47,    45,    39,    46,    33,
     197,   197,   197,   133,   201,   135,   201,    47,    55,   102,
     140,   208,    42,   208,    39,   212,    40,   212,    20,   112,
     113,    20,    20,    42,    42,   118,    39,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      44,    22,    43,   136,    44,    40,   139,    44,   141,     5,
       6,    40,     8,     9,   184,    20,   149,     7,    43,    43,
      17,    33,    18,   148,   100,   178,    22,   181,    -1,    -1,
      -1,    -1,    28,    -1,    -1,   205,    -1,    -1,    34,    35,
      36,    37,    -1,    39,   177,   178,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    -1,    -1,   191,   192,
      56,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    42,    18,
      -1,    -1,    46,    22,    48,    49,    50,    51,    -1,    28,
      -1,    -1,    56,    -1,    -1,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    -1,    17,    -1,    19,    56,    21,    -1,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      -1,    17,    -1,    19,    -1,    21,    -1,    23,    24,    25,
      26,    27,    45,    29,    30,    31,    32,    -1,    17,    -1,
      19,    -1,    21,    -1,    23,    24,    25,    26,    27,    45,
      29,    30,    31,    32,    -1,    17,    -1,    19,    -1,    21,
      -1,    23,    24,    25,    26,    27,    45,    29,    30,    31,
      32,    -1,    17,    -1,    19,    -1,    21,    -1,    23,    24,
      25,    26,    27,    45,    29,    30,    31,    32,    -1,    17,
      -1,    19,    -1,    21,    -1,    23,    24,    25,    26,    27,
      45,    29,    30,    31,    32,    -1,    17,    -1,    19,    -1,
      21,    -1,    23,    24,    25,    26,    27,    45,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    21,    43,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    21,    43,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    -1,    21,    43,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    -1,    21,    43,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    17,
      -1,    19,    -1,    21,    41,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    -1,    -1,    17,    -1,    19,
      -1,    21,    40,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    17,    -1,    19,    -1,    21,
      40,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    -1,    -1,    17,    -1,    19,    -1,    21,    40,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    62,    64,    64,     0,    63,    66,    16,    54,
      65,    67,    38,    39,    39,    42,    42,    42,    43,    39,
      68,    69,    73,    68,    64,    41,    43,    40,    55,    43,
      46,    73,    46,    64,    10,    11,    12,    13,    14,    15,
      52,    53,    74,    64,    64,    70,    70,    69,    44,     9,
      66,    47,    47,    48,    10,    11,    12,    13,    14,    15,
      52,    53,    75,    16,    71,    45,    46,    33,    72,    76,
      70,    73,     5,     6,     8,     9,    18,    22,    28,    34,
      35,    36,    37,    39,    42,    46,    48,    49,    50,    51,
      56,    78,    79,    80,    81,    82,    83,    84,    87,    47,
      55,    64,    42,    64,    39,    82,    83,    84,    39,    42,
      39,    82,    42,    44,    86,    82,    66,    39,    42,    40,
      20,    17,    19,    21,    23,    24,    25,    26,    27,    29,
      30,    31,    32,    40,    64,    74,    42,    82,    42,    44,
      40,    44,    39,    22,    82,    85,    82,    43,    64,    44,
      82,    64,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    64,    64,    82,    43,    39,
      80,    83,    84,    82,    64,    82,    43,    44,    41,    43,
      45,    71,    82,    43,    40,    43,    40,    67,    72,    77,
      79,    44,    40,    45,    45,    82,    85,    76,    45,    64,
      77,     7,    82,    82,    45,    47,    77,    45,    40,    43,
      64,    80,    43,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    64,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    71,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    77,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    84,
      84,    84,    85,    85,    85,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     8,     2,     0,    11,
       8,     1,     0,     3,     4,     4,     2,     0,     7,     3,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     1,     1,     7,     5,     7,     6,    10,     3,     3,
       4,     1,     3,     4,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     1,     1,     2,     4,     5,     7,     2,
       4,     5,     3,     1,     0,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 102 "parser.y" /* yacc.c:1646  */
    { syntaxAnalyzer((yyvsp[0].node),globalScope); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("CODE",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 107 "parser.y" /* yacc.c:1646  */
    {;}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 111 "parser.y" /* yacc.c:1646  */
    {
(yyval.node)=mkNode("Main",mkNode("ARGS",NULL,(yyvsp[-1].node)),NULL);
}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 121 "parser.y" /* yacc.c:1646  */
    { 
		(yyval.node)=mkNode("FUNC",mkNode((yyvsp[-9].string),mkNode(" ",NULL,NULL),mkNode("ARGS",(yyvsp[-7].node),mkNode("Return",(yyvsp[-3].node),NULL))),mkNode("",(yyvsp[-1].node),NULL));

}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("PROC",mkNode((yyvsp[-6].string),mkNode("",NULL,NULL),NULL),mkNode("ARGS",(yyvsp[-4].node),(yyvsp[-1].node)));
}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("(",(yyvsp[0].node),mkNode("",(yyvsp[-2].node),mkNode(")",NULL,NULL)));}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",(yyvsp[-3].node),mkNode("",(yyvsp[0].node),NULL));}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("BODY", mkNode(" ",(yyvsp[-2].node),NULL),mkNode(" ",(yyvsp[-1].node),mkNode(" ",(yyvsp[0].node),mkNode(" ",NULL,NULL))));
}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 152 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("var", (yyvsp[-3].node),(yyvsp[-5].node));
}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[-2].string), mkNode(" ", (yyvsp[0].node), NULL),NULL);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string), NULL, NULL);}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("boolean", NULL, NULL);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("string", mkNode("[",mkNode("$3",NULL,NULL),NULL), NULL);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("char", NULL, NULL);}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("int", NULL, NULL);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("real", NULL, NULL);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("int*", NULL, NULL);}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("char*", NULL, NULL);}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("real*", NULL, NULL);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("boolean", NULL, NULL);}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("string", NULL, NULL);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("char", NULL, NULL);}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("int", NULL, NULL);}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("real", NULL, NULL);}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("int*", NULL, NULL);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("char*", NULL, NULL);}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("real*", NULL, NULL);}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",NULL,NULL);}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 192 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("{",(yyvsp[-5].node),mkNode("", (yyvsp[-3].node),mkNode("", (yyvsp[-2].node),("}",NULL,NULL))));
}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("if",
	mkNode("(", (yyvsp[-2].node), 
	mkNode(")",NULL,NULL)),(yyvsp[0].node));
}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 204 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("if-else",
	mkNode("", (yyvsp[-4].node), 
	mkNode("",NULL,NULL)),
	mkNode("",(yyvsp[-2].node),
	mkNode("",(yyvsp[0].node),NULL)));
}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 212 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("while",
	mkNode("(", (yyvsp[-2].node), 
	mkNode(")",NULL,NULL)),(yyvsp[0].node));
}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node)= mkNode("for",
			mkNode("(",
			mkNode("",(yyvsp[-6].node),(yyvsp[-4].node)),
			mkNode("",(yyvsp[-2].node),
			mkNode(")",NULL,NULL))),(yyvsp[0].node));		
}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",(yyvsp[-2].node),NULL);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 226 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-2].node);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("return",(yyvsp[-2].node),NULL);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 235 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode("=",(yyvsp[-2].node),(yyvsp[0].node));
}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 242 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node)=mkNode((yyvsp[-3].string), mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)), NULL);
}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),NULL,NULL);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("(",(yyvsp[-1].node),mkNode(")",NULL,NULL));}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("==",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 255 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("!=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode(">=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode(">",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 258 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("<=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("<",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("&&",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("||",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 268 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("!",(yyvsp[0].node),NULL);}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 272 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),mkNode("INT",NULL,NULL),NULL);}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),mkNode("HEX", NULL, NULL),NULL);}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),mkNode("CHAR", NULL, NULL),NULL);}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),mkNode("REAL", NULL, NULL),NULL);}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),mkNode("STRING", NULL, NULL),NULL);}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),mkNode("BOOLEAN", NULL, NULL),NULL);}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[0].string),mkNode("BOOLEAN", NULL, NULL),NULL);}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node)=mkNode("|",
		mkNode((yyvsp[-1].string),NULL,NULL),
		mkNode("|",NULL,NULL));
	}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("solovar",mkNode((yyvsp[-3].string),mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)),NULL),NULL);}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("solovar",mkNode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("null",NULL,NULL);}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("&",mkNode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("&",mkNode("(",mkNode((yyvsp[-1].string),NULL,NULL),NULL),mkNode(")",NULL,NULL));}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("&", mkNode((yyvsp[-3].string),mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)),NULL),NULL);}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 299 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node)=mkNode("&",
		mkNode("(", 
		mkNode((yyvsp[-4].string),mkNode("[",(yyvsp[-2].node),mkNode("]",NULL,NULL)),NULL)
		,mkNode(")",NULL,NULL)),NULL);
	}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("^",mkNode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("^",mkNode("(",(yyvsp[-1].node),NULL),mkNode(")",NULL,NULL));}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode((yyvsp[-4].string), mkNode((yyvsp[-3].string),mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)),NULL), NULL);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",(yyvsp[-2].node),mkNode(",",(yyvsp[0].node),NULL));}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("",(yyvsp[0].node),NULL);}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 316 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=mkNode("Call func",mkNode((yyvsp[-1].string),NULL,NULL),mkNode("ARGS",(yyvsp[0].node),NULL));}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2218 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 321 "parser.y" /* yacc.c:1906  */




int main()
{
	int res = yyparse();
	if(res==0)
	{
	printf("syntax valid\n"); 
	printf("Semantics valid\n");
	}
	return res;	
}

void addVar(Varaiable * arguments,int countvars,int isArg,SCOPE * MYscope){
	if(countvars==0)
	return;
	Varaiable* tmp;
	SCOPE * scopes=MYscope;

	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("There is the same var %s in one declare",arguments[i].name);
		SCOPE * t=scopes->preScope;
		while(t->preScope!=NULL && t->preScope->Fcount==0)
			t=t->preScope;
		if(t->func!=NULL)
		printf(",in function %s\n",t->func[t->Fcount-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(scopes->var==NULL)
	{ 
		scopes->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	}
	else
	{
		tmp=scopes->var;
		scopes->var=(Varaiable*) malloc(sizeof(Varaiable)*(scopes->VarCount+countvars));
		for(int i=0;i<scopes->VarCount;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(tmp[i].name,arguments[j].name)==0 )
				{
					printf("There can't be the same var %s in same scope",tmp[i].name);
					SCOPE * t=scopes->preScope;
					while(t->preScope!=NULL && t->preScope->Fcount==0)
						t=t->preScope;
					if(t->func!=NULL)
					printf(",in function %s\n",t->func[t->Fcount-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			scopes->var[i]=tmp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{

		scopes->var[scopes->VarCount].name=arguments[j].name;
		scopes->var[scopes->VarCount].value=NULL;
		scopes->var[scopes->VarCount].isArg=isArg;
		scopes->var[scopes->VarCount].length=arguments[j].length;
		scopes->var[(scopes->VarCount)++].type=arguments[j].type;
	}

}


char * getExpType(node * tree,SCOPE* MYscope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"HEX")==0)
			msg= "hex";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"BOOLEAN")==0)
			msg= "boolean";
		if(strcmp(tree->token,"!")==0)
		if(strcmp(getExpType(tree->left,MYscope),"boolean")==0)
			msg="boolean";
		else{
			printf("ERROR, you can use operator ! only on boolean type");
			exit(1);
		}
		if(strcmp(tree->token,"|")==0)
		if(strcmp(getExpType(tree->left,MYscope),"string")==0)
		msg="int";
		else{
			printf("ERROR, you can use operator | only on string type in function/proc %s",globalScope->func[globalScope->Fcount-1]->name);
			exit(1);
		}
		if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0)
		{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->right,MYscope),"string")!=0)
			msg="boolean";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in function/proc %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			msg="boolean";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in function/proc %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0)
		{

			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->right,MYscope),"boolean")==0)
			msg="boolean";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in function/proc %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
			

		}
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->left,MYscope),"int")==0)
			msg="int";
			else
			msg="real";
			}

			if(strcmp(getExpType(tree->right,MYscope),"int")==0&&(strcmp(getExpType(tree->left,MYscope),"char*")==0||strcmp(getExpType(tree->right,MYscope),"int*")==0||strcmp(getExpType(tree->right,MYscope),"real*")==0)){
				msg=getExpType(tree->left,MYscope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("ERROR, you can't use operator %s between %s and %s in function/proc %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}

		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->left,MYscope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			else
			{
				printf("ERROR, you can't use operator %s between %s and %s in function/proc %s\n\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=getExpType(tree->left->left,MYscope);
			else{
				msg=getExpType(tree->left,MYscope);
				
				}
			if(strcmp(msg,"char")==0)
			msg="char*";
			else
			if(strcmp(msg,"int")==0)
			msg="int*";
			else
			if(strcmp(msg,"real")==0)
			msg="real*";
			else
			{
				printf("ERROR, you can't use %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=getExpType(tree->left->left,MYscope);
			else
				msg=getExpType(tree->left,MYscope);
			
			if(strcmp(msg,"char*")==0)
			msg="char";
			else
			if(strcmp(msg,"int*")==0)
			msg="int";
			else
			if(strcmp(msg,"real*")==0)
			msg="real";
			else
			{
				printf("ERROR, you can't use %s on %s \n",tree->token,msg);
				exit(1);
			}

		}
		if(strcmp(tree->token,"(")==0)
			msg=getExpType(tree->left,MYscope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findFunc(tree,MYscope);
		
	}
	if(strcmp(msg,"")==0)
		msg=findVar(tree,MYscope);

	
	

	return msg;
}

SCOPE* mkScope(char* name)
{	
	SCOPE *newScope = (SCOPE*)malloc(sizeof(SCOPE));
	newScope->name=name;
	newScope->var=NULL;
	newScope->VarCount=0;
	newScope->func=NULL;
	newScope->Fcount=0;
	newScope->nextScope=NULL;
	newScope->preScope=NULL;
	return newScope;
}


void addFunc(char * name,Varaiable * arguments,node *returnType,int argNum,SCOPE * MYscope){
	Function** tmp;
	SCOPE * scopes = MYscope;
	for(int i=0;i<argNum;i++)
		for(int j=0;j<argNum;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("ERROR, there are identicles arguments %s in function %s\n",arguments[i].name,name);
		exit(1);
	}
	if(scopes->func==NULL)
	{ 
		scopes->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		tmp=scopes->func;
		scopes->func=(Function**) malloc(sizeof(Function*)*(scopes->Fcount+1));
		for(int i=0;i<scopes->Fcount;i++)
		{
				if(strcmp(tmp[i]->name,name)==0 )
				{
					printf("ERROR, there's already function %s in same scope \n",tmp[i]->name);
					exit(1);
				}
				scopes->func[i]=tmp[i];
		}
	}
		scopes->func[scopes->Fcount]=(Function*) malloc(sizeof(Function));
		scopes->func[scopes->Fcount]->name=name;
		scopes->func[scopes->Fcount]->arguments=arguments;
		if(returnType==NULL)
		scopes->func[scopes->Fcount]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type function %s can't be string\n",name);
				exit(1);
			}
		scopes->func[scopes->Fcount]->returnType=returnType->token;
		}
		scopes->func[scopes->Fcount]->argNum=argNum;
		scopes->func[scopes->Fcount]->findreturn=false;
		++(scopes->Fcount); 

}


/* allocation for node*/
node* mkNode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

int yyerror(char *e)
{
	int yydebug=1;
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "Does not accept '%s'\n",yytext);
	
	return 0;
}

SCOPE* finScope(SCOPE * scopes)
{
	SCOPE * MYscope=scopes;
	if(MYscope!=NULL)
	while(MYscope->nextScope!=NULL)
		MYscope=MYscope->nextScope;
	return MYscope;
}


void syntaxAnalyzer(node *tree,SCOPE * MYscope){

	if(strcmp(tree->token, "=") == 0 )
	{
		if(!(strcmp(getExpType(tree->right,MYscope),"NULL")==0&& (strcmp(getExpType(tree->left,MYscope),"real*")==0||strcmp(getExpType(tree->left,MYscope),"int*")==0||strcmp(getExpType(tree->left,MYscope),"char*")==0)))
		if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))!=0)
		{
			printf("ERORR, you can't  = between %s and %s in scope %s in function/proc %s\n",getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int VarCount=0;
		Varaiable * var=mkArguments(tree,&VarCount);
		addVar(var,VarCount,0,MYscope);
		
		
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"boolean")!=0)
		{
			printf("ERROR, the condition in if has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"boolean")!=0)
		{
			printf("ERROR, the condition in while has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{

	 if(strcmp(getExpType(tree->left->left->right,MYscope),"boolean")!=0)
		{
			printf("ERROR, the condition in for has to be boolean\n");
			exit(1);
		}

		syntaxAnalyzer(tree->left->left->left,MYscope);

		syntaxAnalyzer(tree->left->right->left,MYscope);

		if(strcmp(tree->right->token,"{")!=0)
		{

			pushScopes(MYscope,tree->token);

			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}

		
		
	}
	else if(strcmp(tree->token, "FUNC") == 0 )
	{
        int count=0;
		Varaiable * arg=mkArguments(tree->left->right->left,&count);
		addFunc(tree->left->token,arg,tree->left->right->right->left,count,MYscope);
		pushScopes(MYscope,tree->token);
		addVar(arg,count,1,finScope(MYscope));
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
		if(MYscope->func[MYscope->Fcount-1]->findreturn==false)
		{
			printf("ERORR, there is no return in function %s\n",tree->left->token);
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{
		
        int count=0;
		Varaiable * arg=mkArguments(tree->right->left,&count);
		addFunc(tree->left->token,arg,NULL,count,MYscope);
		pushScopes(MYscope,tree->token);
		addVar(arg,count,1,finScope(MYscope));
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
		scope--;	
		return;
    }

	else if(strcmp(tree->token, "Call func") == 0)
	{
		findFunc(tree,MYscope);
		//printf("(%s \n",tree->token);
		
		
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{
		pushScopes(NULL,tree->token);
	if (tree->left) 
		syntaxAnalyzer(tree->left,globalScope);
	
	if (tree->right)
		syntaxAnalyzer(tree->right,globalScope);
		scope--;
		return;
	}

    else if(strcmp(tree->token, "Main") == 0)
	{
		addFunc(tree->token,NULL,NULL,0,MYscope);
		pushScopes(MYscope,tree->token);

	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        scope--;
		return;
               
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"boolean")!=0)
		{
			printf("ERORR, if condition must be of type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->left->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			syntaxAnalyzer(tree->right->left,finScope( MYscope->nextScope));
			scope--;
			pushScopes(MYscope,tree->token);
			syntaxAnalyzer(tree->right->right->left,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
	}

	else if(strcmp(tree->token, "return") == 0)
	{
		SCOPE * tmp= MYscope;
		int flag=true;
		while(strcmp(tmp->name,"FUNC")!=0&&strcmp(tmp->name,"PROC")!=0&&strcmp(tmp->name,"CODE")!=0)
		{
			tmp=tmp->preScope;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType))
			{
			printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
			printf("%s ,%s %s\n",getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType,tmp->preScope->func[tmp->preScope->Fcount-1]->name);
			exit(1);
			}
		}
		else
		{
			if(tmp->preScope->func[tmp->preScope->Fcount-1]->returnType!=NULL)
			{
				if(0==strcmp(getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType))
				{
					tmp->preScope->func[tmp->preScope->Fcount-1]->findreturn=true;
				}
				else
				{
					printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
					printf("%s ,%s %s\n",getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType,tmp->preScope->func[tmp->preScope->Fcount-1]->name);
					exit(1);
				}
			}
			else
			{
				printf("ERORR, there can't be return in procedure %s\n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
				exit(1);
			}  
		}  
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    pushScopes(MYscope,tree->token);
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        scope--;
		return;			
	}
	else if(strcmp(tree->token, "solovar") == 0 )
	{
		findVar(tree->left,MYscope);
	}
	if (tree->left) 
		syntaxAnalyzer(tree->left,MYscope);
	
	if (tree->right)
		syntaxAnalyzer(tree->right,MYscope);
}


void pushScopes(SCOPE* from,char* name)
{
	SCOPE * point;
	if(globalScope==NULL)
		globalScope=mkScope(name);
	else{
	point=globalScope;
	while(point->nextScope!=NULL)
		point=point->nextScope;
	point->nextScope=mkScope(name);
	point->nextScope->preScope=from;
	}
}

char* findFunc(node * tree,SCOPE * MYscope)
{
	SCOPE* tmp=MYscope;
	Varaiable* arguments;
	bool find = false, flag = true;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->Fcount;i++)
		if(strcmp(tree->left->token,tmp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			arguments=callFuncArguments(MYscope,tree->right->left,&count);
			if(count==tmp->func[i]->argNum)
			{
				for(int j=0,t=count-1;j<count;j++,t--)
				{
					if(strcmp(arguments[j].type,tmp->func[i]->arguments[t].type)!=0)
						flag=false;
				}
				if(flag==true)
					return tmp->func[i]->returnType;
			}
		}
		tmp=tmp->preScope;
	}
	printf("ERROR,func %s not find call in scope %s in function/procedure %s\n",tree->left->token,MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
	if(find==true)
		printf("There is a function with the same name that accepts different arguments\n");
		exit(1);
}

char *findVar(node * tree,SCOPE * MYscope)
{
	SCOPE* tmp = MYscope;
	if(strcmp(tree->token,"solovar")==0)
		tree=tree->left;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->VarCount;i++)
		if(strcmp(tree->token,tmp->var[i].name)==0)
		{
			
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(tmp->var[i].type,"string")==0)
					if(strcmp(getExpType(tree->left->left,MYscope),"int")==0)
					{
						return "char";
					}
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in function/procedure %s\n",MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) in scope %s in function/procedure %s\n",MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
					exit(1);
				}

			}
			else
			return tmp->var[i].type;

		}
		tmp=tmp->preScope;
	}
	printf("ERORR, var %s wasn't found in scope %s in function/procedure %s\n ",tree->token,MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
	exit(1);	
}

Varaiable * mkArguments(node *tree,int *count){
	Varaiable  *arr=NULL,arr2[50];
	char* type,*length;
	if(tree!=NULL)
	{
		node * temp1=tree,*tmp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			tmp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
			{
				type=tmp->left->token;
				if(tmp->left->left!=NULL)
					length=tmp->left->left->left->token;
				node * tmptree;
				tmptree=tmp->right->left;
				do{
				arr2[*count].name=tmptree->token;
				arr2[*count].type=type;
				arr2[*count].length=length;
				(*count)++;
				if(tmptree->left==NULL)
					tmptree=NULL;
				else
					tmptree=tmptree->left->left;
				}while(tmptree!=NULL);
			}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(tmp->token, "var")!=0);
		tmp=temp1;
		if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
		{
			type=tmp->left->token;
			node * tmptree;
			if(strcmp(tmp->token, "var")==0)
			tmptree=tmp->right;
			else
			tmptree=tmp->right->left;
			if(tmp->left->left!=NULL)
			length=tmp->left->left->left->token;
			do{
			arr2[*count].name=tmptree->token;
			arr2[*count].type=type;
			arr2[*count].length=length;
			(*count)++;
			if(tmptree->left==NULL)
				tmptree=NULL;
			else
				tmptree=tmptree->left->left;
			}while(tmptree!=NULL);
		}
		arr=(Varaiable*)malloc(sizeof(Varaiable)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=arr2[i].name;
			arr[i].type=arr2[i].type;
		}
	}
	return arr;
}


Varaiable* callFuncArguments(SCOPE * MYscope,node *tree,int * count)
{
	Varaiable  *arr=NULL,arr2[50];
	char* type,*length;
	while(tree!=NULL)
	{
		arr2[(*count)++].type=getExpType(tree->left,MYscope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;

	}
	arr=(Varaiable*)malloc(sizeof(Varaiable)*(*count));
	for(int i = 0; i<*count; i++)
		arr[i].type=arr2[i].type;
	return arr;
}

