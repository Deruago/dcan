/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#include "dcan/Grammar.h"
#include "dcan/Language.h"

dcan::Grammar::Grammar(dcan::Language* language)
			:	::deamer::language::generator::definition::property::user::Grammar<
					dcan::Language>(language)
{
}

void dcan::Grammar::GenerateObjects()
{
	// Non-Terminal initialization
	program.Set(::deamer::language::type::definition::object::main::NonTerminal("program", { program_deamerreserved_star__stmt__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_star__stmt__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_star__stmt__", { deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__.Pointer(),deamerreserved_star__stmt___EMPTY.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
stmt.Set(::deamer::language::type::definition::object::main::NonTerminal("stmt", { stmt_node_declaration.Pointer(),stmt_ground_declaration.Pointer(),stmt_source_declaration.Pointer(),stmt_assignment.Pointer(),stmt_connection.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
node_declaration.Set(::deamer::language::type::definition::object::main::NonTerminal("node_declaration", { node_declaration_NODE_node_name.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
ground_declaration.Set(::deamer::language::type::definition::object::main::NonTerminal("ground_declaration", { ground_declaration_GROUND_ground_name.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
source_declaration.Set(::deamer::language::type::definition::object::main::NonTerminal("source_declaration", { source_declaration_IDEAL_SOURCE_source_name.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
assignment.Set(::deamer::language::type::definition::object::main::NonTerminal("assignment", { assignment_lhs_component_name_EQ_unit_value.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
unit_value.Set(::deamer::language::type::definition::object::main::NonTerminal("unit_value", { unit_value_current_value.Pointer(),unit_value_voltage_value.Pointer(),unit_value_resistance_value.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
current_value.Set(::deamer::language::type::definition::object::main::NonTerminal("current_value", { current_value_CURRENT_value.Pointer(),current_value_value_CURRENT.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
voltage_value.Set(::deamer::language::type::definition::object::main::NonTerminal("voltage_value", { voltage_value_VOLTAGE_value.Pointer(),voltage_value_value_VOLTAGE.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
resistance_value.Set(::deamer::language::type::definition::object::main::NonTerminal("resistance_value", { resistance_value_RESISTANCE_value.Pointer(),resistance_value_value_RESISTANCE.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
value.Set(::deamer::language::type::definition::object::main::NonTerminal("value", { value_NUMBER.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
connection.Set(::deamer::language::type::definition::object::main::NonTerminal("connection", { connection_component_name_deamerreserved_plus__MIN__component_name__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_plus__MIN__component_name__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_plus__MIN__component_name__", { deamerreserved_plus__MIN__component_name___MIN_component_name.Pointer(),deamerreserved_plus__MIN__component_name___MIN_component_name_deamerreserved_plus__MIN__component_name__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
component_name.Set(::deamer::language::type::definition::object::main::NonTerminal("component_name", { component_name_VARNAME.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
lhs_component_name.Set(::deamer::language::type::definition::object::main::NonTerminal("lhs_component_name", { lhs_component_name_VARNAME.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
rhs_component_name.Set(::deamer::language::type::definition::object::main::NonTerminal("rhs_component_name", { rhs_component_name_VARNAME.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
source_name.Set(::deamer::language::type::definition::object::main::NonTerminal("source_name", { source_name_VARNAME.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
ground_name.Set(::deamer::language::type::definition::object::main::NonTerminal("ground_name", { ground_name_VARNAME.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
node_name.Set(::deamer::language::type::definition::object::main::NonTerminal("node_name", { node_name_VARNAME.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));


	// Production-Rule initialization
	deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->stmt.Pointer(),Language->deamerreserved_star__stmt__.Pointer() }));
deamerreserved_star__stmt___EMPTY.Set(::deamer::language::type::definition::object::main::ProductionRule());
program_deamerreserved_star__stmt__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->deamerreserved_star__stmt__.Pointer() }));
stmt_node_declaration.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->node_declaration.Pointer() }));
stmt_ground_declaration.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->ground_declaration.Pointer() }));
stmt_source_declaration.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->source_declaration.Pointer() }));
stmt_assignment.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->assignment.Pointer() }));
stmt_connection.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->connection.Pointer() }));
node_declaration_NODE_node_name.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->NODE.Pointer(),Language->node_name.Pointer() }));
ground_declaration_GROUND_ground_name.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->GROUND.Pointer(),Language->ground_name.Pointer() }));
source_declaration_IDEAL_SOURCE_source_name.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->IDEAL_SOURCE.Pointer(),Language->source_name.Pointer() }));
assignment_lhs_component_name_EQ_unit_value.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->lhs_component_name.Pointer(),Language->EQ.Pointer(),Language->unit_value.Pointer() }));
unit_value_current_value.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->current_value.Pointer() }));
unit_value_voltage_value.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->voltage_value.Pointer() }));
unit_value_resistance_value.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->resistance_value.Pointer() }));
current_value_CURRENT_value.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->CURRENT.Pointer(),Language->value.Pointer() }));
current_value_value_CURRENT.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->value.Pointer(),Language->CURRENT.Pointer() }));
voltage_value_VOLTAGE_value.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->VOLTAGE.Pointer(),Language->value.Pointer() }));
voltage_value_value_VOLTAGE.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->value.Pointer(),Language->VOLTAGE.Pointer() }));
resistance_value_RESISTANCE_value.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->RESISTANCE.Pointer(),Language->value.Pointer() }));
resistance_value_value_RESISTANCE.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->value.Pointer(),Language->RESISTANCE.Pointer() }));
value_NUMBER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->NUMBER.Pointer() }));
deamerreserved_plus__MIN__component_name___MIN_component_name.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->MIN.Pointer(),Language->component_name.Pointer() }));
deamerreserved_plus__MIN__component_name___MIN_component_name_deamerreserved_plus__MIN__component_name__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->MIN.Pointer(),Language->component_name.Pointer(),Language->deamerreserved_plus__MIN__component_name__.Pointer() }));
connection_component_name_deamerreserved_plus__MIN__component_name__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->component_name.Pointer(),Language->deamerreserved_plus__MIN__component_name__.Pointer() }));
component_name_VARNAME.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->VARNAME.Pointer() }));
lhs_component_name_VARNAME.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->VARNAME.Pointer() }));
rhs_component_name_VARNAME.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->VARNAME.Pointer() }));
source_name_VARNAME.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->VARNAME.Pointer() }));
ground_name_VARNAME.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->VARNAME.Pointer() }));
node_name_VARNAME.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->VARNAME.Pointer() }));


	// Unknown references
	

	// Add object calls
	// AddObject(...)
	AddObject(program);
