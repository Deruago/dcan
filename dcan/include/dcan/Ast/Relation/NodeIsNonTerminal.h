#ifndef DCAN_AST_RELATION_NODEISNONTERMINAL_H
#define DCAN_AST_RELATION_NODEISNONTERMINAL_H

#include "dcan/Ast/Enum/Type.h"

namespace dcan { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::dcan::ast::Type t)
	{
		
		if (t == ::dcan::ast::Type::program)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::node_declaration)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::ground_declaration)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::source_declaration)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::assignment)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::unit_value)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::current_value)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::voltage_value)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::resistance_value)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::value)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::connection)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::deamerreserved_plus__MIN__component_name__)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::component_name)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::lhs_component_name)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::rhs_component_name)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::source_name)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::ground_name)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::node_name)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DCAN_AST_RELATION_NODEISNONTERMINAL_H