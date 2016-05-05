/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:339  */

	#include <iostream>
	#include <ocelot/parser/interface/PTXParser.h>
	#include <ocelot/parser/interface/PTXLexer.h>
	#include <hydrazine/interface/debug.h>
	#include <cassert>
	#include <cstring>

	#define YYERROR_VERBOSE 1

	#ifdef REPORT_BASE
	#undef REPORT_BASE
	#endif

	#define REPORT_BASE 0

	namespace ptx
	{
	
	int yylex( YYSTYPE* token, YYLTYPE* location, parser::PTXLexer& lexer, 
		parser::PTXParser::State& state );
	void yyerror( YYLTYPE* location, parser::PTXLexer& lexer, 
		parser::PTXParser::State& state, char const* message );
	
	std::string yyTypeToString( int );
	

#line 94 ".release_build/ptxgrammar.cpp" /* yacc.c:339  */

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
   by #include "ptxgrammar.hpp".  */
#ifndef YY_YY_RELEASE_BUILD_PTXGRAMMAR_HPP_INCLUDED
# define YY_YY_RELEASE_BUILD_PTXGRAMMAR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_LABEL = 258,
    TOKEN_IDENTIFIER = 259,
    TOKEN_STRING = 260,
    TOKEN_METADATA = 261,
    TOKEN_INV_PREDICATE_IDENTIFIER = 262,
    TOKEN_PREDICATE_IDENTIFIER = 263,
    OPCODE_COPYSIGN = 264,
    OPCODE_COS = 265,
    OPCODE_SQRT = 266,
    OPCODE_ADD = 267,
    OPCODE_RSQRT = 268,
    OPCODE_MUL = 269,
    OPCODE_SAD = 270,
    OPCODE_SUB = 271,
    OPCODE_EX2 = 272,
    OPCODE_LG2 = 273,
    OPCODE_ADDC = 274,
    OPCODE_RCP = 275,
    OPCODE_SIN = 276,
    OPCODE_REM = 277,
    OPCODE_MUL24 = 278,
    OPCODE_MAD24 = 279,
    OPCODE_DIV = 280,
    OPCODE_ABS = 281,
    OPCODE_NEG = 282,
    OPCODE_MIN = 283,
    OPCODE_MAX = 284,
    OPCODE_MAD = 285,
    OPCODE_MADC = 286,
    OPCODE_SET = 287,
    OPCODE_SETP = 288,
    OPCODE_SELP = 289,
    OPCODE_SLCT = 290,
    OPCODE_MOV = 291,
    OPCODE_ST = 292,
    OPCODE_CVT = 293,
    OPCODE_AND = 294,
    OPCODE_XOR = 295,
    OPCODE_OR = 296,
    OPCODE_CVTA = 297,
    OPCODE_ISSPACEP = 298,
    OPCODE_LDU = 299,
    OPCODE_SULD = 300,
    OPCODE_TXQ = 301,
    OPCODE_SUST = 302,
    OPCODE_SURED = 303,
    OPCODE_SUQ = 304,
    OPCODE_BRA = 305,
    OPCODE_CALL = 306,
    OPCODE_RET = 307,
    OPCODE_EXIT = 308,
    OPCODE_TRAP = 309,
    OPCODE_BRKPT = 310,
    OPCODE_SUBC = 311,
    OPCODE_TEX = 312,
    OPCODE_LD = 313,
    OPCODE_BARSYNC = 314,
    OPCODE_ATOM = 315,
    OPCODE_RED = 316,
    OPCODE_NOT = 317,
    OPCODE_CNOT = 318,
    OPCODE_VOTE = 319,
    OPCODE_SHR = 320,
    OPCODE_SHL = 321,
    OPCODE_FMA = 322,
    OPCODE_MEMBAR = 323,
    OPCODE_PMEVENT = 324,
    OPCODE_POPC = 325,
    OPCODE_PRMT = 326,
    OPCODE_CLZ = 327,
    OPCODE_BFIND = 328,
    OPCODE_BREV = 329,
    OPCODE_BFI = 330,
    OPCODE_BFE = 331,
    OPCODE_TESTP = 332,
    OPCODE_TLD4 = 333,
    OPCODE_BAR = 334,
    OPCODE_PREFETCH = 335,
    OPCODE_PREFETCHU = 336,
    OPCODE_SHFL = 337,
    PREPROCESSOR_INCLUDE = 338,
    PREPROCESSOR_DEFINE = 339,
    PREPROCESSOR_IF = 340,
    PREPROCESSOR_IFDEF = 341,
    PREPROCESSOR_ELSE = 342,
    PREPROCESSOR_ENDIF = 343,
    PREPROCESSOR_LINE = 344,
    PREPROCESSOR_FILE = 345,
    TOKEN_ENTRY = 346,
    TOKEN_EXTERN = 347,
    TOKEN_FILE = 348,
    TOKEN_VISIBLE = 349,
    TOKEN_LOC = 350,
    TOKEN_FUNCTION = 351,
    TOKEN_STRUCT = 352,
    TOKEN_UNION = 353,
    TOKEN_TARGET = 354,
    TOKEN_VERSION = 355,
    TOKEN_SECTION = 356,
    TOKEN_ADDRESS_SIZE = 357,
    TOKEN_WEAK = 358,
    TOKEN_MAXNREG = 359,
    TOKEN_MAXNTID = 360,
    TOKEN_MAXNCTAPERSM = 361,
    TOKEN_MINNCTAPERSM = 362,
    TOKEN_SM11 = 363,
    TOKEN_SM12 = 364,
    TOKEN_SM13 = 365,
    TOKEN_SM20 = 366,
    TOKEN_MAP_F64_TO_F32 = 367,
    TOKEN_SM21 = 368,
    TOKEN_SM10 = 369,
    TOKEN_SM30 = 370,
    TOKEN_SM35 = 371,
    TOKEN_TEXMODE_INDEPENDENT = 372,
    TOKEN_TEXMODE_UNIFIED = 373,
    TOKEN_CONST = 374,
    TOKEN_GLOBAL = 375,
    TOKEN_LOCAL = 376,
    TOKEN_PARAM = 377,
    TOKEN_PRAGMA = 378,
    TOKEN_PTR = 379,
    TOKEN_REG = 380,
    TOKEN_SHARED = 381,
    TOKEN_TEXREF = 382,
    TOKEN_CTA = 383,
    TOKEN_SURFREF = 384,
    TOKEN_GL = 385,
    TOKEN_SYS = 386,
    TOKEN_SAMPLERREF = 387,
    TOKEN_U32 = 388,
    TOKEN_S32 = 389,
    TOKEN_S8 = 390,
    TOKEN_S16 = 391,
    TOKEN_S64 = 392,
    TOKEN_U8 = 393,
    TOKEN_U16 = 394,
    TOKEN_U64 = 395,
    TOKEN_B8 = 396,
    TOKEN_B16 = 397,
    TOKEN_B32 = 398,
    TOKEN_B64 = 399,
    TOKEN_F16 = 400,
    TOKEN_F64 = 401,
    TOKEN_F32 = 402,
    TOKEN_PRED = 403,
    TOKEN_EQ = 404,
    TOKEN_NE = 405,
    TOKEN_LT = 406,
    TOKEN_LE = 407,
    TOKEN_GT = 408,
    TOKEN_GE = 409,
    TOKEN_LS = 410,
    TOKEN_HS = 411,
    TOKEN_EQU = 412,
    TOKEN_NEU = 413,
    TOKEN_LTU = 414,
    TOKEN_LEU = 415,
    TOKEN_GTU = 416,
    TOKEN_GEU = 417,
    TOKEN_NUM = 418,
    TOKEN_NAN = 419,
    TOKEN_HI = 420,
    TOKEN_LO = 421,
    TOKEN_AND = 422,
    TOKEN_OR = 423,
    TOKEN_XOR = 424,
    TOKEN_RN = 425,
    TOKEN_RM = 426,
    TOKEN_RZ = 427,
    TOKEN_RP = 428,
    TOKEN_SAT = 429,
    TOKEN_VOLATILE = 430,
    TOKEN_TAIL = 431,
    TOKEN_UNI = 432,
    TOKEN_ALIGN = 433,
    TOKEN_BYTE = 434,
    TOKEN_WIDE = 435,
    TOKEN_CARRY = 436,
    TOKEN_RNI = 437,
    TOKEN_RMI = 438,
    TOKEN_RZI = 439,
    TOKEN_RPI = 440,
    TOKEN_FTZ = 441,
    TOKEN_APPROX = 442,
    TOKEN_FULL = 443,
    TOKEN_SHIFT_AMOUNT = 444,
    TOKEN_R = 445,
    TOKEN_G = 446,
    TOKEN_B = 447,
    TOKEN_A = 448,
    TOKEN_TO = 449,
    TOKEN_CALL_PROTOTYPE = 450,
    TOKEN_CALL_TARGETS = 451,
    TOKEN_V2 = 452,
    TOKEN_V4 = 453,
    TOKEN_X = 454,
    TOKEN_Y = 455,
    TOKEN_Z = 456,
    TOKEN_W = 457,
    TOKEN_ANY = 458,
    TOKEN_ALL = 459,
    TOKEN_UP = 460,
    TOKEN_DOWN = 461,
    TOKEN_BFLY = 462,
    TOKEN_IDX = 463,
    TOKEN_MIN = 464,
    TOKEN_MAX = 465,
    TOKEN_DEC = 466,
    TOKEN_INC = 467,
    TOKEN_ADD = 468,
    TOKEN_CAS = 469,
    TOKEN_EXCH = 470,
    TOKEN_1D = 471,
    TOKEN_2D = 472,
    TOKEN_3D = 473,
    TOKEN_A1D = 474,
    TOKEN_A2D = 475,
    TOKEN_CUBE = 476,
    TOKEN_ACUBE = 477,
    TOKEN_CA = 478,
    TOKEN_WB = 479,
    TOKEN_CG = 480,
    TOKEN_CS = 481,
    TOKEN_LU = 482,
    TOKEN_CV = 483,
    TOKEN_WT = 484,
    TOKEN_NC = 485,
    TOKEN_L1 = 486,
    TOKEN_L2 = 487,
    TOKEN_P = 488,
    TOKEN_WIDTH = 489,
    TOKEN_DEPTH = 490,
    TOKEN_HEIGHT = 491,
    TOKEN_NORMALIZED_COORDS = 492,
    TOKEN_FILTER_MODE = 493,
    TOKEN_ADDR_MODE_0 = 494,
    TOKEN_ADDR_MODE_1 = 495,
    TOKEN_ADDR_MODE_2 = 496,
    TOKEN_CHANNEL_DATA_TYPE = 497,
    TOKEN_CHANNEL_ORDER = 498,
    TOKEN_TRAP = 499,
    TOKEN_CLAMP = 500,
    TOKEN_ZERO = 501,
    TOKEN_ARRIVE = 502,
    TOKEN_RED = 503,
    TOKEN_POPC = 504,
    TOKEN_SYNC = 505,
    TOKEN_BALLOT = 506,
    TOKEN_F4E = 507,
    TOKEN_B4E = 508,
    TOKEN_RC8 = 509,
    TOKEN_ECL = 510,
    TOKEN_ECR = 511,
    TOKEN_RC16 = 512,
    TOKEN_FINITE = 513,
    TOKEN_INFINITE = 514,
    TOKEN_NUMBER = 515,
    TOKEN_NOT_A_NUMBER = 516,
    TOKEN_NORMAL = 517,
    TOKEN_SUBNORMAL = 518,
    TOKEN_DECIMAL_CONSTANT = 519,
    TOKEN_UNSIGNED_DECIMAL_CONSTANT = 520,
    TOKEN_SINGLE_CONSTANT = 521,
    TOKEN_DOUBLE_CONSTANT = 522
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 36 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:355  */

	char text[1024];
	long long int value;
	long long unsigned int uvalue;

	double doubleFloat;
	float singleFloat;

#line 411 ".release_build/ptxgrammar.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (parser::PTXLexer& lexer, parser::PTXParser::State& state);

#endif /* !YY_YY_RELEASE_BUILD_PTXGRAMMAR_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 439 ".release_build/ptxgrammar.cpp" /* yacc.c:358  */

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
#define YYFINAL  85
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  285
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  271
/* YYNRULES -- Number of rules.  */
#define YYNRULES  710
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1320

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   522

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   281,     2,     2,     2,     2,     2,     2,
     278,   279,     2,   282,   269,   283,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   280,   277,
     275,   274,   276,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   272,     2,   273,     2,   268,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   270,   284,   271,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   151,   151,   151,   152,   152,   152,   152,
     153,   153,   153,   155,   160,   160,   160,   160,   161,   163,
     163,   165,   165,   166,   166,   166,   167,   167,   167,   169,
     174,   179,   179,   179,   180,   180,   182,   187,   192,   198,
     204,   210,   214,   219,   224,   225,   227,   227,   228,   228,
     230,   235,   240,   241,   243,   243,   243,   244,   246,   251,
     256,   257,   259,   259,   259,   260,   262,   262,   262,   262,
     262,   263,   263,   263,   265,   266,   266,   268,   268,   268,
     269,   274,   274,   275,   277,   282,   287,   287,   287,   288,
     288,   290,   295,   297,   301,   301,   303,   303,   303,   303,
     303,   304,   304,   304,   304,   304,   304,   305,   305,   305,
     305,   305,   307,   312,   317,   317,   319,   324,   329,   330,
     332,   334,   334,   334,   334,   335,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   353,   358,
     363,   369,   373,   375,   377,   382,   382,   383,   385,   390,
     395,   400,   405,   406,   408,   410,   411,   414,   420,   427,
     434,   441,   441,   443,   448,   453,   458,   463,   468,   475,
     480,   485,   490,   495,   500,   505,   506,   507,   509,   511,
     513,   513,   515,   520,   525,   526,   528,   534,   540,   542,
     547,   548,   550,   555,   557,   559,   564,   564,   564,   564,
     565,   565,   567,   569,   574,   580,   582,   583,   585,   590,
     595,   600,   606,   611,   611,   613,   618,   623,   628,   633,
     633,   633,   633,   634,   635,   636,   636,   638,   643,   648,
     654,   658,   658,   658,   659,   659,   661,   666,   671,   671,
     671,   671,   671,   672,   672,   672,   672,   672,   673,   673,
     673,   673,   673,   674,   674,   674,   674,   674,   675,   675,
     675,   675,   675,   676,   676,   676,   676,   676,   677,   677,
     677,   678,   678,   678,   679,   679,   679,   679,   679,   680,
     680,   680,   680,   680,   681,   681,   681,   681,   681,   682,
     682,   682,   682,   682,   683,   683,   683,   683,   683,   684,
     684,   684,   684,   684,   685,   685,   685,   686,   686,   688,
     695,   701,   706,   711,   716,   717,   718,   718,   718,   720,
     720,   722,   728,   729,   730,   730,   732,   738,   743,   748,
     753,   753,   753,   753,   755,   761,   765,   770,   775,   780,
     785,   790,   795,   800,   805,   810,   811,   811,   813,   813,
     813,   815,   817,   818,   823,   828,   834,   838,   838,   838,
     838,   839,   839,   839,   839,   841,   846,   851,   851,   853,
     853,   853,   854,   854,   854,   854,   854,   854,   854,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   856,
     856,   856,   856,   856,   856,   856,   856,   856,   856,   857,
     857,   857,   857,   857,   857,   857,   858,   858,   858,   858,
     858,   858,   858,   858,   858,   858,   858,   859,   859,   859,
     859,   859,   859,   859,   861,   861,   862,   862,   862,   862,
     862,   864,   870,   870,   870,   870,   871,   873,   878,   884,
     889,   889,   891,   896,   896,   898,   898,   900,   906,   906,
     908,   915,   919,   924,   929,   934,   935,   937,   937,   939,
     940,   942,   947,   952,   957,   958,   958,   960,   965,   970,
     972,   978,   984,   988,   993,   998,   998,  1000,  1006,  1006,
    1008,  1010,  1017,  1017,  1017,  1017,  1017,  1018,  1018,  1018,
    1018,  1018,  1020,  1025,  1027,  1031,  1037,  1043,  1049,  1053,
    1059,  1065,  1070,  1070,  1070,  1075,  1075,  1077,  1077,  1079,
    1084,  1089,  1094,  1099,  1104,  1109,  1109,  1111,  1112,  1113,
    1114,  1116,  1122,  1122,  1124,  1129,  1140,  1145,  1150,  1155,
    1157,  1157,  1158,  1160,  1165,  1170,  1175,  1180,  1183,  1187,
    1190,  1195,  1200,  1200,  1202,  1202,  1202,  1204,  1210,  1215,
    1220,  1220,  1222,  1228,  1230,  1235,  1241,  1246,  1252,  1252,
    1252,  1254,  1259,  1264,  1269,  1269,  1269,  1271,  1276,  1278,
    1283,  1288,  1293,  1293,  1295,  1300,  1305,  1310,  1310,  1310,
    1311,  1311,  1311,  1313,  1319,  1323,  1323,  1328,  1333,  1338,
    1344,  1349,  1350,  1355,  1355,  1357,  1363,  1363,  1363,  1363,
    1363,  1364,  1364,  1364,  1366,  1371,  1377,  1382,  1387,  1387,
    1387,  1387,  1387,  1387,  1388,  1388,  1388,  1388,  1388,  1388,
    1389,  1389,  1389,  1389,  1389,  1389,  1391,  1396,  1396,  1396,
    1398,  1403,  1408,  1416,  1417,  1419,  1426,  1434,  1435,  1437,
    1437,  1439,  1445,  1451,  1457,  1457,  1457,  1457,  1459,  1464,
    1470,  1477,  1482,  1482,  1482,  1482,  1482,  1483,  1483,  1485,
    1490,  1490,  1490,  1491,  1491,  1491,  1493,  1498,  1503,  1510,
    1510,  1510,  1510,  1512,  1517,  1527,  1527,  1527,  1528,  1528,
    1528,  1529,  1529,  1529,  1530,  1535,  1541,  1547,  1547,  1547,
    1547,  1547,  1552,  1552,  1554,  1554,  1554,  1559,  1559,  1564,
    1573,  1582,  1594,  1599,  1599,  1599,  1599,  1601,  1606,  1606,
    1608
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_LABEL", "TOKEN_IDENTIFIER",
  "TOKEN_STRING", "TOKEN_METADATA", "TOKEN_INV_PREDICATE_IDENTIFIER",
  "TOKEN_PREDICATE_IDENTIFIER", "OPCODE_COPYSIGN", "OPCODE_COS",
  "OPCODE_SQRT", "OPCODE_ADD", "OPCODE_RSQRT", "OPCODE_MUL", "OPCODE_SAD",
  "OPCODE_SUB", "OPCODE_EX2", "OPCODE_LG2", "OPCODE_ADDC", "OPCODE_RCP",
  "OPCODE_SIN", "OPCODE_REM", "OPCODE_MUL24", "OPCODE_MAD24", "OPCODE_DIV",
  "OPCODE_ABS", "OPCODE_NEG", "OPCODE_MIN", "OPCODE_MAX", "OPCODE_MAD",
  "OPCODE_MADC", "OPCODE_SET", "OPCODE_SETP", "OPCODE_SELP", "OPCODE_SLCT",
  "OPCODE_MOV", "OPCODE_ST", "OPCODE_CVT", "OPCODE_AND", "OPCODE_XOR",
  "OPCODE_OR", "OPCODE_CVTA", "OPCODE_ISSPACEP", "OPCODE_LDU",
  "OPCODE_SULD", "OPCODE_TXQ", "OPCODE_SUST", "OPCODE_SURED", "OPCODE_SUQ",
  "OPCODE_BRA", "OPCODE_CALL", "OPCODE_RET", "OPCODE_EXIT", "OPCODE_TRAP",
  "OPCODE_BRKPT", "OPCODE_SUBC", "OPCODE_TEX", "OPCODE_LD",
  "OPCODE_BARSYNC", "OPCODE_ATOM", "OPCODE_RED", "OPCODE_NOT",
  "OPCODE_CNOT", "OPCODE_VOTE", "OPCODE_SHR", "OPCODE_SHL", "OPCODE_FMA",
  "OPCODE_MEMBAR", "OPCODE_PMEVENT", "OPCODE_POPC", "OPCODE_PRMT",
  "OPCODE_CLZ", "OPCODE_BFIND", "OPCODE_BREV", "OPCODE_BFI", "OPCODE_BFE",
  "OPCODE_TESTP", "OPCODE_TLD4", "OPCODE_BAR", "OPCODE_PREFETCH",
  "OPCODE_PREFETCHU", "OPCODE_SHFL", "PREPROCESSOR_INCLUDE",
  "PREPROCESSOR_DEFINE", "PREPROCESSOR_IF", "PREPROCESSOR_IFDEF",
  "PREPROCESSOR_ELSE", "PREPROCESSOR_ENDIF", "PREPROCESSOR_LINE",
  "PREPROCESSOR_FILE", "TOKEN_ENTRY", "TOKEN_EXTERN", "TOKEN_FILE",
  "TOKEN_VISIBLE", "TOKEN_LOC", "TOKEN_FUNCTION", "TOKEN_STRUCT",
  "TOKEN_UNION", "TOKEN_TARGET", "TOKEN_VERSION", "TOKEN_SECTION",
  "TOKEN_ADDRESS_SIZE", "TOKEN_WEAK", "TOKEN_MAXNREG", "TOKEN_MAXNTID",
  "TOKEN_MAXNCTAPERSM", "TOKEN_MINNCTAPERSM", "TOKEN_SM11", "TOKEN_SM12",
  "TOKEN_SM13", "TOKEN_SM20", "TOKEN_MAP_F64_TO_F32", "TOKEN_SM21",
  "TOKEN_SM10", "TOKEN_SM30", "TOKEN_SM35", "TOKEN_TEXMODE_INDEPENDENT",
  "TOKEN_TEXMODE_UNIFIED", "TOKEN_CONST", "TOKEN_GLOBAL", "TOKEN_LOCAL",
  "TOKEN_PARAM", "TOKEN_PRAGMA", "TOKEN_PTR", "TOKEN_REG", "TOKEN_SHARED",
  "TOKEN_TEXREF", "TOKEN_CTA", "TOKEN_SURFREF", "TOKEN_GL", "TOKEN_SYS",
  "TOKEN_SAMPLERREF", "TOKEN_U32", "TOKEN_S32", "TOKEN_S8", "TOKEN_S16",
  "TOKEN_S64", "TOKEN_U8", "TOKEN_U16", "TOKEN_U64", "TOKEN_B8",
  "TOKEN_B16", "TOKEN_B32", "TOKEN_B64", "TOKEN_F16", "TOKEN_F64",
  "TOKEN_F32", "TOKEN_PRED", "TOKEN_EQ", "TOKEN_NE", "TOKEN_LT",
  "TOKEN_LE", "TOKEN_GT", "TOKEN_GE", "TOKEN_LS", "TOKEN_HS", "TOKEN_EQU",
  "TOKEN_NEU", "TOKEN_LTU", "TOKEN_LEU", "TOKEN_GTU", "TOKEN_GEU",
  "TOKEN_NUM", "TOKEN_NAN", "TOKEN_HI", "TOKEN_LO", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_XOR", "TOKEN_RN", "TOKEN_RM", "TOKEN_RZ", "TOKEN_RP",
  "TOKEN_SAT", "TOKEN_VOLATILE", "TOKEN_TAIL", "TOKEN_UNI", "TOKEN_ALIGN",
  "TOKEN_BYTE", "TOKEN_WIDE", "TOKEN_CARRY", "TOKEN_RNI", "TOKEN_RMI",
  "TOKEN_RZI", "TOKEN_RPI", "TOKEN_FTZ", "TOKEN_APPROX", "TOKEN_FULL",
  "TOKEN_SHIFT_AMOUNT", "TOKEN_R", "TOKEN_G", "TOKEN_B", "TOKEN_A",
  "TOKEN_TO", "TOKEN_CALL_PROTOTYPE", "TOKEN_CALL_TARGETS", "TOKEN_V2",
  "TOKEN_V4", "TOKEN_X", "TOKEN_Y", "TOKEN_Z", "TOKEN_W", "TOKEN_ANY",
  "TOKEN_ALL", "TOKEN_UP", "TOKEN_DOWN", "TOKEN_BFLY", "TOKEN_IDX",
  "TOKEN_MIN", "TOKEN_MAX", "TOKEN_DEC", "TOKEN_INC", "TOKEN_ADD",
  "TOKEN_CAS", "TOKEN_EXCH", "TOKEN_1D", "TOKEN_2D", "TOKEN_3D",
  "TOKEN_A1D", "TOKEN_A2D", "TOKEN_CUBE", "TOKEN_ACUBE", "TOKEN_CA",
  "TOKEN_WB", "TOKEN_CG", "TOKEN_CS", "TOKEN_LU", "TOKEN_CV", "TOKEN_WT",
  "TOKEN_NC", "TOKEN_L1", "TOKEN_L2", "TOKEN_P", "TOKEN_WIDTH",
  "TOKEN_DEPTH", "TOKEN_HEIGHT", "TOKEN_NORMALIZED_COORDS",
  "TOKEN_FILTER_MODE", "TOKEN_ADDR_MODE_0", "TOKEN_ADDR_MODE_1",
  "TOKEN_ADDR_MODE_2", "TOKEN_CHANNEL_DATA_TYPE", "TOKEN_CHANNEL_ORDER",
  "TOKEN_TRAP", "TOKEN_CLAMP", "TOKEN_ZERO", "TOKEN_ARRIVE", "TOKEN_RED",
  "TOKEN_POPC", "TOKEN_SYNC", "TOKEN_BALLOT", "TOKEN_F4E", "TOKEN_B4E",
  "TOKEN_RC8", "TOKEN_ECL", "TOKEN_ECR", "TOKEN_RC16", "TOKEN_FINITE",
  "TOKEN_INFINITE", "TOKEN_NUMBER", "TOKEN_NOT_A_NUMBER", "TOKEN_NORMAL",
  "TOKEN_SUBNORMAL", "TOKEN_DECIMAL_CONSTANT",
  "TOKEN_UNSIGNED_DECIMAL_CONSTANT", "TOKEN_SINGLE_CONSTANT",
  "TOKEN_DOUBLE_CONSTANT", "'_'", "','", "'{'", "'}'", "'['", "']'", "'='",
  "'<'", "'>'", "';'", "'('", "')'", "':'", "'!'", "'+'", "'-'", "'|'",
  "$accept", "nonEntryStatements", "nonEntryStatement", "statement",
  "statements", "preprocessorCommand", "preprocessor", "version",
  "identifier", "optionalIdentifier", "identifierList",
  "decimalListSingle", "optionalMetadata", "decimalList",
  "decimalInitializer", "floatListSingle", "floatList", "floatInitializer",
  "singleListSingle", "singleList", "singleInitializer", "shaderModel",
  "floatingPointOption", "textureOption", "targetOption", "targetElement",
  "targetElementList", "target", "addressSize", "addressSpaceIdentifier",
  "addressSpace", "optionalAddressSpace", "pointerDataTypeId",
  "dataTypeId", "dataType", "pointerDataType", "vectorToken",
  "statementVectorType", "instructionVectorType",
  "optionalInstructionVectorType", "alignment", "kernelParameterPtrSpace",
  "parameterAttribute", "addressableVariablePrefix", "arrayDimensionSet",
  "arrayDimensions", "initializer", "assignment", "registerIdentifierList",
  "registerSeperator", "registerPrefix", "registerDeclaration",
  "optionalTimestampAndSize", "fileDeclaration", "globalSharedDeclaration",
  "initializableDeclaration", "globalLocalDeclaration", "textureSpace",
  "textureDeclaration", "samplerDeclaration", "surfaceDeclaration",
  "parameter", "argumentDeclaration", "returnArgumentListBegin",
  "returnArgumentListEnd", "argumentListBegin", "argumentListEnd",
  "openBrace", "closeBrace", "argumentListBody", "returnArgumentList",
  "argumentList", "optionalReturnArgumentList", "functionBegin",
  "functionName", "optionalSemicolon", "functionDeclaration",
  "functionBodyDefinition", "functionBody", "entryName",
  "optionalArgumentList", "entryDeclaration", "entry", "entryStatement",
  "completeEntryStatement", "entryStatements", "maxnreg", "maxntid",
  "ctapersm", "ctapersmList", "minnctapersm", "maxnctapersm",
  "performanceDirective", "performanceDirectiveList",
  "performanceDirectives", "externOrVisible", "uninitializableAddress",
  "initializableAddress", "uninitializable", "initializable", "opcode",
  "uninitializableDeclaration", "location", "label", "labelOperand",
  "returnType", "returnTypeListBody", "returnTypeList",
  "optionalAlignment", "argumentType", "argumentTypeListBody",
  "argumentTypeList", "callprototype", "calltargets", "pragma",
  "vectorIndex", "optionalVectorIndex", "nonLabelOperand",
  "constantOperand", "addressableOperand", "offsetAddressableOperand",
  "callOperand", "operand", "memoryOperand", "branchOperand",
  "arrayOperand", "guard", "floatRoundingToken", "intRoundingToken",
  "floatRounding", "intRounding", "optionalFloatRounding", "instruction",
  "basicInstruction3Opcode", "basicInstruction3",
  "approxInstruction2Opcode", "approximate", "approxInstruction2", "ftz",
  "optionalFtz", "sat", "optionalSaturate", "ftzInstruction2Opcode",
  "ftzInstruction2", "ftzInstruction3Opcode", "ftzInstruction3",
  "optionalUni", "branch", "returnOperand", "returnOperandList",
  "optionalReturnOperandList", "callArgumentList", "optionalPrototypeName",
  "optionalUniOrTail", "call", "optionalCarry", "addModifier",
  "addOrSubOpcode", "addOrSub", "addCOrSubCOpcode", "addCModifier",
  "addCOrSubC", "atomicOperationId", "atomicOperation", "atomModifier",
  "atom", "shiftAmount", "bfe", "bfi", "bfind", "barrierOperation",
  "optionalBarrierOperator", "operandSequence", "bar", "brev", "brkpt",
  "clz", "floatRoundingModifier", "intRoundingModifier",
  "cvtRoundingModifier", "cvtModifier", "cvt", "cvtaOperand", "cvta",
  "divFullModifier", "divApproxModifier", "divRnModifier", "divModifier",
  "div", "exit", "isspacep", "volatileModifier", "optionalVolatile",
  "ldModifier", "ld", "ldu", "hiOrLo", "roundHiLoWide", "mulModifier",
  "madOpcode", "mad", "mad24Modifier", "mad24", "madCModifier", "madc",
  "membarSpaceType", "membarSpace", "membar", "movIndexedOperand",
  "movSourceOperand", "mov", "mul24Modifier", "mul24", "mul", "notOpcode",
  "notInstruction", "pmevent", "popc", "permuteModeType", "permuteMode",
  "cacheLevel", "prefetch", "prefetchu", "prmt", "rcpSqrtModifier",
  "rcpSqrtOpcode", "rcpSqrtInstruction", "reductionOperationId",
  "reductionOperation", "red", "ret", "comparisonId", "comparison",
  "boolOperatorId", "boolOperator", "sad", "selp", "setModifier", "set",
  "setpModifier", "predicatePair", "setp", "shuffleModifierId",
  "shuffleModifier", "shfl", "slct", "st", "geometryId", "geometry",
  "floatingPointModeType", "floatingPointMode", "testp", "tex",
  "colorComponentId", "colorComponent", "tld4", "surfaceQuery", "txq",
  "suq", "cacheOperation", "optionalCacheOperation", "clampOperation",
  "formatMode", "suld", "sust", "sured", "trap", "voteOperationId",
  "voteOperation", "voteDataType", "vote", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,    95,    44,
     123,   125,    91,    93,    61,    60,    62,    59,    40,    41,
      58,    33,    43,    45,   124
};
# endif