AddObject(deamerreserved_star__stmt__);
AddObject(stmt);
AddObject(node_declaration);
AddObject(ground_declaration);
AddObject(source_declaration);
AddObject(assignment);
AddObject(unit_value);
AddObject(current_value);
AddObject(voltage_value);
AddObject(resistance_value);
AddObject(value);
AddObject(connection);
AddObject(deamerreserved_plus__MIN__component_name__);
AddObject(component_name);
AddObject(lhs_component_name);
AddObject(rhs_component_name);
AddObject(source_name);
AddObject(ground_name);
AddObject(node_name);


	AddObject(deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__);
AddObject(deamerreserved_star__stmt___EMPTY);
AddObject(program_deamerreserved_star__stmt__);
AddObject(stmt_node_declaration);
AddObject(stmt_ground_declaration);
AddObject(stmt_source_declaration);
AddObject(stmt_assignment);
AddObject(stmt_connection);
AddObject(node_declaration_NODE_node_name);
AddObject(ground_declaration_GROUND_ground_name);
AddObject(source_declaration_IDEAL_SOURCE_source_name);
AddObject(assignment_lhs_component_name_EQ_unit_value);
AddObject(unit_value_current_value);
AddObject(unit_value_voltage_value);
AddObject(unit_value_resistance_value);
AddObject(current_value_CURRENT_value);
AddObject(current_value_value_CURRENT);
AddObject(voltage_value_VOLTAGE_value);
AddObject(voltage_value_value_VOLTAGE);
AddObject(resistance_value_RESISTANCE_value);
AddObject(resistance_value_value_RESISTANCE);
AddObject(value_NUMBER);
AddObject(deamerreserved_plus__MIN__component_name___MIN_component_name);
AddObject(deamerreserved_plus__MIN__component_name___MIN_component_name_deamerreserved_plus__MIN__component_name__);
AddObject(connection_component_name_deamerreserved_plus__MIN__component_name__);
AddObject(component_name_VARNAME);
AddObject(lhs_component_name_VARNAME);
AddObject(rhs_component_name_VARNAME);
AddObject(source_name_VARNAME);
AddObject(ground_name_VARNAME);
AddObject(node_name_VARNAME);


	


	// Place higher level operations here.
	// ReplaceObject(..., ...)
	// DeleteObject(..., ...)
	
}
