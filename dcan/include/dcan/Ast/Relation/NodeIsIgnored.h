#ifndef DCAN_AST_RELATION_NODEISIGNORED_H
#define DCAN_AST_RELATION_NODEISIGNORED_H

#include "dcan/Ast/Enum/Type.h"

namespace dcan { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::dcan::ast::Type t)
	{
		
		if (t == ::dcan::ast::Type::SINGLE_COMMENT)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::MULTI_COMMENT)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::CURRENT)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::VOLTAGE)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::RESISTANCE)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::NODE)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::IDEAL_SOURCE)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::GROUND)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::NUMBER)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::MIN)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::EQ)
		{
			return false;
		}

		if (t == ::dcan::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DCAN_AST_RELATION_NODEISIGNORED_H