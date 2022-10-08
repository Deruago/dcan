#ifndef DCAN_AST_RELATION_NODEENUMTOTEXT_H
#define DCAN_AST_RELATION_NODEENUMTOTEXT_H

#include "dcan/Ast/Enum/Type.h"

namespace dcan { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::dcan::ast::Type type)
	{
		switch(type)
		{
			
	case ::dcan::ast::Type::program: {
		return "program";
	}
	

	case ::dcan::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::dcan::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::dcan::ast::Type::node_declaration: {
		return "node_declaration";
	}
	

	case ::dcan::ast::Type::ground_declaration: {
		return "ground_declaration";
	}
	

	case ::dcan::ast::Type::source_declaration: {
		return "source_declaration";
	}
	

	case ::dcan::ast::Type::assignment: {
		return "assignment";
	}
	

	case ::dcan::ast::Type::unit_value: {
		return "unit_value";
	}
	

	case ::dcan::ast::Type::current_value: {
		return "current_value";
	}
	

	case ::dcan::ast::Type::voltage_value: {
		return "voltage_value";
	}
	

	case ::dcan::ast::Type::resistance_value: {
		return "resistance_value";
	}
	

	case ::dcan::ast::Type::value: {
		return "value";
	}
	

	case ::dcan::ast::Type::connection: {
		return "connection";
	}
	

	case ::dcan::ast::Type::deamerreserved_plus__MIN__component_name__: {
		return "deamerreserved_plus__MIN__component_name__";
	}
	

	case ::dcan::ast::Type::component_name: {
		return "component_name";
	}
	

	case ::dcan::ast::Type::lhs_component_name: {
		return "lhs_component_name";
	}
	

	case ::dcan::ast::Type::rhs_component_name: {
		return "rhs_component_name";
	}
	

	case ::dcan::ast::Type::source_name: {
		return "source_name";
	}
	

	case ::dcan::ast::Type::ground_name: {
		return "ground_name";
	}
	

	case ::dcan::ast::Type::node_name: {
		return "node_name";
	}
	

	case ::dcan::ast::Type::SINGLE_COMMENT: {
		return "SINGLE_COMMENT";
	}
	

	case ::dcan::ast::Type::MULTI_COMMENT: {
		return "MULTI_COMMENT";
	}
	

	case ::dcan::ast::Type::CURRENT: {
		return "CURRENT";
	}
	

	case ::dcan::ast::Type::VOLTAGE: {
		return "VOLTAGE";
	}
	

	case ::dcan::ast::Type::RESISTANCE: {
		return "RESISTANCE";
	}
	

	case ::dcan::ast::Type::NODE: {
		return "NODE";
	}
	

	case ::dcan::ast::Type::IDEAL_SOURCE: {
		return "IDEAL_SOURCE";
	}
	

	case ::dcan::ast::Type::GROUND: {
		return "GROUND";
	}
	

	case ::dcan::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::dcan::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::dcan::ast::Type::MIN: {
		return "MIN";
	}
	

	case ::dcan::ast::Type::EQ: {
		return "EQ";
	}
	

	case ::dcan::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DCAN_AST_RELATION_NODEENUMTOTEXT_H