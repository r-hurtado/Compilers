/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "lang.y"

//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//
#include <iostream>
#include "lex.h"
#include "astnodes.h"


/* Line 371 of yacc.c  */
#line 85 "langparse.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "langparse.h".  */
#ifndef YY_YY_LANGPARSE_H_INCLUDED
# define YY_YY_LANGPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPE_ID = 259,
     CHAR_VAL = 260,
     INT_VAL = 261,
     FLOAT_VAL = 262,
     PRINT = 263,
     WHILE = 264,
     IF = 265,
     ELSE = 266,
     ENDIF = 267,
     STRUCT = 268,
     RETURN = 269,
     AND = 270,
     OR = 271,
     NEQUALS = 272,
     EQUALS = 273,
     JUNK_TOKEN = 274
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 21 "lang.y"

    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    cExprNode*      expr_node;
    cFuncDeclNode*  func_node;
    cFuncExprNode*  funccall_node;
    cSymbol*        symbol;
    cSymbolTable::symbolTable_t*  sym_table;
    cDeclsNode*     decls_node;
    cParamsNode*    params_node;
    cDeclNode*      decl_node;
    cVarExprNode*   varref_node;
    cParamListNode* paramlist_node;
    

/* Line 387 of yacc.c  */
#line 168 "langparse.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_LANGPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */
/* Line 390 of yacc.c  */
#line 41 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;

    static bool g_semanticErrorHappened = false;

#define CHECK_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; } }
#define PROP_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; YYERROR; } }

