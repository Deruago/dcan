#ifndef DCAN_AST_RELATION_NODEISTERMINAL_H
#define DCAN_AST_RELATION_NODEISTERMINAL_H

#include "dcan/Ast/Enum/Type.h"

namespace dcan { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::dcan::ast::Type t)
	{
		
		if (t == ::dcan::ast::Type::SINGLE_COMMENT)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::MULTI_COMMENT)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::CURRENT)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::VOLTAGE)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::RESISTANCE)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::NODE)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::IDEAL_SOURCE)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::GROUND)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::VARNAME)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::NUMBER)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::MIN)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::EQ)
		{
			return true;
		}

		if (t == ::dcan::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DCAN_AST_RELATION_NODEISTERMINAL_H