#define YYPACT_NINF -1038

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1038)))

#define YYTABLE_NINF -231

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     438, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
    -165, -1038,   714,  -110,  -101, -1038,   310, -1038, -1038, -1038,
     210, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   -88, -1038,   -90,    -2, -1038,
     223,   244,   192, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   -49,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,   781,  2999, -1038, -1038, -1038,    86, -1038,
      29, -1038,   179, -1038,    70,  2999, -1038, -1038,   205,   244,
   -1038,   244,   221,   -35, -1038,     5,   -23,   482,   310,  2999,
      32,   714, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,    12,  -186, -1038,    20,
   -1038, -1038,    47,   316, -1038,    86, -1038, -1038,    70,   286,
     244, -1038, -1038, -1038, -1038, -1038, -1038,  3184, -1038, -1038,
     244, -1038,  -209,    60,    69,   -61,    10, -1038, -1038, -1038,
   -1038, -1038,   179, -1038,   322, -1038,    70, -1038,  2999,  2999,
    2999,  2999,  2999, -1038,    29, -1038,  2999, -1038,   136,   160,
      33,   160,   160,   781,    33,   781,    79,    91, -1038, -1038,
      96, -1038, -1038,  2999, -1038,   115,  2999, -1038,   167,   163,
      70, -1038, -1038, -1038, -1038, -1038, -1038,  2999, -1038, -1038,
   -1038, -1038, -1038,   248,   781, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   303,    58,   -60, -1038, -1038, -1038, -1038, -1038,
     303,   573,   534,   781,   278,   781,   301,   253, -1038, -1038,
   -1038,   -24,   340,   301,  -149,   370,  -149,  -149,   370,   306,
     233,   306,   212,   222,   227, -1038,   348,   301,   340,   340,
   -1038, -1038,  -116, -1038, -1038, -1038,   142,  2019,   781,   781,
     781,   330,   781,   781,   781,   284,   180,   147,   340,   283,
     266,   322,   781, -1038,   362, -1038,   278, -1038,   278, -1038,
   -1038, -1038,   135, -1038,   392, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   248, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   781,
   -1038, -1038, -1038, -1038, -1038, -1038,   -95, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,  2999,    29, -1038,
   -1038, -1038,   315, -1038,   307, -1038,   320, -1038,   320, -1038,
   -1038, -1038,    79,    79,   308,   314,   317,  -193, -1038,   -90,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,  -124,   321,   318,   327,   319, -1038,   -81,  2999,
   -1038,  -166,   333, -1038, -1038,    79, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,   425,   419,   278,
     781,  2019, -1038,   781, -1038, -1038, -1038,   425,   781,   278,
     278,   278, -1038, -1038, -1038,   781,   392,   781, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   650, -1038,    18,   781,
     573,   650,    18,   781,  2019,   781,  1596, -1038, -1038,   340,
     781, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   425, -1038,
   -1038,   278,   781, -1038, -1038, -1038, -1038, -1038,   340, -1038,
     113,  2019,   781, -1038, -1038,   348, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   781,   348,    67,   781,
   -1038,  2999, -1038, -1038,   323,  1671, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,   404,   781, -1038,
     190,    67, -1038, -1038, -1038, -1038, -1038,   111, -1038, -1038,
   -1038, -1038,   356, -1038, -1038, -1038, -1038,  2999,   279, -1038,
   -1038, -1038,  2019,   305,  2019, -1038,   781,  2019,  2019,  2019,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,   781, -1038, -1038,
   -1038, -1038, -1038,   418, -1038, -1038, -1038,    67,   283, -1038,
   -1038,   364, -1038, -1038, -1038, -1038, -1038,   781, -1038,  2019,
   -1038,   278,   781,   781, -1038, -1038,   278,   781, -1038, -1038,
     781,   781,  2019,   278,   278,   781,    79, -1038,   373,   374,
     377,   365,   366, -1038, -1038, -1038, -1038, -1038,    11,   368,
   -1038,   381, -1038,   369,  2169,   385, -1038, -1038,   781, -1038,
    -179,   372,  2999, -1038, -1038,   376, -1038, -1038,   425,  2019,
     382,  2019, -1038,  2019, -1038, -1038, -1038,  2019, -1038,  2019,
   -1038, -1038, -1038, -1038, -1038, -1038,   278,   781,   278,  2019,
   -1038, -1038,   278,  2019,   386,   781,  2999, -1038,   387, -1038,
      92,   389, -1038,   425,   781,   113, -1038, -1038, -1038,  2019,
     388,  1596,    92,  2019,    92, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   348,  2019, -1038, -1038,   424,  2019,
    2999, -1038,   426,   781,  1596, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   781,   781, -1038, -1038,
    2019, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   390,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,  2019,   393,  2019,
     394,   395,   396,  2019,   456,  2019,   781,   430,  2584,  2019,
     436,   781,  2019,  2019,   425,  2019,  2019,  2019,   437, -1038,
   -1038,  2019, -1038,   439, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   434, -1038, -1038, -1038, -1038,  2434, -1038,   440, -1038,
   -1038,   441, -1038, -1038,   442, -1038, -1038, -1038,  2999,    29,
   -1038,   -80,   463, -1038, -1038, -1038,   444,  2019,   446,   447,
     448,   449,   781,  2019,   435,   472,   781,   474,  2019,  2019,
    -155,  1596, -1038, -1038, -1038, -1038, -1038, -1038,    33,  2584,
   -1038,  2019,  2019,   475,  2019,   476,    33,   478,    33,   781,
     479, -1038, -1038, -1038, -1038,  -157,   480, -1038,   781,   483,
    2019,  2019,   484,  2019,   486,  2019,   487,  2019,  2019,  2019,
     488,   781,  2019,   481, -1038,  2584,   272, -1038, -1038, -1038,
     489,   491,  2019,  2019,   492,   496, -1038,   497,   498,   499,
    2019,   500,   506, -1038,  2434,    97,   501,   161,   502,   194,
     503,  2849,   391,   485, -1038, -1038, -1038, -1038,   160, -1038,
    -140, -1038,  2019,   507,  2019,  2019,  2019,  2019,   781,   509,
    2019,  2019,  2019,  2019,   510,   511, -1038,    64, -1038, -1038,
   -1038,   494, -1038, -1038, -1038,   508,   513,   514,  2019,   512,
     515,   781,   516,   781,   171,   518,  2019,   517,  2094,   519,
    1596,   520,   522,   525,  2019,   540,  2019,   542,  2019,   543,
     526,   528,  2019,   781, -1038, -1038,   561,   571,   572,   560,
    2019,   569,   570,  2019,  2019,  2019,  2019,  2019,   564,  2019,
   -1038,   229,   575,   234,   577,   240,   579,   574,   582,   583,
     585,   586,   587, -1038, -1038, -1038, -1038, -1038,   781,    29,
   -1038,   588,  2019,   589,   590,   591,   592,  2019,  2019, -1038,
     593,   594,   595,  2019,  2019,   578, -1038,   596,  2019,  2019,
     -69, -1038, -1038,   567, -1038,  2584,   171,  2019,   171, -1038,
   -1038, -1038,   598,  2019, -1038, -1038,  1746, -1038, -1038,   597,
    2584,   599,  2019,   600, -1038,   603, -1038,   601, -1038,  2019,
    2019,   602,  1596,   604, -1038, -1038, -1038,   605,  2019,  2019,
     606,   611,   613,   617,   618, -1038,   612,   574,   582,   583,
     585,   586,   587,   620,   621,   622,   623,   625,   626,  2999,
   -1038,  2019,   619,  2019,  2019,  2019,  2019,   628,   630,  2019,
    2019,  2019,   631,   632,   629,  1596,   627,   633, -1038,   634,
    1596,   636,   658,  2019,   659,   662, -1038,   -85,   661,   663,
    2584,   657, -1038,  2019, -1038,   666,   668, -1038,   669, -1038,
    2019,   664,   665, -1038,  2019,  2019,  2019,  2019, -1038,  2924,
     635,   608,   670,   607,   674,    79,   671,  2019,   672,   677,
     673,   678,  2019,  2019,   675,   682,   676,  2019,  2019, -1038,
     680, -1038, -1038,   681,   685,   683,  2019,   686,   684,  2999,
    2019,   690,  2019,   687,   689, -1038,   694,  2019,  2019,   667,
     697, -1038, -1038,   692,   695,   696,   698,   249,  2509,   703,
     264,   -91,   704,   265,   -25,   705, -1038, -1038,   700, -1038,
    2019, -1038,  2019,   709,   702, -1038,  2019, -1038,   706,   711,
   -1038, -1038,   710, -1038,   712,  1596, -1038, -1038, -1038,  2999,
     715, -1038,   716,  2019,   718,   717,  2019,  2019, -1038, -1038,
   -1038,  2019, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   719,
     721,  2019, -1038,   720, -1038,  2019,  2019,  1596,   726, -1038,
    1596,  2019,   723,  2019, -1038,   722,   725,   727, -1038, -1038,
     736,  2019,   729,   738,   735,   740,   737,   -52, -1038,   734,
    1596, -1038, -1038,  2019,   739, -1038,  1596,   743,  1596,   741,
    2019, -1038, -1038,   742,   744, -1038,   746,  1596,   745, -1038,
     747,   749, -1038,   750,   751, -1038, -1038, -1038, -1038, -1038
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     230,    21,    22,    23,    24,    25,    26,    27,    28,   228,
       0,   229,    81,     0,     0,   227,     0,    13,    15,    19,
     230,    29,     6,     2,     3,    12,     4,     5,    10,    14,
      11,     9,     7,     8,    18,     0,    17,   191,     0,    16,
       0,     0,     0,    67,    68,    69,    70,    74,    71,    66,
      72,    73,    75,    76,    77,    78,    79,    80,    82,    84,
      30,    85,    98,   102,   100,   101,   103,    96,    97,    99,
     104,   105,   106,   107,   108,   110,   109,   111,   114,   115,
     112,   153,   116,     0,     0,     1,    20,   173,   356,   171,
     176,   190,   225,   195,   356,     0,   182,   234,   235,     0,
     161,     0,     0,   181,   237,     0,   128,     0,     0,     0,
     155,     0,   152,    32,   266,   238,   239,   240,   241,   243,
     244,   245,   246,   247,   242,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   268,   271,   272,   273,   269,   270,   283,
     285,   286,   287,   288,   289,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   284,   290,   291,   292,   293,   294,
     295,   296,   298,   297,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   267,    31,   148,     0,    33,    41,
     355,   354,     0,     0,   196,   356,   203,   206,   356,     0,
       0,   202,   197,   198,   200,   201,   199,     0,   166,   167,
       0,   175,     0,     0,     0,     0,     0,   219,   220,   222,
     221,   223,   226,   192,    41,   194,   356,   189,     0,     0,
       0,     0,     0,   169,   176,   180,     0,   120,     0,   126,
     135,     0,   127,     0,   136,     0,   141,     0,   157,    83,
       0,   150,   154,     0,    42,   318,     0,   311,     0,   328,
     356,   188,   207,   231,   233,   232,   236,     0,   430,   434,
     594,   475,   432,   441,     0,   476,   436,   435,   478,   593,
     433,   426,   568,   444,   529,   445,   446,   449,   448,   550,
       0,     0,     0,     0,   441,     0,   538,   441,   424,   429,
     425,     0,     0,   538,     0,     0,     0,     0,     0,   451,
     451,   451,     0,     0,     0,   479,     0,   538,   494,     0,
     573,   572,     0,   428,   427,   551,     0,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,   372,     0,   371,   441,   369,   441,   370,
     377,   469,   368,   378,   472,   379,   380,   373,   374,   375,
     381,   376,   382,   383,   384,   385,   387,   388,   386,   389,
     390,   441,   391,   392,   393,   394,   395,   396,   397,     0,
     398,   399,   400,   401,   402,   403,   591,   404,   405,   406,
     407,   408,   409,   410,   423,   411,   412,   417,   418,   419,
     421,   414,   413,   416,   415,   420,   422,     0,     0,   172,
     179,   208,   209,   217,     0,   213,   218,   215,   216,   224,
     174,   193,   141,   141,     0,     0,     0,     0,   183,     0,
     122,   121,   123,   124,   125,   132,   131,   137,   133,   134,
     129,   130,     0,   142,   143,     0,     0,   151,     0,     0,
      36,     0,     0,   329,   205,   141,   542,   543,   357,   358,
     360,   359,   546,   439,   365,   544,   440,   444,   545,   441,
       0,     0,   569,     0,   442,   443,   553,   444,     0,   441,
     441,   441,   530,   531,   532,     0,   472,     0,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   625,   624,     0,   626,   441,     0,
       0,     0,   441,     0,     0,     0,     0,   536,   537,    93,
       0,   361,   362,   364,   363,   366,   513,   514,   520,   516,
     515,   441,     0,    86,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   697,   698,     0,   675,   677,   676,   680,
     681,   682,   683,   684,   678,   679,     0,     0,     0,     0,
     452,     0,   467,   468,   458,     0,   534,   702,   511,   652,
     653,   654,   655,   656,   657,   658,   659,     0,     0,   493,
       0,     0,   705,   703,   704,   706,   707,     0,   559,   558,
     560,   561,     0,   338,   339,   341,   340,     0,   335,   347,
     346,   575,     0,   584,     0,   497,     0,     0,     0,     0,
     660,   661,   662,   663,   664,   665,   666,     0,   671,   672,
     670,   669,   673,     0,   502,   503,   504,   506,     0,   585,
     586,     0,   644,   645,   646,   647,   648,     0,   204,     0,
     437,   441,     0,     0,   473,   367,   441,     0,   471,   480,
       0,     0,     0,   441,   441,     0,   141,   177,     0,     0,
       0,     0,     0,   163,   165,   164,   170,   178,   185,     0,
     140,     0,   144,     0,     0,     0,   149,   317,     0,   314,
       0,     0,     0,   327,   310,     0,   549,   548,   444,     0,
       0,     0,   554,     0,   528,   527,   526,     0,   556,     0,
     634,   627,   628,   629,   633,   630,   441,     0,   441,     0,
     638,   637,   441,     0,     0,     0,     0,   352,     0,    92,
     693,     0,   519,   518,     0,     0,    95,    94,   113,     0,
       0,     0,   693,     0,   693,   596,   598,   597,   602,   603,
     601,   600,   599,   604,     0,     0,   312,   351,     0,     0,
       0,   606,     0,     0,     0,   482,   483,   484,   490,   491,
     489,   488,   487,   485,   486,   492,     0,     0,   709,   708,
       0,   562,   337,   330,   331,   332,   333,   334,   336,     0,
     577,   578,   579,   580,   581,   582,   583,     0,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
       0,     0,     0,     0,   444,     0,     0,     0,     0,   592,
     590,     0,   168,   210,   212,   214,   160,   158,   184,   186,
     138,     0,   159,    40,    58,    50,     0,    38,    49,    46,
     145,    57,    54,   146,    65,    62,   147,   156,    34,     0,
     316,     0,     0,    37,   309,   547,     0,     0,     0,     0,
       0,     0,     0,     0,   640,     0,     0,     0,     0,     0,
       0,     0,   687,   688,   689,   690,   691,   692,   119,     0,
     517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   453,   454,   345,   455,     0,   466,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   508,     0,   505,     0,   342,   348,   349,   350,
       0,     0,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,   313,   315,   325,   319,   322,
       0,   326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   353,   335,   565,   564,
     566,     0,   117,   118,   539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   507,   509,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,     0,     0,     0,     0,     0,     0,    48,    47,    56,
      55,    64,    63,    43,    39,    51,    59,   320,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,   639,
       0,     0,     0,     0,     0,     0,   567,     0,     0,     0,
     335,   523,   522,     0,   535,     0,     0,     0,     0,   696,
     694,   695,     0,     0,   456,   457,     0,   463,   470,     0,
       0,     0,     0,     0,   576,     0,   512,     0,   510,     0,
       0,     0,     0,     0,   343,   344,   588,     0,     0,     0,
       0,     0,     0,     0,     0,   574,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   524,     0,
       0,     0,     0,     0,     0,   465,   459,     0,     0,     0,
       0,     0,   710,     0,   501,     0,     0,   667,     0,   587,
       0,     0,     0,   447,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   563,
       0,   521,   525,     0,     0,     0,     0,     0,     0,     0,
       0,   464,     0,     0,     0,   605,     0,     0,     0,     0,
       0,   431,   438,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   321,   571,     0,   570,
       0,   533,     0,     0,     0,   642,     0,   641,     0,     0,
     651,   541,     0,   685,     0,     0,   686,   462,   460,     0,
       0,   540,     0,     0,     0,     0,     0,     0,   450,   477,
     481,     0,    45,    44,    53,    52,    61,    60,   631,     0,
       0,     0,   635,     0,   632,     0,     0,     0,     0,   461,
       0,     0,     0,     0,   499,     0,     0,     0,   555,   557,
       0,     0,     0,     0,     0,     0,     0,     0,   589,     0,
       0,   649,   552,     0,     0,   650,     0,     0,     0,     0,
       0,   495,   500,     0,     0,   643,     0,     0,     0,   668,
       0,     0,   636,     0,     0,   701,   496,   674,   699,   700
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1038, -1038, -1038,   764, -1038, -1038, -1038, -1038,   -84,  -242,
     152,  -665,  -191,  -658, -1038,  -660,  -667, -1038,  -666,  -668,
   -1038,    45, -1038, -1038, -1038,   792, -1038, -1038, -1038, -1038,
    -280, -1038, -1038,  -659,    -3,   263,  -650,     7,  -326, -1038,
    -105, -1038, -1038,   -33, -1038,  -419, -1038, -1038, -1038, -1038,
   -1038,    59, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,  -443,   584, -1038, -1038, -1038, -1038,   326,  -152,   780,
   -1038,   609, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   -55,   -57, -1038, -1038,   360,   807,
   -1038, -1038,   808, -1038, -1038,    62, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   193, -1038, -1038, -1038,     0,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,  -788, -1038,
    -827, -1037,   304,  -849, -1038,  -719, -1038, -1038, -1038,  -246,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,  -260,  -279,
    -504,  -450, -1038, -1038, -1038, -1038,   270, -1038,    55, -1038,
   -1038, -1038, -1038, -1038, -1038,   548, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   133, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   -13, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,  -232, -1038, -1038,  -218, -1038,   679, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
     411, -1038, -1038, -1038, -1038, -1038, -1038, -1038,  -518, -1038,
   -1038, -1038,  -262, -1038,   529, -1038, -1038, -1038, -1038,   530,
    -692, -1038, -1038, -1038, -1038, -1038, -1038, -1038,  -517, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   752, -1038, -1038, -1038,
    -160,  -480,   276, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,   598,   935,
     451,  1011,   257,  1012,   830,  1013,  1014,   833,  1015,  1016,
     836,   414,    55,    56,    57,    58,    59,    24,    25,   539,
     540,   720,   728,    80,   106,   729,    82,   107,   963,   964,
     108,   434,   241,   109,   443,   444,   673,   674,   187,   253,
      84,   194,   248,    27,    28,    29,    30,   102,    31,    32,
      33,   210,   211,   234,   667,    90,   410,   195,   225,   212,
     235,    91,   236,   103,   429,   819,    34,    35,    36,    37,
      92,    38,    39,   196,   197,   198,   217,   218,   415,   416,
     219,   220,   221,   222,   223,   199,   266,   104,   200,    41,
     188,   201,   202,   203,   747,   679,   680,   449,  1028,   939,
     940,   842,   204,   205,   206,   777,   778,   599,   600,   908,
     909,   882,   717,   910,   748,   718,   207,   464,   525,   465,
     527,   646,   341,   342,   343,   344,   641,   345,   466,   467,
     475,   476,   346,   347,   348,   349,   561,   350,   884,   885,
     750,  1137,   979,   564,   351,   649,   647,   352,   353,   354,
     650,   355,   765,   766,   580,   356,   606,   357,   358,   359,
     627,   795,   903,   360,   361,   362,   363,   529,   530,   531,
     532,   364,  1053,   365,   482,   483,   484,   485,   366,   367,
     368,   518,   519,   520,   369,   370,   468,   469,   470,   371,
     372,   478,   373,   487,   374,   591,   592,   375,   960,   961,
     376,   473,   377,   378,   379,   380,   381,   382,   786,   787,
     631,   383,   384,   385,   655,   386,   387,   743,   744,   388,
     389,   507,   508,   705,   706,   390,   391,   509,   392,   513,
     855,   393,   636,   637,   394,   395,   396,   576,   577,   616,
     617,   397,   398,   622,   623,   399,   556,   400,   401,   867,
     868,  1062,   545,   402,   403,   404,   405,   586,   587,   770,
     406
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     186,   240,   243,   661,   662,   678,   835,   832,   834,   828,
     907,   227,   875,    81,   831,   515,   829,   686,   528,   838,
     965,   857,   541,    83,   722,   246,   254,   692,   732,  1136,
     512,   506,   511,   420,   958,   889,   685,   226,   579,   581,
     734,   208,   208,   543,   209,   209,   261,    43,    44,    45,
      46,   526,    48,    49,    50,    51,   996,    54,   628,    26,
     408,   582,    40,   767,   472,   477,   228,   642,   229,   643,
     409,   542,   486,   189,   421,   653,   408,   190,   191,    26,
     112,   907,    40,   251,   544,   578,   666,   583,   584,   189,
     839,   252,   654,   190,   191,   533,   534,   535,   536,    42,
     840,   238,   537,   682,   242,   244,   645,   911,   454,   796,
     479,   683,   976,   239,   682,   245,   956,   907,    43,    44,
      45,    46,   977,    48,    49,    50,    51,   480,   481,  1029,
     773,   774,   775,   776,   435,   585,   437,   438,   260,  1030,
     669,  1051,   959,   262,   422,   423,   424,   425,   426,   670,
     638,   208,   428,  1238,   209,   105,    54,    60,   930,   928,
     929,   925,     9,    61,    11,   192,   927,   267,   926,   447,
     538,   262,   450,    15,    78,    79,   825,   407,     9,  1211,
      11,   192,    87,   455,  1190,   701,   702,   703,    89,    15,
     688,  -230,  -230,   193,  1191,    16,  -230,   110,   677,   937,
     694,   695,   696,   413,   463,   262,  1129,  -230,  -230,   193,
      85,    16,  -230,   997,   998,   255,   256,  1300,   962,   870,
     111,  1139,  1051,   456,   457,  1301,   962,   879,   962,   704,
      78,    79,   474,   711,   735,   736,   737,   812,   845,   719,
     439,   824,   441,   233,   700,  1214,   726,   436,   708,   710,
     511,   440,   723,   727,   768,   430,   431,   432,   725,   769,
    1041,  1069,   433,   773,   774,   775,   776,   907,    87,   237,
     588,   471,   589,   590,   417,    93,   738,   739,   740,   741,
     742,  -187,   907,   213,   214,   215,   216,   250,   818,   510,
     514,  1194,   516,     1,     2,     3,     4,     5,     6,     7,
       8,   247,     9,    10,    11,   458,   459,   460,   461,    12,
      13,   258,    14,    15,    95,   862,   644,   863,   864,    96,
     865,   259,   866,   656,   411,   602,   603,   604,   254,   607,
     608,   609,  -162,   412,  -162,    16,  1045,  -162,   105,   639,
      87,   224,    97,    98,    99,   100,   997,   998,   230,   101,
     231,   442,   907,   232,   916,   445,    87,   755,   756,   757,
     446,    88,   801,  1148,    94,   681,   931,   804,  1017,  1109,
     618,   619,   620,   621,   809,   810,   652,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   448,   624,   625,   678,   626,   938,   758,
     759,   760,   761,   762,   763,   764,  1180,   263,   264,   562,
     560,  1184,   265,   456,   457,  1059,  1060,  1061,   458,   459,
     460,   461,   105,   458,   459,   460,   461,   852,   462,   711,
     932,   452,  1019,   856,   463,   521,   522,   523,   524,   463,
     453,    78,    79,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   533,
     534,   535,   536,   933,   463,  1021,   537,   689,   456,   457,
     691,   632,   633,   634,   635,   693,   517,   746,   773,   774,
     775,   776,   697,   560,   699,    43,    44,    45,    46,   566,
      48,    49,    50,    51,  1207,  1212,  1215,  1213,   931,   567,
    1097,  1210,  1209,   932,   568,  1099,   707,    78,    79,   933,
     713,  1101,   715,   772,   629,   630,  1268,   721,   931,   605,
    1252,     1,     2,     3,     4,     5,     6,     7,     8,   724,
       9,    10,    11,   932,   933,  1254,  1256,    12,    13,   731,
      14,    15,   610,   611,   612,   613,   614,   615,  1284,   640,
     971,  1286,   973,   733,   997,   998,   745,   780,   781,   782,
     783,   784,   785,    16,   569,   570,   571,   572,   573,   574,
     575,  1303,   876,   648,   878,   754,  1130,  1306,  1132,  1308,
     563,   565,   557,   558,   658,   663,   938,   659,  1314,   660,
     827,   664,   672,   671,   665,   676,   675,   684,   843,   474,
     687,   749,   753,   789,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   793,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   601,   450,   771,   799,   794,   798,   813,   814,   802,
     803,   820,   816,   817,   805,   821,   822,   806,   807,   837,
     841,   847,   811,   844,   901,   858,   861,   874,  1025,   893,
     105,   869,   895,   897,   898,   899,   886,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   881,   905,   887,   853,   912,   920,   923,   922,   931,
     932,   933,   859,   942,   906,   944,   945,   946,   947,   950,
     463,   871,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     941,   951,   827,   953,   968,   970,  1216,   972,   975,   978,
     888,  1026,   981,   984,   934,   986,   988,   992,   995,   463,
    1000,  1003,   999,   890,   891,  1004,  1005,  1006,  1007,  1009,
    1010,  1046,  1018,  1020,  1022,   690,  1032,   957,  1038,  1043,
    1044,  1047,  1048,  1049,    86,   906,  1065,  1055,  1057,  1054,
    1063,  1071,  1070,   904,  1072,  1079,  1068,  1080,   913,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,  1074,   714,  1076,
    1078,   906,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,  1027,  1083,  1084,  1085,  1086,  1088,  1089,
     827,  1095,  1124,  1103,  1128,   730,  1098,  1024,  1100,   948,
    1102,  1104,  1105,   952,  1106,  1107,  1108,  1111,  1113,  1114,
    1115,  1116,  1119,  1120,  1121,  1125,  1138,  1165,   860,   752,
    1133,  1140,  1143,   824,  1150,   825,   974,  1142,  1144,  1147,
    1154,  1149,  1155,  1153,  1050,   980,  1156,  1157,  1167,  1158,
    1159,  1160,  1161,  1162,  1067,  1163,  1164,  1172,   993,  1173,
    1177,  1178,  1179,   249,  1181,  1208,   779,  1183,   788,  1185,
    1182,   790,   791,   792,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    1186,  1189,  1188,  1192,  1195,  1197,  1193,  1198,  1199,  1246,
    1211,  1201,  1202,   800,  1214,  1037,  1220,  1222,  1217,  1219,
    1221,  1226,  1225,  1227,  1232,  1235,   808,  1230,  1231,  1239,
    1233,  1236,  1242,  1243,  1241,  1050,  1247,  1251,  1056,  1248,
    1058,   906,  1249,  1250,  1253,  1255,  1257,  1258,  1261,  1262,
    1265,  1267,  1266,  1264,  1270,  1271,   906,  1273,   872,  1281,
    1082,  1290,   657,   846,  1274,   848,  1278,   849,  1279,  1285,
    1288,   850,  1291,   851,  1292,  1293,  1295,  1296,  1297,  1298,
    1299,  1302,  1307,   854,   427,  1311,  1305,   854,  1309,  1313,
     815,  1312,  1315,   418,  1316,   934,  1317,  1318,  1319,  1110,
     419,  1064,   936,   873,   698,   994,  1127,   877,   668,   797,
     709,   712,     0,     0,     0,     0,     0,     0,     0,   880,
     651,     0,     0,   883,     0,     0,   906,     0,     0,     0,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   892,   827,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   894,     0,   896,     0,     0,     0,   900,     0,   902,
       0,     0,     0,   854,     0,  1237,   914,   915,     0,   917,
     918,   919,     0,     0,     0,   921,     0,     0,     0,     0,
       0,     0,     0,     0,   827,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   943,     0,     0,     0,  1269,     0,   949,     0,     0,
       0,     0,   954,   955,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   966,   967,     0,   969,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   982,   983,     0,   985,     0,   987,
       0,   989,   990,   991,     0,     0,   902,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1001,  1002,     0,     0,
       0,     0,     0,     0,  1008,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1031,     0,  1033,  1034,
    1035,  1036,     0,     0,  1039,  1040,   854,  1042,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1052,     0,     0,     0,     0,     0,     0,     0,
     883,     0,     0,     0,     0,     0,     0,     0,  1073,     0,
    1075,     0,  1077,     0,     0,     0,  1081,     0,     0,     0,
       0,     0,     0,     0,  1087,     0,     0,  1090,  1091,  1092,
    1093,  1094,     0,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,  1117,  1118,     0,     0,     0,     0,  1122,  1123,     0,
       0,     0,  1126,  1052,     0,     0,     0,     0,     0,     0,
       0,  1131,     0,     0,     0,     0,     0,  1134,     0,     0,
     883,     0,     0,     0,     0,     0,  1141,     0,     0,     0,
       0,     0,     0,  1145,  1146,     0,     0,     0,     0,     0,
       0,     0,  1151,  1152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1166,     0,  1168,  1169,  1170,
    1171,     0,     0,  1174,  1175,  1176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1196,     0,     0,
       0,     0,     0,     0,  1200,     0,     0,     0,  1203,  1204,
    1205,  1206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1218,     0,     0,     0,     0,  1223,  1224,     0,     0,
       0,  1228,  1229,     0,     0,     0,     0,     0,     0,     0,
    1234,     0,     0,     0,   883,     0,  1240,     0,     0,     0,
       0,  1244,  1245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1259,     0,  1260,     0,     0,     0,
    1263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1272,     0,     0,
    1275,  1276,     0,     0,     0,  1277,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1280,     0,     0,     0,  1282,
    1283,     0,     0,     0,     0,  1287,     0,  1289,     0,     0,
       0,     0,     0,     0,     0,  1294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1304,     0,     0,
     113,     0,     0,     0,  1310,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,   176,   177,
     178,   179,     0,   180,   181,   113,   182,   183,   184,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   179,     0,   180,   181,
     113,   182,   183,   184,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,   176,   177,
     178,   179,     0,   180,   181,     0,   182,   183,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,   594,   595,   596,   185,     0,   716,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   597,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   593,   594,   595,   596,   185,
       0,     0,     0,     0,     0,     0,     0,     0,   751,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,   594,   595,   596,   185,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,  1135,     0,   597,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,     0,   180,   181,   113,   182,
     183,   184,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   176,   177,   178,   179,
       0,   180,   181,   113,   182,   183,   184,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,     0,   180,   181,     0,   182,
     183,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   593,   594,   595,   596,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1066,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   823,     0,   824,   825,   185,   113,   826,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   176,   177,   178,   179,
       0,   180,   181,   113,   182,   183,   184,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,     0,   180,   181,   113,   182,
     183,   184,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   176,   177,   178,   179,
       0,   180,   181,     0,   182,   183,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   823,     0,
     824,   825,   185,     0,   924,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   823,     0,     0,     0,   185,     0,  1208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   593,   594,
     595,   596,   185,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,     0,   180,   181,   113,   182,
     183,   184,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   176,   177,   178,   179,
       0,   180,   181,   113,   182,   183,   184,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,     0,   180,   181,     0,   182,
     183,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1023,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   823,     0,
       0,     0,   185,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,     0,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   185
};