/* Line 390 of yacc.c  */
#line 222 "langparse.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      24,    23,    30,    28,    25,    29,    27,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,    21,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    10,    14,    16,    18,    21,    23,
      26,    29,    31,    34,    37,    41,    47,    50,    56,    61,
      65,    68,    72,    76,    78,    80,    83,    85,    93,   103,
     109,   115,   120,   125,   128,   130,   134,   137,   142,   146,
     150,   152,   154,   156,   160,   162,   164,   168,   170,   174,
     176,   180,   184,   186,   190,   194,   196,   200,   204,   208,
     210,   214,   216,   218
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    36,    38,    47,    37,    -1,
      36,    47,    37,    -1,    20,    -1,    21,    -1,    38,    39,
      -1,    39,    -1,    40,    22,    -1,    41,    22,    -1,    42,
      -1,     1,    22,    -1,     4,     3,    -1,    13,     3,     3,
      -1,    13,    36,    38,    37,     3,    -1,    43,    22,    -1,
      43,    20,    38,    47,    21,    -1,    43,    20,    47,    21,
      -1,    44,    45,    23,    -1,    44,    23,    -1,     4,     3,
      24,    -1,    45,    25,    46,    -1,    46,    -1,    40,    -1,
      47,    48,    -1,    48,    -1,    10,    24,    55,    23,    47,
      12,    22,    -1,    10,    24,    55,    23,    47,    11,    47,
      12,    22,    -1,     9,    24,    55,    23,    48,    -1,     8,
      24,    55,    23,    22,    -1,    52,    26,    55,    22,    -1,
      52,    26,    49,    22,    -1,    49,    22,    -1,    35,    -1,
      14,    55,    22,    -1,     1,    22,    -1,     3,    24,    53,
      23,    -1,     3,    24,    23,    -1,    50,    27,    51,    -1,
      51,    -1,     3,    -1,    50,    -1,    53,    25,    54,    -1,
      54,    -1,    55,    -1,    55,    16,    56,    -1,    56,    -1,
      56,    15,    57,    -1,    57,    -1,    57,    18,    58,    -1,
      57,    17,    58,    -1,    58,    -1,    58,    28,    59,    -1,
      58,    29,    59,    -1,    59,    -1,    59,    30,    60,    -1,
      59,    31,    60,    -1,    59,    32,    60,    -1,    60,    -1,
      24,    55,    23,    -1,     6,    -1,     7,    -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    99,    99,   106,   107,   109,   111,   113,   114,   115,
     116,   117,   118,   120,   124,   128,   130,   134,   140,   146,
     150,   151,   158,   160,   162,   164,   165,   167,   169,   171,
     173,   175,   179,   183,   184,   185,   186,   188,   192,   197,
     198,   200,   202,   204,   205,   207,   209,   210,   212,   213,
     215,   216,   217,   219,   220,   221,   223,   224,   225,   226,
     228,   229,   230,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPE_ID", "CHAR_VAL",
  "INT_VAL", "FLOAT_VAL", "PRINT", "WHILE", "IF", "ELSE", "ENDIF",
  "STRUCT", "RETURN", "AND", "OR", "NEQUALS", "EQUALS", "JUNK_TOKEN",
  "'{'", "'}'", "';'", "')'", "'('", "','", "'='", "'.'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "$accept", "program", "block", "open", "close",
  "decls", "decl", "var_decl", "struct_decl", "func_decl", "func_header",
  "func_prefix", "paramsspec", "paramspec", "stmts", "stmt", "func_call",
  "varref", "varpart", "lval", "paramlist", "param", "expr", "and",
  "equal", "add", "term", "fact", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     123,   125,    59,    41,    40,    44,    61,    46,    43,    45,
      42,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    37,    38,    38,    39,
      39,    39,    39,    40,    40,    41,    42,    42,    42,    43,
      43,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    49,    50,
      50,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     3,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     3,     5,     2,     5,     4,     3,
       2,     3,     3,     1,     1,     2,     1,     7,     9,     5,
       5,     4,     4,     2,     1,     3,     2,     4,     3,     3,
       1,     1,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,     0,     1,     0,    41,     0,     0,
       0,     0,     0,     0,    34,     0,     8,     0,     0,    11,
       0,     0,     0,    26,     0,    42,    40,     0,    12,     0,
      13,     0,     0,     0,     0,     0,    41,    61,    62,     0,
      63,     0,    47,    49,    52,    55,    59,     7,     0,     9,
      10,     0,    16,     0,     0,    20,    24,     0,    23,     0,
       6,     4,    25,    33,     0,     0,    38,     0,    44,    45,
      21,     0,     0,     0,    14,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,    13,    19,     0,    36,    39,     0,     0,    37,     0,
       0,     0,     0,    12,     0,    60,    46,    48,    51,    50,
      53,    54,    56,    57,    58,     0,    18,    22,    32,    31,
      43,    30,    29,     0,    15,    17,     0,     0,     0,    27,
       0,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    14,     4,    61,    15,    16,    17,    18,    19,
      20,    21,    57,    58,    22,    23,    24,    40,    26,    27,
      67,    68,    69,    42,    43,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
      -6,   -43,     8,   -43,   127,   -43,    -3,     9,    42,    72,
      78,    86,     7,    14,   -43,   127,   -43,    61,    91,   -43,
     101,     3,    40,   -43,   103,   102,   -43,   107,   125,     6,
     124,    14,    14,    14,   151,    54,   -43,   -43,   -43,    14,
     102,    30,   142,    48,    64,    69,   -43,   -43,    40,   -43,
     -43,   127,   -43,   156,   157,   -43,   -43,   109,   -43,   140,
     -43,   -43,   -43,   -43,   163,    29,   -43,   120,   -43,   152,
     -43,    -1,    46,    66,   -43,   149,    38,    71,    14,   -43,
      14,    14,    14,    14,    14,    14,    14,    14,   -43,   127,
      70,   -43,   -43,    59,   -43,   -43,   154,    52,   -43,    14,
     158,   169,   169,   -43,   170,   -43,   142,    48,    64,    64,
      69,    69,   -43,   -43,   -43,   106,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   141,   -43,   -43,   169,   159,   155,   -43,
     160,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   174,   172,   -42,     5,   -12,   -17,   -43,   -43,
     -43,   -43,   -43,    92,   -14,   -20,   121,    -4,   123,   -43,
     -43,    89,    -8,   112,   111,    36,    55,    19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int16 yytable[] =
{
      25,    48,    62,    47,    56,    41,    88,    53,     5,    36,
      34,    25,    37,    38,     1,    78,    54,    36,    25,    28,
      37,    38,   100,    71,    72,    73,    55,     1,    62,    66,
      39,    77,     7,    29,   104,    37,    38,    90,    39,    75,
      76,    59,     8,     7,    25,    30,    78,    25,     9,    10,
      11,    12,    79,    39,    13,    75,    89,    97,     8,    60,
       1,    60,    78,    53,    47,    81,    82,    12,    78,   101,
      62,    59,    54,     7,   119,   115,    56,    47,     9,    10,
      11,   122,    78,    49,    13,    25,    25,    78,   123,   102,
       1,   116,    83,    84,   105,    62,    31,    25,    25,    85,
      86,    87,    32,    62,   112,   113,   114,    59,    62,     7,
      33,    25,   128,    50,     9,    10,    11,   108,   109,    25,
      13,    51,    25,    52,    25,    63,     1,   125,     6,    64,
       7,     8,    92,    65,    93,     9,    10,    11,   110,   111,
      12,    13,    59,    98,     7,    99,   -36,     1,    70,     9,
      10,    11,   126,   127,    74,    13,    59,    80,     7,    91,
      34,     1,    94,     9,    10,    11,    36,   130,    78,    13,
      59,   103,     7,   124,     3,     1,   118,     9,    10,    11,
     121,   129,   131,    13,    35,   117,    96,    95,   120,     1,
     106,   107
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       4,    15,    22,    15,    21,    13,    48,     4,     0,     3,
       3,    15,     6,     7,    20,    16,    13,     3,    22,    22,
       6,     7,    23,    31,    32,    33,    23,    20,    48,    23,
      24,    39,     3,    24,    76,     6,     7,    51,    24,     1,
      35,     1,     4,     3,    48,     3,    16,    51,     8,     9,
      10,    13,    22,    24,    14,     1,    51,    65,     4,    21,
      20,    21,    16,     4,    76,    17,    18,    13,    16,    23,
      90,     1,    13,     3,    22,    89,    93,    89,     8,     9,
      10,   101,    16,    22,    14,    89,    90,    16,   102,    23,
      20,    21,    28,    29,    23,   115,    24,   101,   102,    30,
      31,    32,    24,   123,    85,    86,    87,     1,   128,     3,
      24,   115,   126,    22,     8,     9,    10,    81,    82,   123,
      14,    20,   126,    22,   128,    22,    20,    21,     1,    27,
       3,     4,    23,    26,    25,     8,     9,    10,    83,    84,
      13,    14,     1,    23,     3,    25,    21,    20,    24,     8,
       9,    10,    11,    12,     3,    14,     1,    15,     3,     3,
       3,    20,    22,     8,     9,    10,     3,    12,    16,    14,
       1,    22,     3,     3,     0,    20,    22,     8,     9,    10,
      22,    22,    22,    14,    12,    93,    65,    64,    99,    20,
      78,    80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    34,    35,    36,     0,     1,     3,     4,     8,
       9,    10,    13,    14,    35,    38,    39,    40,    41,    42,
      43,    44,    47,    48,    49,    50,    51,    52,    22,    24,
       3,    24,    24,    24,     3,    36,     3,     6,     7,    24,
      50,    55,    56,    57,    58,    59,    60,    39,    47,    22,
      22,    20,    22,     4,    13,    23,    40,    45,    46,     1,
      21,    37,    48,    22,    27,    26,    23,    53,    54,    55,
      24,    55,    55,    55,     3,     1,    38,    55,    16,    22,
      15,    17,    18,    28,    29,    30,    31,    32,    37,    38,
      47,     3,    23,    25,    22,    51,    49,    55,    23,    25,
      23,    23,    23,    22,    37,    23,    56,    57,    58,    58,
      59,    59,    60,    60,    60,    47,    21,    46,    22,    22,
      54,    22,    48,    47,     3,    21,    11,    12,    47,    22,
      12,    22
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 99 "lang.y"
    { (yyval.program_node) = new cProgramNode((yyvsp[(1) - (1)].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 106 "lang.y"
    { (yyval.block_node) = new cBlockNode((yyvsp[(2) - (4)].decls_node), (yyvsp[(3) - (4)].stmts_node)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 107 "lang.y"
    { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[(2) - (3)].stmts_node)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 109 "lang.y"
    { (yyval.sym_table) = g_SymbolTable.IncreaseScope(); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 111 "lang.y"
    { (yyval.sym_table) = g_SymbolTable.DecreaseScope(); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 113 "lang.y"
    { (yyval.decls_node) = (yyvsp[(1) - (2)].decls_node); (yyval.decls_node)->Insert((yyvsp[(2) - (2)].decl_node)); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 114 "lang.y"
    { (yyval.decls_node) = new cDeclsNode((yyvsp[(1) - (1)].decl_node)); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 115 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); CHECK_ERROR(); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 116 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 117 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (1)].func_node); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 118 "lang.y"
    {}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 120 "lang.y"
    { 
                                  (yyval.decl_node) = new cVarDeclNode((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol));
                                  CHECK_ERROR();
                                }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 124 "lang.y"
    { 
                                  (yyval.decl_node) = new cVarDeclNode((yyvsp[(2) - (3)].symbol), (yyvsp[(3) - (3)].symbol));
                                  CHECK_ERROR();
                                }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 129 "lang.y"
    { (yyval.decl_node) = new cStructDeclNode((yyvsp[(2) - (5)].sym_table), (yyvsp[(3) - (5)].decls_node), (yyvsp[(5) - (5)].symbol)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 131 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (2)].func_node);  
                                  g_SymbolTable.DecreaseScope();  
                                }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 135 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (5)].func_node); 
                                  (yyval.func_node)->AddDecls((yyvsp[(3) - (5)].decls_node)); 
                                  (yyval.func_node)->AddStmts((yyvsp[(4) - (5)].stmts_node)); 
                                  g_SymbolTable.DecreaseScope();  
                                }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 141 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (4)].func_node); 
                                  (yyval.func_node)->AddDecls(nullptr); 
                                  (yyval.func_node)->AddStmts((yyvsp[(3) - (4)].stmts_node)); 
                                  g_SymbolTable.DecreaseScope();  
                                }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 147 "lang.y"
    { 
                                  (yyval.func_node) = (yyvsp[(1) - (3)].func_node); (yyval.func_node)->AddParams((yyvsp[(2) - (3)].params_node)); 
                                }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 150 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (2)].func_node); (yyval.func_node)->AddParams(nullptr);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 152 "lang.y"
    { 
                                  (yyval.func_node) = new cFuncDeclNode((yyvsp[(1) - (3)].symbol), (yyvsp[(2) - (3)].symbol)); 
                                  g_SymbolTable.IncreaseScope();
                                  CHECK_ERROR();
                                }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 159 "lang.y"
    { (yyval.params_node) = (yyvsp[(1) - (3)].params_node); (yyval.params_node)->Insert((yyvsp[(3) - (3)].decl_node)); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 160 "lang.y"
    { (yyval.params_node) = new cParamsNode((yyvsp[(1) - (1)].decl_node)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 162 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (1)].decl_node); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 164 "lang.y"
    { (yyval.stmts_node) = (yyvsp[(1) - (2)].stmts_node); (yyval.stmts_node)->Insert((yyvsp[(2) - (2)].stmt_node)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 165 "lang.y"
    { (yyval.stmts_node) = new cStmtsNode((yyvsp[(1) - (1)].stmt_node)); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 168 "lang.y"
    { (yyval.stmt_node) = new cIfNode((yyvsp[(3) - (7)].expr_node), (yyvsp[(5) - (7)].stmts_node), nullptr); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 170 "lang.y"
    { (yyval.stmt_node) = new cIfNode((yyvsp[(3) - (9)].expr_node), (yyvsp[(5) - (9)].stmts_node), (yyvsp[(7) - (9)].stmts_node)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 172 "lang.y"
    { (yyval.stmt_node) = new cWhileNode((yyvsp[(3) - (5)].expr_node), (yyvsp[(5) - (5)].stmt_node)); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 174 "lang.y"
    { (yyval.stmt_node) = new cPrintNode((yyvsp[(3) - (5)].expr_node)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 175 "lang.y"
    { 
                                  (yyval.stmt_node) = new cAssignNode((yyvsp[(1) - (4)].varref_node), (yyvsp[(3) - (4)].expr_node)); 
                                  CHECK_ERROR(); 
                                }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 179 "lang.y"
    { 
                                  (yyval.stmt_node) = new cAssignNode((yyvsp[(1) - (4)].varref_node), (yyvsp[(3) - (4)].funccall_node)); 
                                  CHECK_ERROR();
                                }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 183 "lang.y"
    { (yyval.stmt_node) = (yyvsp[(1) - (2)].funccall_node); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 184 "lang.y"
    { (yyval.stmt_node) = (yyvsp[(1) - (1)].block_node); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 185 "lang.y"
    { (yyval.stmt_node) = new cReturnNode((yyvsp[(2) - (3)].expr_node)); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 186 "lang.y"
    {}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 188 "lang.y"
    { 
                                  (yyval.funccall_node) = new cFuncExprNode((yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].paramlist_node)); 
                                  CHECK_ERROR();
                                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 192 "lang.y"
    { 
                                    (yyval.funccall_node) = new cFuncExprNode((yyvsp[(1) - (3)].symbol), nullptr);
                                  CHECK_ERROR();
                                }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 197 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (3)].varref_node); (yyval.varref_node)->AddElement((yyvsp[(3) - (3)].symbol)); PROP_ERROR(); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 198 "lang.y"
    { (yyval.varref_node) = new cVarExprNode((yyvsp[(1) - (1)].symbol)); PROP_ERROR(); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 200 "lang.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 202 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (1)].varref_node); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 204 "lang.y"
    { (yyval.paramlist_node) = (yyvsp[(1) - (3)].paramlist_node); (yyval.paramlist_node)->Insert((yyvsp[(3) - (3)].expr_node)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 205 "lang.y"
    { (yyval.paramlist_node) = new cParamListNode((yyvsp[(1) - (1)].expr_node)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 207 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 209 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), OR, (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 210 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 212 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), AND, (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 213 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 215 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), EQUALS, (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 216 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), NEQUALS, (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 217 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 219 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '+', (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 220 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '-', (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 221 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 223 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '*', (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 224 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '/', (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 225 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '%', (yyvsp[(3) - (3)].expr_node)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 226 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 228 "lang.y"
    { (yyval.expr_node) = (yyvsp[(2) - (3)].expr_node); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 229 "lang.y"
    { (yyval.expr_node) = new cIntExprNode((yyvsp[(1) - (1)].int_val)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 230 "lang.y"
    { (yyval.expr_node) = new cFloatExprNode((yyvsp[(1) - (1)].float_val)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 231 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].varref_node); }
    break;


/* Line 1792 of yacc.c  */
#line 2056 "langparse.c"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 233 "lang.y"


// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticError(std::string error)
{
    std::cout << "ERROR: " << error << " on line " << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
