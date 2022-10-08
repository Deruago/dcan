#ifndef DCAN_AST_RELATION_NODETEXTTOENUM_H
#define DCAN_AST_RELATION_NODETEXTTOENUM_H

#include "dcan/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace dcan { namespace ast { namespace relation { 

	static constexpr ::dcan::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::dcan::ast::Type> mapTextWithType = {
			{"", ::dcan::ast::Type::deamerreserved_unknown },
			
		{ "program", ::dcan::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::dcan::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::dcan::ast::Type::stmt },
	

		{ "node_declaration", ::dcan::ast::Type::node_declaration },
	

		{ "ground_declaration", ::dcan::ast::Type::ground_declaration },
	

		{ "source_declaration", ::dcan::ast::Type::source_declaration },
	

		{ "assignment", ::dcan::ast::Type::assignment },
	

		{ "unit_value", ::dcan::ast::Type::unit_value },
	

		{ "current_value", ::dcan::ast::Type::current_value },
	

		{ "voltage_value", ::dcan::ast::Type::voltage_value },
	

		{ "resistance_value", ::dcan::ast::Type::resistance_value },
	

		{ "value", ::dcan::ast::Type::value },
	

		{ "connection", ::dcan::ast::Type::connection },
	

		{ "deamerreserved_plus__MIN__component_name__", ::dcan::ast::Type::deamerreserved_plus__MIN__component_name__ },
	

		{ "component_name", ::dcan::ast::Type::component_name },
	

		{ "lhs_component_name", ::dcan::ast::Type::lhs_component_name },
	

		{ "rhs_component_name", ::dcan::ast::Type::rhs_component_name },
	

		{ "source_name", ::dcan::ast::Type::source_name },
	

		{ "ground_name", ::dcan::ast::Type::ground_name },
	

		{ "node_name", ::dcan::ast::Type::node_name },
	

		{ "SINGLE_COMMENT", ::dcan::ast::Type::SINGLE_COMMENT },
	

		{ "MULTI_COMMENT", ::dcan::ast::Type::MULTI_COMMENT },
	

		{ "CURRENT", ::dcan::ast::Type::CURRENT },
	

		{ "VOLTAGE", ::dcan::ast::Type::VOLTAGE },
	

		{ "RESISTANCE", ::dcan::ast::Type::RESISTANCE },
	

		{ "NODE", ::dcan::ast::Type::NODE },
	

		{ "IDEAL_SOURCE", ::dcan::ast::Type::IDEAL_SOURCE },
	

		{ "GROUND", ::dcan::ast::Type::GROUND },
	

		{ "VARNAME", ::dcan::ast::Type::VARNAME },
	

		{ "NUMBER", ::dcan::ast::Type::NUMBER },
	

		{ "MIN", ::dcan::ast::Type::MIN },
	

		{ "EQ", ::dcan::ast::Type::EQ },
	

		{ "ESCAPE_CHARS", ::dcan::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DCAN_AST_RELATION_NODETEXTTOENUM_H