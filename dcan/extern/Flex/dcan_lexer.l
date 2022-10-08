%option yylineno
%option noyywrap
%option never-interactive
%option nounistd

%{
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cwchar>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include "dcan/Flex/Lexer.h"

#include "dcan/Ast/Enum/Type.h"

#include "dcan/Ast/Node/SINGLE_COMMENT.h"
#include "dcan/Ast/Node/MULTI_COMMENT.h"
#include "dcan/Ast/Node/CURRENT.h"
#include "dcan/Ast/Node/VOLTAGE.h"
#include "dcan/Ast/Node/RESISTANCE.h"
#include "dcan/Ast/Node/NODE.h"
#include "dcan/Ast/Node/IDEAL_SOURCE.h"
#include "dcan/Ast/Node/GROUND.h"
#include "dcan/Ast/Node/VARNAME.h"
#include "dcan/Ast/Node/NUMBER.h"
#include "dcan/Ast/Node/MIN.h"
#include "dcan/Ast/Node/EQ.h"
#include "dcan/Ast/Node/ESCAPE_CHARS.h"
#include "dcan/Ast/Node/program.h"
#include "dcan/Ast/Node/deamerreserved_star__stmt__.h"
#include "dcan/Ast/Node/stmt.h"
#include "dcan/Ast/Node/node_declaration.h"
#include "dcan/Ast/Node/ground_declaration.h"
#include "dcan/Ast/Node/source_declaration.h"
#include "dcan/Ast/Node/assignment.h"
#include "dcan/Ast/Node/unit_value.h"
#include "dcan/Ast/Node/current_value.h"
#include "dcan/Ast/Node/voltage_value.h"
#include "dcan/Ast/Node/resistance_value.h"
#include "dcan/Ast/Node/value.h"
#include "dcan/Ast/Node/connection.h"
#include "dcan/Ast/Node/deamerreserved_plus__MIN__component_name__.h"
#include "dcan/Ast/Node/component_name.h"
#include "dcan/Ast/Node/lhs_component_name.h"
#include "dcan/Ast/Node/rhs_component_name.h"
#include "dcan/Ast/Node/source_name.h"
#include "dcan/Ast/Node/ground_name.h"
#include "dcan/Ast/Node/node_name.h"


#include "Bison/dcan_parser.tab.h"
void showError();
extern int dcanlex();

static bool local_store     = false;
static bool include_deleted = false;

int dcan_column    = 1;
static int next_column = 1;

static std::size_t min(std::size_t a, std::size_t b);

static void handleColumn();
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> 
local_objects;


#ifndef yyval
#define yyval yytext
#endif // yyval
%}

SINGLE_COMMENT	([/][^\n\r]*[\n\r]{0,1})
MULTI_COMMENT	([/][*][^*]*[*][/]{0,1})
CURRENT	((([Cc][Uu][Rr][Rr][Ee][Nn][Tt])|([Ii])|([Aa])))
VOLTAGE	((([Vv][Oo][Ll][Tt][Aa][Gg][Ee])|([Uu])|([Vv])))
RESISTANCE	((([Rr][Ee][Ss][Ii][Ss][Tt][Aa][Nn][Cc][Ee])|([Rr])))
NODE	([Nn][Oo][Dd][Ee])
IDEAL_SOURCE	([Ss][Oo][Uu][Rr][Cc][Ee])
GROUND	([Gg][Rr][Oo][Uu][Nn][Dd])
VARNAME	([a-zA-Z_][a-zA-Z0-9_]*)
NUMBER	([-]{0,1}[0-9]+([\.][0-9]+){0,1})
MIN	([-])
EQ	([=])
ESCAPE_CHARS	([ \n\r\t\f\v\b]+)

DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH	(.)

%%

{SINGLE_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(1))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(1))); else if (local_store && true); else if (!true || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(1)); else if (false) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(1)); if ((!local_store && false) || (!local_store && include_deleted)) return (SINGLE_COMMENT); }
{MULTI_COMMENT}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(2))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(2))); else if (local_store && true); else if (!true || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(2)); else if (false) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(2)); if ((!local_store && false) || (!local_store && include_deleted)) return (MULTI_COMMENT); }
{CURRENT}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(3))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(3))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(3)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(3)); if ((!local_store && true) || (!local_store && include_deleted)) return (CURRENT); }
{VOLTAGE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(4))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(4))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(4)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(4)); if ((!local_store && true) || (!local_store && include_deleted)) return (VOLTAGE); }
{RESISTANCE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(5))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(5))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(5)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(5)); if ((!local_store && true) || (!local_store && include_deleted)) return (RESISTANCE); }
{NODE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(6))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(6))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(6)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(6)); if ((!local_store && true) || (!local_store && include_deleted)) return (NODE); }
{IDEAL_SOURCE}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(7))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(7))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(7)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(7)); if ((!local_store && true) || (!local_store && include_deleted)) return (IDEAL_SOURCE); }
{GROUND}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(8))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(8))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(8)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(8)); if ((!local_store && true) || (!local_store && include_deleted)) return (GROUND); }
{VARNAME}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(9))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(9))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(9)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(9)); if ((!local_store && true) || (!local_store && include_deleted)) return (VARNAME); }
{NUMBER}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(10))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(10))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(10)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(10)); if ((!local_store && true) || (!local_store && include_deleted)) return (NUMBER); }
{MIN}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(11))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(11))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(11)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(11)); if ((!local_store && true) || (!local_store && include_deleted)) return (MIN); }
{EQ}	{ handleColumn();  if (local_store && !false || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(12))); else if (local_store && true) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(12))); else if (local_store && false); else if (!false || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(12)); else if (true) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(12)); if ((!local_store && true) || (!local_store && include_deleted)) return (EQ); }
{ESCAPE_CHARS}	{ handleColumn();  if (local_store && !true || local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(13))); else if (local_store && false) store(new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(13))); else if (local_store && true); else if (!true || include_deleted) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(13)); else if (false) dcanlval.Terminal = new deamer::external::cpp::lexer::TerminalObject("", yylineno, dcan_column, std::size_t(13)); if ((!local_store && false) || (!local_store && include_deleted)) return (ESCAPE_CHARS); }

{DEAMER_RESERVED_UNRECOGNIZED_RULE_MATCH} { if (local_store && include_deleted) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, dcan_column, std::size_t(0))); }

%%

static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject)
{
	local_objects.push_back(newObject);
}

static void clear()
{
	local_objects.clear();
}

static void handleColumn()
{
	const std::string text = yytext;
	dcan_column = next_column;

	for (auto character : text)
	{
		next_column++;
		if (character == '\n')
		{
			next_column = 1;
		}
	}
}

static std::size_t min(std::size_t a, std::size_t b) {
    if (b < a)
	{
		return b;
	}
	else
	{
		return a;
	}
}

std::vector<const ::deamer::external::cpp::lexer::TerminalObject*> dcan::flex::lexer::Lexer::Tokenize(const std::string& text, ::deamer::external::cpp::lexer::TerminalConstructionPolicy constructionPolicy) const
{
	if (constructionPolicy == ::deamer::external::cpp::lexer::TerminalConstructionPolicy::include_deleted_terminals)
	{
		include_deleted = true;
	}
	else
	{
		include_deleted = false;
	}

	local_store = true;
	dcan_column = 0;

	YY_BUFFER_STATE buf;
	buf = yy_scan_string(text.c_str());
	yylex();
	yy_delete_buffer(buf);
	yylex_destroy();

	local_store = false;
	include_deleted = false;

	auto local_objects_copy = local_objects;
	clear();

	return local_objects_copy;
}