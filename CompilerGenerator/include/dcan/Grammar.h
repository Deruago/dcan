/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DCAN_GRAMMAR_H
#define DCAN_GRAMMAR_H

#include "Deamer/Language/Generator/Definition/Property/User/Main/Grammar.h"
#include "Deamer/Language/Type/Definition/Object/Special/Uninitialized.h"

namespace dcan
{
	class Language;

	/*!	\class Grammar
	 *
	 *	\brief This contains the grammar LPD of the language dcan
	 *
	 *	\note This is auto-generated via the DLDL definition.
	 */
	class Grammar : public ::deamer::language::generator::definition::property::user::Grammar<
								::dcan::Language>
	{
	public:
		// Non-Terminal declarations
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> program;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_star__stmt__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> stmt;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> node_declaration;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> ground_declaration;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> source_declaration;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> assignment;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> unit_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> current_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> voltage_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> resistance_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> connection;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_plus__MIN__component_name__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> component_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> lhs_component_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> rhs_component_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> source_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> ground_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> node_name;

	
		// Production-Rule declarations
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__stmt___EMPTY;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> program_deamerreserved_star__stmt__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> stmt_node_declaration;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> stmt_ground_declaration;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> stmt_source_declaration;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> stmt_assignment;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> stmt_connection;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> node_declaration_NODE_node_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> ground_declaration_GROUND_ground_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> source_declaration_IDEAL_SOURCE_source_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> assignment_lhs_component_name_EQ_unit_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> unit_value_current_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> unit_value_voltage_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> unit_value_resistance_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> current_value_CURRENT_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> current_value_value_CURRENT;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> voltage_value_VOLTAGE_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> voltage_value_value_VOLTAGE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> resistance_value_RESISTANCE_value;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> resistance_value_value_RESISTANCE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> value_NUMBER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_plus__MIN__component_name___MIN_component_name;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_plus__MIN__component_name___MIN_component_name_deamerreserved_plus__MIN__component_name__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> connection_component_name_deamerreserved_plus__MIN__component_name__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> component_name_VARNAME;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> lhs_component_name_VARNAME;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> rhs_component_name_VARNAME;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> source_name_VARNAME;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> ground_name_VARNAME;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> node_name_VARNAME;

	
	private:
		// Unknown reference declarations
		
	
	public:
		Grammar(dcan::Language* language);

		void GenerateObjects() override;
	};
}

#endif // DCAN_GRAMMAR_H
