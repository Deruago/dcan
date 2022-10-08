#ifndef DCAN_AST_ENUM_TYPE_H
#define DCAN_AST_ENUM_TYPE_H

#include <cstddef>

namespace dcan { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		SINGLE_COMMENT,
		MULTI_COMMENT,
		CURRENT,
		VOLTAGE,
		RESISTANCE,
		NODE,
		IDEAL_SOURCE,
		GROUND,
		VARNAME,
		NUMBER,
		MIN,
		EQ,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		node_declaration,
		ground_declaration,
		source_declaration,
		assignment,
		unit_value,
		current_value,
		voltage_value,
		resistance_value,
		value,
		connection,
		deamerreserved_plus__MIN__component_name__,
		component_name,
		lhs_component_name,
		rhs_component_name,
		source_name,
		ground_name,
		node_name,

	};

	static inline bool operator==(std::size_t lhs, ::dcan::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::dcan::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::dcan::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::dcan::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DCAN_AST_ENUM_TYPE_H