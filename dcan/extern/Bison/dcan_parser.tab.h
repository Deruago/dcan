/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_DCAN_DCAN_PARSER_TAB_H_INCLUDED
# define YY_DCAN_DCAN_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int dcandebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SINGLE_COMMENT = 258,          /* SINGLE_COMMENT  */
    MULTI_COMMENT = 259,           /* MULTI_COMMENT  */
    CURRENT = 260,                 /* CURRENT  */
    VOLTAGE = 261,                 /* VOLTAGE  */
    RESISTANCE = 262,              /* RESISTANCE  */
    NODE = 263,                    /* NODE  */
    IDEAL_SOURCE = 264,            /* IDEAL_SOURCE  */
    GROUND = 265,                  /* GROUND  */
    VARNAME = 266,                 /* VARNAME  */
    NUMBER = 267,                  /* NUMBER  */
    MIN = 268,                     /* MIN  */
    EQ = 269,                      /* EQ  */
    ESCAPE_CHARS = 270             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 112 "./dcan_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::dcan::ast::node::SINGLE_COMMENT* dcan_SINGLE_COMMENT;
	::dcan::ast::node::MULTI_COMMENT* dcan_MULTI_COMMENT;
	::dcan::ast::node::CURRENT* dcan_CURRENT;
	::dcan::ast::node::VOLTAGE* dcan_VOLTAGE;
	::dcan::ast::node::RESISTANCE* dcan_RESISTANCE;
	::dcan::ast::node::NODE* dcan_NODE;
	::dcan::ast::node::IDEAL_SOURCE* dcan_IDEAL_SOURCE;
	::dcan::ast::node::GROUND* dcan_GROUND;
	::dcan::ast::node::VARNAME* dcan_VARNAME;
	::dcan::ast::node::NUMBER* dcan_NUMBER;
	::dcan::ast::node::MIN* dcan_MIN;
	::dcan::ast::node::EQ* dcan_EQ;
	::dcan::ast::node::ESCAPE_CHARS* dcan_ESCAPE_CHARS;
	::dcan::ast::node::program* dcan_program;
	::dcan::ast::node::deamerreserved_star__stmt__* dcan_deamerreserved_star__stmt__;
	::dcan::ast::node::stmt* dcan_stmt;
	::dcan::ast::node::node_declaration* dcan_node_declaration;
	::dcan::ast::node::ground_declaration* dcan_ground_declaration;
	::dcan::ast::node::source_declaration* dcan_source_declaration;
	::dcan::ast::node::assignment* dcan_assignment;
	::dcan::ast::node::unit_value* dcan_unit_value;
	::dcan::ast::node::current_value* dcan_current_value;
	::dcan::ast::node::voltage_value* dcan_voltage_value;
	::dcan::ast::node::resistance_value* dcan_resistance_value;
	::dcan::ast::node::value* dcan_value;
	::dcan::ast::node::connection* dcan_connection;
	::dcan::ast::node::deamerreserved_plus__MIN__component_name__* dcan_deamerreserved_plus__MIN__component_name__;
	::dcan::ast::node::component_name* dcan_component_name;
	::dcan::ast::node::lhs_component_name* dcan_lhs_component_name;
	::dcan::ast::node::rhs_component_name* dcan_rhs_component_name;
	::dcan::ast::node::source_name* dcan_source_name;
	::dcan::ast::node::ground_name* dcan_ground_name;
	::dcan::ast::node::node_name* dcan_node_name;


#line 117 "dcan_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE dcanlval;


int dcanparse (void);


#endif /* !YY_DCAN_DCAN_PARSER_TAB_H_INCLUDED  */
