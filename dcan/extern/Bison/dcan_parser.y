%define parse.error verbose
%define parse.lac full


%{
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "dcan/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/dcan_lexer.h"
#undef YY_NO_UNISTD_H
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


#ifndef YY_parse_NERRS
#define YY_parse_NERRS dcannerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC dcanlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE 1



void dcanerror(const char* s);
int dcanlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

extern int dcanlineno;
extern int dcan_column;

static const std::string* dcan_input_text = nullptr;
%}

%token<Terminal> SINGLE_COMMENT
%token<Terminal> MULTI_COMMENT
%token<Terminal> CURRENT
%token<Terminal> VOLTAGE
%token<Terminal> RESISTANCE
%token<Terminal> NODE
%token<Terminal> IDEAL_SOURCE
%token<Terminal> GROUND
%token<Terminal> VARNAME
%token<Terminal> NUMBER
%token<Terminal> MIN
%token<Terminal> EQ
%token<Terminal> ESCAPE_CHARS


%nterm<dcan_program> program
%nterm<dcan_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<dcan_stmt> stmt
%nterm<dcan_node_declaration> node_declaration
%nterm<dcan_ground_declaration> ground_declaration
%nterm<dcan_source_declaration> source_declaration
%nterm<dcan_assignment> assignment
%nterm<dcan_unit_value> unit_value
%nterm<dcan_current_value> current_value
%nterm<dcan_voltage_value> voltage_value
%nterm<dcan_resistance_value> resistance_value
%nterm<dcan_value> value
%nterm<dcan_connection> connection
%nterm<dcan_deamerreserved_plus__MIN__component_name__> deamerreserved_plus__MIN__component_name__
%nterm<dcan_component_name> component_name
%nterm<dcan_lhs_component_name> lhs_component_name
%nterm<dcan_rhs_component_name> rhs_component_name
%nterm<dcan_source_name> source_name
%nterm<dcan_ground_name> ground_name
%nterm<dcan_node_name> node_name


%union{
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

}

%%