static const yytype_int16 yycheck[] =
{
      84,   106,   107,   422,   423,   448,   674,   674,   674,   674,
     798,    95,   731,    16,   674,   294,   674,   467,   297,   678,
     869,   713,   302,    16,   528,   109,     6,   477,   545,  1066,
     292,   291,   292,   224,   861,   754,   455,    94,   318,   319,
     557,   122,   122,   192,   125,   125,   198,   108,   109,   110,
     111,   297,   113,   114,   115,   116,   905,    12,   338,     0,
     269,   177,     0,   581,   282,   283,    99,   346,   101,   348,
     279,   303,   290,     3,   226,   170,   269,     7,     8,    20,
      83,   869,    20,   269,   233,   317,   279,   203,   204,     3,
     269,   277,   187,     7,     8,   119,   120,   121,   122,   264,
     279,   124,   126,   269,   107,   108,   352,   799,   260,   627,
     170,   277,   269,   106,   269,   108,   271,   905,   108,   109,
     110,   111,   279,   113,   114,   115,   116,   187,   188,   269,
     199,   200,   201,   202,   239,   251,   241,   242,   195,   279,
     264,   968,   861,   198,   228,   229,   230,   231,   232,   273,
     341,   122,   236,  1190,   125,   178,   111,   267,   826,   826,
     826,   826,    92,   264,    94,    95,   826,   200,   826,   253,
     194,   226,   256,   103,   197,   198,   267,   210,    92,   270,
      94,    95,   270,   267,   269,   167,   168,   169,   278,   103,
     469,   121,   122,   123,   279,   125,   126,     5,   279,   279,
     479,   480,   481,   264,   186,   260,  1055,   121,   122,   123,
       0,   125,   126,   282,   283,   195,   196,   269,   868,   723,
     269,  1070,  1049,   165,   166,   277,   876,   744,   878,   508,
     197,   198,   174,   512,   167,   168,   169,   656,   688,   519,
     243,   266,   245,   278,   506,   270,   133,   240,   510,   511,
     510,   244,   531,   140,   143,   119,   120,   121,   538,   148,
     952,   980,   126,   199,   200,   201,   202,  1055,   270,   264,
     128,   274,   130,   131,   264,   277,   209,   210,   211,   212,
     213,   270,  1070,   104,   105,   106,   107,   275,   277,   292,
     293,  1140,   295,    83,    84,    85,    86,    87,    88,    89,
      90,   269,    92,    93,    94,   170,   171,   172,   173,    99,
     100,   264,   102,   103,    91,   223,   181,   225,   226,    96,
     228,     5,   230,   407,   264,   328,   329,   330,     6,   332,
     333,   334,   127,   264,   129,   125,   272,   132,   178,   342,
     270,   271,   119,   120,   121,   122,   282,   283,   127,   126,
     129,   272,  1140,   132,   804,   264,   270,   167,   168,   169,
     264,    35,   641,  1082,    38,   449,   269,   646,   271,  1028,
     190,   191,   192,   193,   653,   654,   379,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   278,   247,   248,   839,   250,   841,   209,
     210,   211,   212,   213,   214,   215,  1125,   121,   122,   176,
     177,  1130,   126,   165,   166,   244,   245,   246,   170,   171,
     172,   173,   178,   170,   171,   172,   173,   706,   180,   708,
     269,   264,   271,   712,   186,   182,   183,   184,   185,   186,
     277,   197,   198,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   119,
     120,   121,   122,   269,   186,   271,   126,   470,   165,   166,
     473,   205,   206,   207,   208,   478,   175,   561,   199,   200,
     201,   202,   485,   177,   487,   108,   109,   110,   111,   277,
     113,   114,   115,   116,  1159,  1162,  1164,  1163,   269,   277,
     271,  1161,  1160,   269,   277,   271,   509,   197,   198,   269,
     513,   271,   515,   597,   231,   232,  1235,   520,   269,   189,
     271,    83,    84,    85,    86,    87,    88,    89,    90,   532,
      92,    93,    94,   269,   269,   271,   271,    99,   100,   542,
     102,   103,   258,   259,   260,   261,   262,   263,  1267,   187,
     876,  1270,   878,   556,   282,   283,   559,   252,   253,   254,
     255,   256,   257,   125,   216,   217,   218,   219,   220,   221,
     222,  1290,   732,   181,   734,   578,  1056,  1296,  1058,  1298,
     310,   311,   306,   307,   269,   277,  1029,   280,  1307,   269,
     674,   277,   274,   272,   277,   276,   269,   264,   682,   174,
     181,   278,   198,   606,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   617,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   327,   716,   277,   637,   217,   272,   264,   264,   642,
     643,   273,   277,   277,   647,   264,   277,   650,   651,   264,
     278,   269,   655,   277,   198,   269,   269,   269,   267,   269,
     178,   272,   269,   269,   269,   269,   750,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   277,   272,   277,   707,   269,   269,   273,   269,   269,
     269,   269,   715,   269,   798,   269,   269,   269,   269,   284,
     186,   724,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     277,   269,   826,   269,   269,   269,  1165,   269,   269,   269,
     753,   266,   269,   269,   838,   269,   269,   269,   277,   186,
     269,   269,   273,   766,   767,   269,   269,   269,   269,   269,
     264,   277,   271,   271,   271,   471,   269,   861,   269,   269,
     269,   273,   269,   269,    20,   869,   269,   272,   272,   277,
     272,   269,   272,   796,   269,   269,   277,   269,   801,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   277,   514,   277,
     277,   905,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   938,   273,   264,   264,   277,   269,   269,
     924,   277,   264,   269,   277,   541,   271,   931,   271,   852,
     271,   269,   269,   856,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,  1109,   716,   565,
     272,   272,   269,   266,   269,   267,   879,   277,   277,   277,
     269,   277,   269,   277,   968,   888,   269,   269,   269,   277,
     270,   270,   270,   270,   978,   270,   270,   269,   901,   269,
     269,   269,   273,   111,   277,   270,   602,   273,   604,   273,
     277,   607,   608,   609,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     272,   269,   273,   272,   277,   269,   273,   269,   269,   272,
     270,   277,   277,   639,   270,   948,   269,   269,   277,   277,
     277,   269,   277,   277,   269,   269,   652,   277,   277,   269,
     277,   277,   273,   269,   277,  1049,   269,   269,   971,   277,
     973,  1055,   277,   277,   271,   271,   271,   277,   269,   277,
     269,   269,   272,   277,   269,   269,  1070,   269,   725,   269,
     993,   269,   408,   689,   277,   691,   277,   693,   277,   273,
     277,   697,   277,   699,   277,   269,   277,   269,   273,   269,
     273,   277,   269,   709,   234,   273,   277,   713,   277,   273,
     660,   277,   277,   216,   277,  1109,   277,   277,   277,  1029,
     222,   976,   839,   729,   486,   902,  1049,   733,   429,   628,
     510,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   745,
     371,    -1,    -1,   749,    -1,    -1,  1140,    -1,    -1,    -1,
     308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   770,  1159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   787,    -1,   789,    -1,    -1,    -1,   793,    -1,   795,
      -1,    -1,    -1,   799,    -1,  1189,   802,   803,    -1,   805,
     806,   807,    -1,    -1,    -1,   811,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   847,    -1,    -1,    -1,  1239,    -1,   853,    -1,    -1,
      -1,    -1,   858,   859,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   871,   872,    -1,   874,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   890,   891,    -1,   893,    -1,   895,
      -1,   897,   898,   899,    -1,    -1,   902,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   912,   913,    -1,    -1,
      -1,    -1,    -1,    -1,   920,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   942,    -1,   944,   945,
     946,   947,    -1,    -1,   950,   951,   952,   953,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   968,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,
     986,    -1,   988,    -1,    -1,    -1,   992,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1000,    -1,    -1,  1003,  1004,  1005,
    1006,  1007,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1032,    -1,    -1,    -1,
      -1,  1037,  1038,    -1,    -1,    -1,    -1,  1043,  1044,    -1,
      -1,    -1,  1048,  1049,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1057,    -1,    -1,    -1,    -1,    -1,  1063,    -1,    -1,
    1066,    -1,    -1,    -1,    -1,    -1,  1072,    -1,    -1,    -1,
      -1,    -1,    -1,  1079,  1080,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1088,  1089,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1111,    -1,  1113,  1114,  1115,
    1116,    -1,    -1,  1119,  1120,  1121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1143,    -1,    -1,
      -1,    -1,    -1,    -1,  1150,    -1,    -1,    -1,  1154,  1155,
    1156,  1157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1167,    -1,    -1,    -1,    -1,  1172,  1173,    -1,    -1,
      -1,  1177,  1178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1186,    -1,    -1,    -1,  1190,    -1,  1192,    -1,    -1,    -1,
      -1,  1197,  1198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1220,    -1,  1222,    -1,    -1,    -1,
    1226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,
    1246,  1247,    -1,    -1,    -1,  1251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1261,    -1,    -1,    -1,  1265,
    1266,    -1,    -1,    -1,    -1,  1271,    -1,  1273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1281,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1293,    -1,    -1,
       4,    -1,    -1,    -1,  1300,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,    73,
      74,    75,    -1,    77,    78,     4,    80,    81,    82,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    -1,    72,    73,    74,    75,    -1,    77,    78,
       4,    80,    81,    82,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,    73,
      74,    75,    -1,    77,    78,    -1,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   265,   266,   267,   268,    -1,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,   266,   267,   268,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,
      -1,    -1,   281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   265,   266,   267,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,   279,    -1,   281,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    -1,    77,    78,     4,    80,
      81,    82,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      -1,    77,    78,     4,    80,    81,    82,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    -1,    77,    78,    -1,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   265,   266,   267,   268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,   266,   267,   268,     4,   270,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      -1,    77,    78,     4,    80,    81,    82,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    -1,    77,    78,     4,    80,
      81,    82,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      -1,    77,    78,    -1,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,
     266,   267,   268,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,   268,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
     266,   267,   268,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    -1,    77,    78,     4,    80,
      81,    82,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      -1,    77,    78,     4,    80,    81,    82,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    -1,    77,    78,    -1,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,   268,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   268
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    83,    84,    85,    86,    87,    88,    89,    90,    92,
      93,    94,    99,   100,   102,   103,   125,   286,   287,   288,
     289,   290,   291,   292,   312,   313,   336,   338,   339,   340,
     341,   343,   344,   345,   361,   362,   363,   364,   366,   367,
     380,   384,   264,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   306,   307,   308,   309,   310,   311,
     267,   264,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   197,   198,
     318,   319,   321,   322,   335,     0,   288,   270,   352,   278,
     350,   356,   365,   277,   352,    91,    96,   119,   120,   121,
     122,   126,   342,   358,   382,   178,   319,   322,   325,   328,
       5,   269,   319,     4,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    72,    73,    74,    75,
      77,    78,    80,    81,    82,   268,   293,   333,   385,     3,
       7,     8,    95,   123,   336,   352,   368,   369,   370,   380,
     383,   386,   387,   388,   397,   398,   399,   411,   122,   125,
     346,   347,   354,   104,   105,   106,   107,   371,   372,   375,
     376,   377,   378,   379,   271,   353,   370,   293,   328,   328,
     127,   129,   132,   278,   348,   355,   357,   264,   124,   322,
     325,   327,   319,   325,   319,   322,   293,   269,   337,   310,
     275,   269,   277,   334,     6,   195,   196,   297,   264,     5,
     370,   353,   369,   121,   122,   126,   381,   328,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,   417,   418,   419,   420,   422,   427,   428,   429,   430,
     432,   439,   442,   443,   444,   446,   450,   452,   453,   454,
     458,   459,   460,   461,   466,   468,   473,   474,   475,   479,
     480,   484,   485,   487,   489,   492,   495,   497,   498,   499,
     500,   501,   502,   506,   507,   508,   510,   511,   514,   515,
     520,   521,   523,   526,   529,   530,   531,   536,   537,   540,
     542,   543,   548,   549,   550,   551,   555,   328,   269,   279,
     351,   264,   264,   264,   306,   373,   374,   264,   374,   377,
     297,   353,   293,   293,   293,   293,   293,   354,   293,   359,
     119,   120,   121,   126,   326,   325,   322,   325,   325,   319,
     322,   319,   272,   329,   330,   264,   264,   293,   278,   392,
     293,   295,   264,   277,   353,   293,   165,   166,   170,   171,
     172,   173,   180,   186,   412,   414,   423,   424,   481,   482,
     483,   319,   481,   496,   174,   425,   426,   481,   486,   170,
     187,   188,   469,   470,   471,   472,   481,   488,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   423,   516,   517,   522,
     319,   423,   517,   524,   319,   424,   319,   175,   476,   477,
     478,   182,   183,   184,   185,   413,   414,   415,   424,   462,
     463,   464,   465,   119,   120,   121,   122,   126,   194,   314,
     315,   315,   478,   192,   233,   547,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   541,   547,   547,   541,
     177,   431,   176,   431,   438,   431,   277,   277,   277,   216,
     217,   218,   219,   220,   221,   222,   532,   533,   478,   315,
     449,   315,   177,   203,   204,   251,   552,   553,   128,   130,
     131,   490,   491,   264,   265,   266,   267,   281,   293,   402,
     403,   407,   319,   319,   319,   189,   451,   319,   319,   319,
     258,   259,   260,   261,   262,   263,   534,   535,   190,   191,
     192,   193,   538,   539,   247,   248,   250,   455,   315,   231,
     232,   505,   205,   206,   207,   208,   527,   528,   297,   319,
     187,   421,   424,   424,   181,   414,   416,   441,   181,   440,
     445,   483,   319,   170,   187,   509,   293,   347,   269,   280,
     269,   330,   330,   277,   277,   277,   279,   349,   356,   264,
     273,   272,   274,   331,   332,   269,   276,   279,   346,   390,
     391,   293,   269,   277,   264,   330,   426,   181,   424,   319,
     407,   319,   426,   319,   424,   424,   424,   319,   440,   319,
     517,   167,   168,   169,   424,   518,   519,   319,   517,   524,
     517,   424,   519,   319,   407,   319,   270,   407,   410,   315,
     316,   319,   425,   424,   319,   315,   133,   140,   317,   320,
     407,   319,   533,   319,   533,   167,   168,   169,   209,   210,
     211,   212,   213,   512,   513,   319,   293,   389,   409,   278,
     435,   277,   407,   198,   319,   167,   168,   169,   209,   210,
     211,   212,   213,   214,   215,   447,   448,   513,   143,   148,
     554,   277,   293,   199,   200,   201,   202,   400,   401,   407,
     252,   253,   254,   255,   256,   257,   503,   504,   407,   319,
     407,   407,   407,   319,   217,   456,   513,   505,   272,   319,
     407,   424,   319,   319,   424,   319,   319,   319,   407,   424,
     424,   319,   330,   264,   264,   373,   277,   277,   277,   360,
     273,   264,   277,   264,   266,   267,   270,   293,   296,   298,
     299,   300,   301,   302,   303,   304,   305,   264,   318,   269,
     279,   278,   396,   293,   277,   426,   407,   269,   407,   407,
     407,   407,   424,   319,   407,   525,   424,   525,   269,   319,
     295,   269,   223,   225,   226,   228,   230,   544,   545,   272,
     425,   319,   320,   407,   269,   410,   545,   407,   545,   533,
     407,   277,   406,   407,   433,   434,   293,   277,   319,   410,
     319,   319,   407,   269,   407,   269,   407,   269,   269,   269,
     407,   198,   407,   457,   319,   272,   293,   403,   404,   405,
     408,   525,   269,   319,   407,   407,   426,   407,   407,   407,
     269,   407,   269,   273,   270,   296,   298,   300,   301,   303,
     304,   269,   269,   269,   293,   294,   390,   279,   346,   394,
     395,   277,   269,   407,   269,   269,   269,   269,   319,   407,
     284,   269,   319,   269,   407,   407,   271,   293,   405,   410,
     493,   494,   321,   323,   324,   408,   407,   407,   269,   407,
     269,   323,   269,   323,   319,   269,   269,   279,   269,   437,
     319,   269,   407,   407,   269,   407,   269,   407,   269,   407,
     407,   407,   269,   319,   457,   277,   408,   282,   283,   273,
     269,   407,   407,   269,   269,   269,   269,   269,   407,   269,
     264,   296,   298,   300,   301,   303,   304,   271,   271,   271,
     271,   271,   271,   264,   293,   267,   266,   325,   393,   269,
     279,   407,   269,   407,   407,   407,   407,   319,   269,   407,
     407,   525,   407,   269,   269,   272,   277,   273,   269,   269,
     293,   405,   407,   467,   277,   272,   319,   272,   319,   244,
     245,   246,   546,   272,   433,   269,   278,   293,   277,   410,
     272,   269,   269,   407,   277,   407,   277,   407,   277,   269,
     269,   407,   319,   273,   264,   264,   277,   407,   269,   269,
     407,   407,   407,   407,   407,   277,   407,   271,   271,   271,
     271,   271,   271,   269,   269,   269,   269,   269,   269,   318,
     394,   269,   407,   269,   269,   269,   269,   407,   407,   269,
     269,   269,   407,   407,   264,   269,   407,   467,   277,   408,
     546,   407,   546,   272,   407,   279,   406,   436,   269,   408,
     272,   407,   277,   269,   277,   407,   407,   277,   410,   277,
     269,   407,   407,   277,   269,   269,   269,   269,   277,   270,
     270,   270,   270,   270,   270,   294,   407,   269,   407,   407,
     407,   407,   269,   269,   407,   407,   407,   269,   269,   273,
     410,   277,   277,   273,   410,   273,   272,   407,   273,   269,
     269,   279,   272,   273,   408,   277,   407,   269,   269,   269,
     407,   277,   277,   407,   407,   407,   407,   296,   270,   298,
     300,   270,   301,   303,   270,   304,   330,   277,   407,   277,
     269,   277,   269,   407,   407,   277,   269,   277,   407,   407,
     277,   277,   269,   277,   407,   269,   277,   293,   406,   269,
     407,   277,   273,   269,   407,   407,   272,   269,   277,   277,
     277,   269,   271,   271,   271,   271,   271,   271,   277,   407,
     407,   269,   277,   407,   277,   269,   272,   269,   410,   293,
     269,   269,   407,   269,   277,   407,   407,   407,   277,   277,
     407,   269,   407,   407,   410,   273,   410,   407,   277,   407,
     269,   277,   277,   269,   407,   277,   269,   273,   269,   273,
     269,   277,   277,   410,   407,   277,   410,   269,   410,   277,
     407,   273,   277,   273,   410,   277,   277,   277,   277,   277
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   285,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   288,   288,   288,   288,   288,   289,
     289,   290,   290,   290,   290,   290,   290,   290,   290,   291,
     292,   293,   293,   293,   294,   294,   295,   295,   296,   296,
     296,   297,   297,   296,   298,   298,   299,   299,   299,   299,
     300,   300,   301,   301,   302,   302,   302,   302,   303,   303,
     304,   304,   305,   305,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   306,   307,   308,   308,   309,   309,   309,
     310,   311,   311,   311,   312,   313,   314,   314,   314,   314,
     314,   315,   316,   316,   317,   317,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   319,   320,   321,   321,   322,   323,   324,   324,
     325,   326,   326,   326,   326,   327,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   329,   329,
     329,   330,   330,   331,   332,   331,   331,   331,   333,   333,
     334,   333,   335,   335,   336,   337,   337,   338,   339,   340,
     341,   342,   342,   343,   344,   345,   346,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   354,   354,   355,   356,
     357,   357,   358,   359,   360,   360,   361,   362,   363,   364,
     365,   365,   366,   367,   367,   367,   368,   368,   368,   368,
     368,   368,   369,   369,   369,   369,   370,   370,   371,   372,
     372,   372,   373,   374,   374,   375,   375,   376,   376,   377,
     377,   377,   377,   378,   378,   379,   379,   380,   380,   380,
     380,   381,   381,   381,   382,   382,   383,   384,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   386,
     387,   388,   389,   390,   391,   391,   392,   392,   392,   393,
     393,   394,   395,   395,   396,   396,   397,   398,   399,   399,
     400,   400,   400,   400,   401,   401,   402,   402,   403,   403,
     403,   403,   404,   405,   405,   406,   407,   407,   408,   408,
     408,   409,   410,   410,   411,   411,   411,   412,   412,   412,
     412,   413,   413,   413,   413,   414,   415,   416,   416,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   418,   418,   418,   418,   418,   418,
     418,   419,   420,   420,   420,   420,   420,   421,   422,   423,
     424,   424,   425,   426,   426,   427,   427,   428,   429,   429,
     430,   431,   431,   432,   433,   434,   434,   435,   435,   436,
     436,   437,   437,   437,   437,   437,   437,   438,   438,   432,
     439,   440,   440,   441,   441,   442,   442,   443,   444,   444,
     445,   446,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   448,   449,   449,   450,   450,   451,   451,   452,
     453,   454,   455,   455,   455,   456,   456,   457,   457,   458,
     459,   460,   461,   462,   463,   464,   464,   465,   465,   465,
     465,   466,   467,   467,   468,   468,   469,   470,   471,   471,
     472,   472,   472,   473,   474,   475,   476,   477,   477,   478,
     479,   480,   481,   481,   482,   482,   482,   483,   483,   483,
     484,   484,   485,   486,   486,   487,   488,   489,   490,   490,
     490,   491,   492,   493,   494,   494,   494,   495,   496,   496,
     497,   498,   499,   499,   500,   501,   502,   503,   503,   503,
     503,   503,   503,   504,   504,   505,   505,   506,   507,   508,
     509,   509,   509,   510,   510,   511,   512,   512,   512,   512,
     512,   512,   512,   512,   513,   514,   515,   515,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   517,   518,   518,   518,
     519,   520,   521,   522,   522,   523,   523,   524,   524,   525,
     525,   526,   526,   526,   527,   527,   527,   527,   528,   529,
     530,   531,   532,   532,   532,   532,   532,   532,   532,   533,
     534,   534,   534,   534,   534,   534,   535,   536,   537,   538,
     538,   538,   538,   539,   540,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   542,   543,   544,   544,   544,
     544,   544,   545,   545,   546,   546,   546,   547,   547,   548,
     549,   550,   551,   552,   552,   552,   552,   553,   554,   554,
     555
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     1,     1,     3,     1,     3,
       1,     0,     1,     3,     7,     7,     1,     3,     3,     1,
       1,     3,     7,     7,     1,     3,     3,     1,     1,     3,
       7,     7,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     1,     2,     2,     2,     1,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     3,     4,
       2,     0,     1,     0,     1,     2,     2,     2,     1,     4,
       1,     3,     2,     1,     4,     0,     4,     4,     6,     6,
       6,     1,     1,     5,     5,     5,     1,     1,     4,     1,
       1,     1,     1,     1,     2,     1,     0,     3,     3,     3,
       1,     0,     1,     1,     1,     0,     6,     5,     4,     3,
       1,     0,     3,     4,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     2,     2,     2,
       4,     6,     3,     1,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     0,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     3,     1,     3,     3,     2,     0,     0,
       1,     5,     1,     3,     3,     2,     6,     4,     2,     3,
       1,     1,     1,     1,     1,     0,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     8,     1,     1,     1,     1,     1,     1,     8,     1,
       1,     0,     1,     1,     0,     1,     1,     7,     1,     1,
       9,     0,     1,     4,     1,     1,     3,     4,     0,     1,
       3,     6,     5,     2,     4,     3,     0,     1,     1,     1,
       6,     1,     0,     1,     3,     1,     1,     9,     1,     1,
       1,     9,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,    12,    14,     1,     0,    10,
      12,     7,     1,     1,     1,     2,     0,     2,     0,     5,
       6,     2,     6,     1,     1,     1,     1,     3,     2,     2,
       1,     8,     1,     1,     7,     8,     2,     2,     2,     0,
       1,     1,     1,     9,     2,     6,     1,     1,     0,     4,
       9,     9,     1,     1,     1,     1,     1,     3,     2,     2,
       1,     1,    11,     1,     2,    11,     2,    11,     1,     1,
       1,     1,     3,     4,     1,     1,     1,     6,     0,     1,
       9,     9,     1,     1,     6,     2,     6,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     7,     6,    11,
       2,     0,     2,     1,     1,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    10,    10,     2,     2,    10,    14,     2,     2,     3,
       1,     9,     9,    13,     1,     1,     1,     1,     1,    11,
      12,     9,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,    13,     1,
       1,     1,     1,     1,    14,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     9,     9,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,    15,
      15,    14,     2,     1,     1,     1,     1,     1,     1,     1,
       7
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
      yyerror (&yylloc, lexer, state, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
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
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, lexer, state); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, parser::PTXLexer& lexer, parser::PTXParser::State& state)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (lexer);
  YYUSE (state);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, parser::PTXLexer& lexer, parser::PTXParser::State& state)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, lexer, state);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, parser::PTXLexer& lexer, parser::PTXParser::State& state)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , lexer, state);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, lexer, state); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, parser::PTXLexer& lexer, parser::PTXParser::State& state)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (lexer);
  YYUSE (state);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (parser::PTXLexer& lexer, parser::PTXParser::State& state)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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
      yychar = yylex (&yylval, &yylloc, lexer, state);
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
     '$$ = $1'.

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
        case 13:
