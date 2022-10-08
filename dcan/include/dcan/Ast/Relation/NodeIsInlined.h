#ifndef DCAN_AST_RELATION_NODEISINLINED_H
#define DCAN_AST_RELATION_NODEISINLINED_H

#include "dcan/Ast/Enum/Type.h"

namespace dcan { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::dcan::ast::Type t)
	{
		
		if (t == ::dcan::ast::Type::program)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::node_declaration)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::ground_declaration)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::source_declaration)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::assignment)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::unit_value)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::current_value)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::voltage_value)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::resistance_value)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::value)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::connection)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::deamerreserved_plus__MIN__component_name__)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::component_name)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::lhs_component_name)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::rhs_component_name)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::source_name)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::ground_name)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::node_name)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DCAN_AST_RELATION_NODEISINLINED_H