program:
	deamerreserved_star__stmt__  {
		auto* const newNode = new dcan::ast::node::program({::dcan::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new dcan::ast::node::deamerreserved_star__stmt__({::dcan::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new dcan::ast::node::deamerreserved_star__stmt__({::dcan::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	node_declaration  {
		auto* const newNode = new dcan::ast::node::stmt({::dcan::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| ground_declaration  {
		auto* const newNode = new dcan::ast::node::stmt({::dcan::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| source_declaration  {
		auto* const newNode = new dcan::ast::node::stmt({::dcan::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| assignment  {
		auto* const newNode = new dcan::ast::node::stmt({::dcan::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| connection  {
		auto* const newNode = new dcan::ast::node::stmt({::dcan::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


node_declaration:
	NODE node_name  {
		auto* const newNode = new dcan::ast::node::node_declaration({::dcan::ast::Type::node_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::NODE({::dcan::ast::Type::NODE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


ground_declaration:
	GROUND ground_name  {
		auto* const newNode = new dcan::ast::node::ground_declaration({::dcan::ast::Type::ground_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::GROUND({::dcan::ast::Type::GROUND, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


source_declaration:
	IDEAL_SOURCE source_name  {
		auto* const newNode = new dcan::ast::node::source_declaration({::dcan::ast::Type::source_declaration, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::IDEAL_SOURCE({::dcan::ast::Type::IDEAL_SOURCE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


assignment:
	lhs_component_name EQ unit_value  {
		auto* const newNode = new dcan::ast::node::assignment({::dcan::ast::Type::assignment, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dcan::ast::node::EQ({::dcan::ast::Type::EQ, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


unit_value:
	current_value  {
		auto* const newNode = new dcan::ast::node::unit_value({::dcan::ast::Type::unit_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| voltage_value  {
		auto* const newNode = new dcan::ast::node::unit_value({::dcan::ast::Type::unit_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| resistance_value  {
		auto* const newNode = new dcan::ast::node::unit_value({::dcan::ast::Type::unit_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


current_value:
	CURRENT value  {
		auto* const newNode = new dcan::ast::node::current_value({::dcan::ast::Type::current_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::CURRENT({::dcan::ast::Type::CURRENT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| value CURRENT  {
		auto* const newNode = new dcan::ast::node::current_value({::dcan::ast::Type::current_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dcan::ast::node::CURRENT({::dcan::ast::Type::CURRENT, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


voltage_value:
	VOLTAGE value  {
		auto* const newNode = new dcan::ast::node::voltage_value({::dcan::ast::Type::voltage_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::VOLTAGE({::dcan::ast::Type::VOLTAGE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| value VOLTAGE  {
		auto* const newNode = new dcan::ast::node::voltage_value({::dcan::ast::Type::voltage_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dcan::ast::node::VOLTAGE({::dcan::ast::Type::VOLTAGE, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


resistance_value:
	RESISTANCE value  {
		auto* const newNode = new dcan::ast::node::resistance_value({::dcan::ast::Type::resistance_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::RESISTANCE({::dcan::ast::Type::RESISTANCE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| value RESISTANCE  {
		auto* const newNode = new dcan::ast::node::resistance_value({::dcan::ast::Type::resistance_value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dcan::ast::node::RESISTANCE({::dcan::ast::Type::RESISTANCE, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


value:
	NUMBER  {
		auto* const newNode = new dcan::ast::node::value({::dcan::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::NUMBER({::dcan::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


connection:
	component_name deamerreserved_plus__MIN__component_name__  {
		auto* const newNode = new dcan::ast::node::connection({::dcan::ast::Type::connection, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_plus__MIN__component_name__:
	MIN component_name  {
		auto* const newNode = new dcan::ast::node::deamerreserved_plus__MIN__component_name__({::dcan::ast::Type::deamerreserved_plus__MIN__component_name__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dcan::ast::node::MIN({::dcan::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| MIN component_name deamerreserved_plus__MIN__component_name__  {
		auto* const newNode = new dcan::ast::node::deamerreserved_plus__MIN__component_name__({::dcan::ast::Type::deamerreserved_plus__MIN__component_name__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dcan::ast::node::MIN({::dcan::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2, $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


component_name:
	VARNAME  {
		auto* const newNode = new dcan::ast::node::component_name({::dcan::ast::Type::component_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::VARNAME({::dcan::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


lhs_component_name:
	VARNAME  {
		auto* const newNode = new dcan::ast::node::lhs_component_name({::dcan::ast::Type::lhs_component_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::VARNAME({::dcan::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


rhs_component_name:
	VARNAME  {
		auto* const newNode = new dcan::ast::node::rhs_component_name({::dcan::ast::Type::rhs_component_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::VARNAME({::dcan::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


source_name:
	VARNAME  {
		auto* const newNode = new dcan::ast::node::source_name({::dcan::ast::Type::source_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::VARNAME({::dcan::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


ground_name:
	VARNAME  {
		auto* const newNode = new dcan::ast::node::ground_name({::dcan::ast::Type::ground_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::VARNAME({::dcan::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


node_name:
	VARNAME  {
		auto* const newNode = new dcan::ast::node::node_name({::dcan::ast::Type::node_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dcan::ast::node::VARNAME({::dcan::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void dcanerror(const char* s)
{
	std::cout << "Error: " << s << "\n";
	std::cout << "In line: " << dcanlineno << ", Column: " << dcan_column << '\n';

	std::size_t currentLineCount = 1;
	auto index = 0;
	static constexpr auto offsetShow = 2;

	while (index < dcan_input_text->size())
	{
		if ((*dcan_input_text)[index] == '\n')
		{
			currentLineCount += 1;
		}
		index++;

		if (currentLineCount + offsetShow >= dcanlineno)
		{
			break;
		}

	}

	bool donePreShow = false;
	while (!donePreShow && offsetShow > 0)
	{
		if ((*dcan_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*dcan_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*dcan_input_text)[index];
		}

		if ((*dcan_input_text)[index] == '\n')
		{
			if (currentLineCount + 1 == dcanlineno)
			{
				donePreShow = true;
			}
			currentLineCount += 1;
		}

		index++;
	}
	
	bool endLine = false;
	while (!endLine && index < dcan_input_text->size())
	{
		if ((*dcan_input_text)[index] == '\t')
		{
			std::cout << ' ';
		}
		else if ((*dcan_input_text)[index] == '\r')
		{
			// skip
		}
		else
		{
			std::cout << (*dcan_input_text)[index];
		}
		
		if ((*dcan_input_text)[index] == '\n')
		{
			endLine = true;
		}
		
		index++;
	}

    for(int i = 0; i < dcan_column - 1; i++)
	{
		std::cout << "_";
	}
	std::cout << "^\n";
}

deamer::external::cpp::ast::Tree* dcan::bison::parser::Parser::Parse(const std::string& text) const
{
	dcan_input_text = &text;
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = dcan_scan_string(text.c_str());
	dcanparse();
	dcan_delete_buffer(buf);
	dcanlex_destroy();

	return outputTree;
}