#line 156 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.statementEnd( (yylsp[0]) );
}
#line 3108 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 170 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.preprocessor( (yyvsp[0].value) );
}
#line 3116 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 175 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    { 
	state.version( (yyvsp[0].doubleFloat), (yylsp[0]) );
}
#line 3124 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 183 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.identifierList( (yyvsp[0].text) );
}
#line 3132 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 188 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.identifierList2( (yyvsp[0].text) );
}
#line 3140 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.decimalListSingle( 0 );
	state.symbolListSingle( (yyvsp[0].text) );
}
#line 3149 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 199 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.decimalListSingle2( 0 );
	state.symbolListSingle2( (yyvsp[0].text) );
}
#line 3158 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 205 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.decimalListSingle( (yyvsp[0].value) );
}
#line 3166 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 210 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
    state.metadata("");
}
#line 3174 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 215 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
    state.metadata( (yyvsp[0].text) );
}
#line 3182 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 220 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.decimalListSingle2( (yyvsp[0].value) );
}
#line 3190 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 231 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.floatList( (yyvsp[0].doubleFloat) );
}
#line 3198 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.floatList1( (yyvsp[0].doubleFloat) );
}
#line 3206 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 247 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.singleList( (yyvsp[0].singleFloat) );
}
#line 3214 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 252 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.singleList1( (yyvsp[0].singleFloat) );
}
#line 3222 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 270 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.targetElement( (yyvsp[0].value) );
}
#line 3230 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 278 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.target();
}
#line 3238 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 283 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.addressSize( (yyvsp[0].value) );
}
#line 3246 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 291 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.addressSpace( (yyvsp[0].value) );
}
#line 3254 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.noAddressSpace();
}
#line 3262 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 308 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.dataType( (yyvsp[0].value) );
}
#line 3270 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 313 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.dataType( (yyvsp[0].value) );
}
#line 3278 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 320 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.statementVectorType( (yyvsp[0].value) );
}
#line 3286 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 325 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instructionVectorType( (yyvsp[0].value) );
}
#line 3294 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 332 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    { state.alignment = (yyvsp[0].value); }
#line 3300 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 336 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.paramArgumentDeclaration((yyvsp[0].value));
}
#line 3308 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 340 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {state.alignment = 1;}
#line 3314 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 341 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {state.alignment = 1;}
#line 3320 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 342 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    { state.alignment = 1; }
#line 3326 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 354 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.arrayDimensionSet( (yyvsp[-1].value), (yylsp[-1]), false );
}
#line 3334 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 359 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.arrayDimensionSet( (yyvsp[-1].value), (yylsp[-1]), true );
}
#line 3342 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 364 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.arrayDimensionSet( );
}
#line 3350 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 369 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.arrayDimensions();
}
#line 3358 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 378 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.assignment();
}
#line 3366 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 386 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.registerDeclaration( (yyvsp[0].text), (yylsp[0]) );
}
#line 3374 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 391 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.registerDeclaration( (yyvsp[-3].text), (yylsp[-3]), (yyvsp[-1].value) );
}
#line 3382 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 396 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.registerSeperator( (yylsp[0]) );
}
#line 3390 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 401 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.registerDeclaration( (yyvsp[0].text), (yylsp[0]) );
}
#line 3398 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 416 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.fileDeclaration( (yyvsp[-2].value), (yyvsp[-1].text) );
}
#line 3406 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 422 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.locationAddress( (yyvsp[-4].value) );
	state.initializableDeclaration( (yyvsp[-2].text), (yylsp[-2]), (yylsp[0]) );
}
#line 3415 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 429 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.initializableDeclaration( (yyvsp[-3].text), (yylsp[-3]), (yylsp[-1]) );
	state.statementEnd( (yylsp[-3]) );
}
#line 3424 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 436 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.locationAddress( (yyvsp[-4].value) );
	state.initializableDeclaration( (yyvsp[-2].text), (yylsp[-2]), (yylsp[0]) );
}
#line 3433 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 444 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.textureDeclaration( (yyvsp[-3].value), (yyvsp[-1].text), (yylsp[-4]) );
}
#line 3441 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 449 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.samplerDeclaration( (yyvsp[-3].value), (yyvsp[-1].text), (yylsp[-4]) );
}
#line 3449 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 454 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.surfaceDeclaration( (yyvsp[-3].value), (yyvsp[-1].text), (yylsp[-4]) );
}
#line 3457 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 459 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.locationAddress( (yyvsp[0].value) );
}
#line 3465 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 464 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.locationAddress( (yyvsp[0].value) );
}
#line 3473 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 470 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.attribute( false, false, false );
	state.argumentDeclaration( (yyvsp[-1].text), (yylsp[-3]) );
}
#line 3482 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 476 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.returnArgumentListBegin( (yylsp[0]) );
}
#line 3490 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 481 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.returnArgumentListEnd( (yylsp[0]) );
}
#line 3498 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 486 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.argumentListBegin( (yylsp[0]) );
}
#line 3506 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 491 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.argumentListEnd( (yylsp[0]) );
}
#line 3514 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 496 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.openBrace( (yylsp[0]) );
}
#line 3522 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 501 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.closeBrace( (yylsp[-1]) );
}
#line 3530 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 516 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.functionBegin( (yylsp[0]) );
}
#line 3538 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 521 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.functionName( (yyvsp[0].text), (yylsp[0]) );
}
#line 3546 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 530 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.functionDeclaration( (yylsp[-2]), false );
}
#line 3554 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 536 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.functionDeclaration( (yylsp[-1]), true );
}
#line 3562 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 543 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.entry( (yyvsp[0].text), (yylsp[-2]) );
}
#line 3570 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 551 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.entryDeclaration( (yylsp[-2]) );
}
#line 3578 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 560 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.entryPrototype( (yylsp[-1]) );
}
#line 3586 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 570 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.statementEnd( (yylsp[0]) );
}
#line 3594 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 575 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.entryStatement( (yylsp[-1]) );
	state.instruction();
}
#line 3603 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 586 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.maxnreg( (yyvsp[0].value) );
}
#line 3611 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 591 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.maxntid( (yyvsp[0].value) );
}
#line 3619 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 596 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.maxntid( (yyvsp[-2].value), (yyvsp[0].value) );
}
#line 3627 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 602 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.maxntid( (yyvsp[-4].value), (yyvsp[-2].value), (yyvsp[0].value) );
}
#line 3635 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 607 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.ctapersm( (yyvsp[-2].value), (yyvsp[0].value) );
}
#line 3643 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 614 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.minnctapersm( (yyvsp[0].value) );
}
#line 3651 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 619 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.minnctapersm( );
}
#line 3659 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 624 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.maxnctapersm( (yyvsp[0].value) );
}
#line 3667 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 629 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.maxnctapersm();
}
#line 3675 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 639 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.attribute( false, false, true );
}
#line 3683 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 644 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.attribute( false, true, false );
}
#line 3691 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 649 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.attribute( true, false, false );
}
#line 3699 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 654 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.attribute( false, false, false );
}
#line 3707 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 662 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.locationAddress( (yyvsp[0].value) );
}
#line 3715 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 667 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.locationAddress( (yyvsp[0].value) );
}
#line 3723 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 690 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.uninitializableDeclaration( (yyvsp[-2].text) );
	state.statementEnd( (yylsp[-3]) );
}
#line 3732 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 697 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.location( (yyvsp[-2].value), (yyvsp[-1].value), (yyvsp[0].value) );
}
#line 3740 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 702 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.label( (yyvsp[-1].text) );
}
#line 3748 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 707 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.labelOperand( (yyvsp[0].text) );
}
#line 3756 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 712 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.returnType( (yyvsp[-1].value) );
}
#line 3764 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 724 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.argumentType( (yyvsp[-2].value) );
}
#line 3772 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 734 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.callPrototype( (yyvsp[-5].text), (yyvsp[-2].text), (yylsp[-5]) );
}
#line 3780 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 739 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.callTargets( (yyvsp[-3].text), (yylsp[-3]) );
}
#line 3788 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 744 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.pragma( (yyvsp[0].text) );
}
#line 3796 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 749 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.pragma( (yyvsp[-1].text) );
}
#line 3804 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 756 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.vectorIndex( (yyvsp[0].value) );
}
#line 3812 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 761 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {

}
#line 3820 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 766 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.nonLabelOperand( (yyvsp[-1].text), (yylsp[-1]), false );
}
#line 3828 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 771 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.nonLabelOperand( (yyvsp[0].text), (yylsp[-1]), true );
}
#line 3836 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 776 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.constantOperand( (yyvsp[0].value) );
}
#line 3844 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 781 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.constantOperand( (yyvsp[0].uvalue) );
}
#line 3852 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 786 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.constantOperand( (yyvsp[0].doubleFloat) );
}
#line 3860 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 791 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.constantOperand( (yyvsp[0].singleFloat) );
}
#line 3868 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 796 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.addressableOperand( (yyvsp[0].text), 0, (yylsp[0]), false );
}
#line 3876 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 801 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.addressableOperand( (yyvsp[-2].text), (yyvsp[0].value), (yylsp[-2]), false );
}
#line 3884 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 806 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.addressableOperand( (yyvsp[-2].text), (yyvsp[0].value), (yylsp[-2]), true );
}
#line 3892 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 819 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.arrayOperand( (yylsp[-2]) );
}
#line 3900 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 824 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.guard( (yyvsp[0].text), (yylsp[0]), false );
}
#line 3908 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 829 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.guard( (yyvsp[0].text), (yylsp[0]), true );
}
#line 3916 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 834 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.guard();
}
#line 3924 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 842 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 3932 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 847 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 3940 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 866 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-7].text), (yyvsp[-6].value) );
}
#line 3948 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 874 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 3956 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 880 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-7].text), (yyvsp[-4].value) );
}
#line 3964 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 885 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 3972 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 892 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 3980 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 902 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-6].text), (yyvsp[-4].value) );
}
#line 3988 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 910 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 3996 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 915 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.uni( false );
}
#line 4004 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 920 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.uni( true );
}
#line 4012 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 925 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-3].text) );
}
#line 4020 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 930 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.returnOperand();
}
#line 4028 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 943 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.callPrototypeName( (yyvsp[0].text) );
}
#line 4036 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 948 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.callPrototypeName( (yyvsp[0].text) );
}
#line 4044 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 953 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.callPrototypeName( (yyvsp[0].text) );
}
#line 4052 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 961 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.tail( true );
}
#line 4060 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 966 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.tail( false );
}
#line 4068 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 974 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.call( (yyvsp[-2].text), (yylsp[-5]) );
}
#line 4076 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 979 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.carry( true );
}
#line 4084 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 984 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.carry( false );
}
#line 4092 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 989 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.carry( true );
}
#line 4100 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 994 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.carry( false );
}
#line 4108 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 1002 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4116 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 1012 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.carryIn();
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4125 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 1021 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.atomic( (yyvsp[0].value) );
}
#line 4133 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 1027 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.addressSpace(TOKEN_GLOBAL);
}
#line 4141 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 1033 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-11].text), (yyvsp[-8].value) );
}
#line 4149 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 1039 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-13].text), (yyvsp[-10].value) );
}
#line 4157 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 1044 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.shiftAmount( true );
}
#line 4165 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 1049 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.shiftAmount( false );
}
#line 4173 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 1055 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-9].text), (yyvsp[-8].value) );
}
#line 4181 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 1061 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-11].text), (yyvsp[-10].value) );
}
#line 4189 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 1066 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-6].text), (yyvsp[-4].value) );
}
#line 4197 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 1071 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.barrierOperation( (yyvsp[0].value), (yylsp[0]) );
}
#line 4205 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 1080 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-4].text) );
}
#line 4213 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 1085 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-5].text), (yyvsp[-4].value) );
}
#line 4221 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 1090 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-1].text) );
}
#line 4229 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 1095 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-5].text), (yyvsp[-4].value) );
}
#line 4237 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 1100 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 4245 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 1105 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 4253 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 1117 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-7].text), (yyvsp[-5].value) );
	state.relaxedConvert( (yyvsp[-4].value), (yylsp[-7]) );
}
#line 4262 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 1125 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-6].text), (yyvsp[-4].value) );
}
#line 4270 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 1131 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-7].text), (yyvsp[-4].value) );
	state.cvtaTo();
}
#line 4279 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 1141 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.full();
}
#line 4287 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 1146 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier((yyvsp[-1].value));
}
#line 4295 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 1151 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier((yyvsp[-1].value));
}
#line 4303 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 1161 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4311 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 1166 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-1].text) );
}
#line 4319 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 1171 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-5].text), TOKEN_U32 );
}
#line 4327 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 1176 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.volatileFlag( true );
}
#line 4335 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 1183 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.volatileFlag( false );
}
#line 4343 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 1191 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4351 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 1196 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4359 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 1205 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[-2].value) );
	state.carry( false );
}
#line 4368 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 1211 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.carry( true );
}
#line 4376 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 1216 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.carry( false );
}
#line 4384 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 1224 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-10].text), (yyvsp[-8].value) );
}
#line 4392 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 1231 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[-1].value) );
}
#line 4400 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 1237 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-10].text), (yyvsp[-8].value) );
}
#line 4408 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 1242 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[-1].value) );
}
#line 4416 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 1248 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-10].text), (yyvsp[-8].value) );
}
#line 4424 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 561:
#line 1255 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.level( (yyvsp[0].value) );
}
#line 4432 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 562:
#line 1260 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-2].text) );
}
#line 4440 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 563:
#line 1265 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.indexedOperand( (yyvsp[-3].text), (yylsp[-3]), (yyvsp[-1].value) );
}
#line 4448 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 567:
#line 1272 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-5].text), (yyvsp[-4].value) );
}
#line 4456 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 569:
#line 1279 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[0].value) );
}
#line 4464 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 570:
#line 1284 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4472 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 571:
#line 1289 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4480 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 574:
#line 1296 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-5].text), (yyvsp[-4].value) );
}
#line 4488 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 575:
#line 1301 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-1].text) );
}
#line 4496 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 576:
#line 1306 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-5].text), (yyvsp[-4].value) );
}
#line 4504 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 583:
#line 1314 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.permute( (yyvsp[0].value) );
}
#line 4512 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 584:
#line 1319 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.defaultPermute();
}
#line 4520 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 586:
#line 1324 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.cacheLevel( (yyvsp[0].value) );
}
#line 4528 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 587:
#line 1329 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-6].text) );
}
#line 4536 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 588:
#line 1334 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-5].text) );
}
#line 4544 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 589:
#line 1340 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-10].text), (yyvsp[-9].value) );
}
#line 4552 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 590:
#line 1345 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[-1].value) );
}
#line 4560 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 592:
#line 1351 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.modifier( (yyvsp[-1].value) );
}
#line 4568 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 595:
#line 1359 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-6].text), (yyvsp[-4].value) );
}
#line 4576 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 604:
#line 1367 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.reduction( (yyvsp[0].value) );
}
#line 4584 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 605:
#line 1373 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-7].text), (yyvsp[-4].value) );
}
#line 4592 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 606:
#line 1378 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-2].text) );
}
#line 4600 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 607:
#line 1383 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-3].text) );
}
#line 4608 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 626:
#line 1392 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.comparison( (yyvsp[0].value) );
}
#line 4616 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 630:
#line 1399 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.boolean( (yyvsp[0].value) );
}
#line 4624 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 631:
#line 1404 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-9].text), (yyvsp[-8].value) );
}
#line 4632 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 632:
#line 1409 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-9].text), (yyvsp[-8].value) );
	state.operandCIsAPredicate();
}
#line 4641 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 635:
#line 1421 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-9].text), (yyvsp[-7].value) );
	state.convert( (yyvsp[-6].value), (yylsp[-9]) );
}
#line 4650 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 636:
#line 1428 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-13].text), (yyvsp[-9].value) );
	state.convert( (yyvsp[-8].value), (yylsp[-13]) );
}
#line 4659 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 641:
#line 1441 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4667 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 642:
#line 1447 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-7].value) );
}
#line 4675 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 643:
#line 1453 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-12].text), (yyvsp[-8].value) );
}
#line 4683 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 648:
#line 1460 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.shuffle( (yyvsp[0].value) );
}
#line 4691 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 649:
#line 1466 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-10].text), (yyvsp[-8].value) );
}
#line 4699 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 650:
#line 1472 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-11].text), (yyvsp[-9].value) );
	state.convertC( (yyvsp[-8].value), (yylsp[-11]) );
}
#line 4708 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 651:
#line 1478 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4716 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 659:
#line 1486 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.geometry( (yyvsp[0].value) );
}
#line 4724 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 666:
#line 1494 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.floatingPointMode( (yyvsp[0].value) );
}
#line 4732 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 667:
#line 1499 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-6].text), (yyvsp[-4].value) );
}
#line 4740 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 668:
#line 1505 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.tex( (yyvsp[-8].value) );
	state.convertD( (yyvsp[-9].value), (yylsp[-12]) );
}
#line 4749 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 673:
#line 1513 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.colorComponent( (yyvsp[0].value) );
}
#line 4757 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 674:
#line 1519 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.tld4( (yyvsp[-9].value) );
}
#line 4765 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 684:
#line 1531 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.surfaceQuery( (yyvsp[0].value) );
}
#line 4773 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 685:
#line 1536 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.surfaceQuery( (yyvsp[-7].value) );
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
}
#line 4782 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 686:
#line 1542 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-8].text), (yyvsp[-6].value) );
	state.surfaceQuery( (yyvsp[-7].value) );
}
#line 4791 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 691:
#line 1548 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.cacheOperation( (yyvsp[0].value) );
}
#line 4799 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 696:
#line 1555 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.clampOperation( (yyvsp[0].value) );
}
#line 4807 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 698:
#line 1560 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.formatMode( (yyvsp[0].value) );
}
#line 4815 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 699:
#line 1567 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-14].text), (yyvsp[-9].value) );
	state.formatMode( (yyvsp[-13].value) );
	state.clampOperation( (yyvsp[-8].value) );
}
#line 4825 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 700:
#line 1576 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-14].text), (yyvsp[-9].value) );
	state.formatMode( (yyvsp[-13].value) );
	state.clampOperation( (yyvsp[-8].value) );
}
#line 4835 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 701:
#line 1584 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-13].text), (yyvsp[-9].value) );
	state.formatMode( (yyvsp[-12].value) );
	state.clampOperation( (yyvsp[-8].value) );
}
#line 4845 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 702:
#line 1595 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-1].text) );
}
#line 4853 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 707:
#line 1602 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.vote( (yyvsp[0].value) );
}
#line 4861 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;

  case 710:
#line 1609 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1646  */
    {
	state.instruction( (yyvsp[-6].text), (yyvsp[-4].value) );
}
#line 4869 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
    break;


#line 4873 ".release_build/ptxgrammar.cpp" /* yacc.c:1646  */
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
      yyerror (&yylloc, lexer, state, YY_("syntax error"));
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
        yyerror (&yylloc, lexer, state, yymsgp);
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
                      yytoken, &yylval, &yylloc, lexer, state);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, lexer, state);
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
  yyerror (&yylloc, lexer, state, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, lexer, state);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, lexer, state);
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
#line 1613 "ocelot/parser/implementation/ptxgrammar.yy" /* yacc.c:1906  */


int yylex( YYSTYPE* token, YYLTYPE* location, parser::PTXLexer& lexer, 
	parser::PTXParser::State& state )
{
	lexer.yylval = token;
	
	int tokenValue         = lexer.yylexPosition();
	location->first_line   = lexer.lineno();
	location->first_column = lexer.column;
	
	report( " Lexer (" << location->first_line << ","
		<< location->first_column 
		<< "): " << parser::PTXLexer::toString( tokenValue ) << " \"" 
		<< lexer.YYText() << "\"");
	
	return tokenValue;
}

void yyerror( YYLTYPE* location, parser::PTXLexer& lexer, 
	parser::PTXParser::State& state, char const* message )
{
	parser::PTXParser::Exception exception;
	std::stringstream stream;
	stream << parser::PTXParser::toString( *location, state ) 
		<< " " << message;
	exception.message = stream.str();
	exception.error = parser::PTXParser::State::SyntaxError;
	throw exception;
}

}
