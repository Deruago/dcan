#ifndef DCAN_AST_RELATION_NODEENUMTOTYPE_H
#define DCAN_AST_RELATION_NODEENUMTOTYPE_H

#include "dcan/Ast/Enum/Type.h"

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


namespace dcan { namespace ast { namespace relation { 

	template<::dcan::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::dcan::ast::Type::program>
	{
		constexpr static auto value = ::dcan::ast::Type::program;
		using type = ::dcan::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::dcan::ast::Type::deamerreserved_star__stmt__;
		using type = ::dcan::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::stmt>
	{
		constexpr static auto value = ::dcan::ast::Type::stmt;
		using type = ::dcan::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::node_declaration>
	{
		constexpr static auto value = ::dcan::ast::Type::node_declaration;
		using type = ::dcan::ast::node::node_declaration;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::ground_declaration>
	{
		constexpr static auto value = ::dcan::ast::Type::ground_declaration;
		using type = ::dcan::ast::node::ground_declaration;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::source_declaration>
	{
		constexpr static auto value = ::dcan::ast::Type::source_declaration;
		using type = ::dcan::ast::node::source_declaration;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::assignment>
	{
		constexpr static auto value = ::dcan::ast::Type::assignment;
		using type = ::dcan::ast::node::assignment;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::unit_value>
	{
		constexpr static auto value = ::dcan::ast::Type::unit_value;
		using type = ::dcan::ast::node::unit_value;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::current_value>
	{
		constexpr static auto value = ::dcan::ast::Type::current_value;
		using type = ::dcan::ast::node::current_value;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::voltage_value>
	{
		constexpr static auto value = ::dcan::ast::Type::voltage_value;
		using type = ::dcan::ast::node::voltage_value;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::resistance_value>
	{
		constexpr static auto value = ::dcan::ast::Type::resistance_value;
		using type = ::dcan::ast::node::resistance_value;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::value>
	{
		constexpr static auto value = ::dcan::ast::Type::value;
		using type = ::dcan::ast::node::value;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::connection>
	{
		constexpr static auto value = ::dcan::ast::Type::connection;
		using type = ::dcan::ast::node::connection;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::deamerreserved_plus__MIN__component_name__>
	{
		constexpr static auto value = ::dcan::ast::Type::deamerreserved_plus__MIN__component_name__;
		using type = ::dcan::ast::node::deamerreserved_plus__MIN__component_name__;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::component_name>
	{
		constexpr static auto value = ::dcan::ast::Type::component_name;
		using type = ::dcan::ast::node::component_name;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::lhs_component_name>
	{
		constexpr static auto value = ::dcan::ast::Type::lhs_component_name;
		using type = ::dcan::ast::node::lhs_component_name;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::rhs_component_name>
	{
		constexpr static auto value = ::dcan::ast::Type::rhs_component_name;
		using type = ::dcan::ast::node::rhs_component_name;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::source_name>
	{
		constexpr static auto value = ::dcan::ast::Type::source_name;
		using type = ::dcan::ast::node::source_name;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::ground_name>
	{
		constexpr static auto value = ::dcan::ast::Type::ground_name;
		using type = ::dcan::ast::node::ground_name;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::node_name>
	{
		constexpr static auto value = ::dcan::ast::Type::node_name;
		using type = ::dcan::ast::node::node_name;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::SINGLE_COMMENT>
	{
		constexpr static auto value = ::dcan::ast::Type::SINGLE_COMMENT;
		using type = ::dcan::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::MULTI_COMMENT>
	{
		constexpr static auto value = ::dcan::ast::Type::MULTI_COMMENT;
		using type = ::dcan::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::CURRENT>
	{
		constexpr static auto value = ::dcan::ast::Type::CURRENT;
		using type = ::dcan::ast::node::CURRENT;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::VOLTAGE>
	{
		constexpr static auto value = ::dcan::ast::Type::VOLTAGE;
		using type = ::dcan::ast::node::VOLTAGE;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::RESISTANCE>
	{
		constexpr static auto value = ::dcan::ast::Type::RESISTANCE;
		using type = ::dcan::ast::node::RESISTANCE;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::NODE>
	{
		constexpr static auto value = ::dcan::ast::Type::NODE;
		using type = ::dcan::ast::node::NODE;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::IDEAL_SOURCE>
	{
		constexpr static auto value = ::dcan::ast::Type::IDEAL_SOURCE;
		using type = ::dcan::ast::node::IDEAL_SOURCE;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::GROUND>
	{
		constexpr static auto value = ::dcan::ast::Type::GROUND;
		using type = ::dcan::ast::node::GROUND;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::VARNAME>
	{
		constexpr static auto value = ::dcan::ast::Type::VARNAME;
		using type = ::dcan::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::NUMBER>
	{
		constexpr static auto value = ::dcan::ast::Type::NUMBER;
		using type = ::dcan::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::MIN>
	{
		constexpr static auto value = ::dcan::ast::Type::MIN;
		using type = ::dcan::ast::node::MIN;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::EQ>
	{
		constexpr static auto value = ::dcan::ast::Type::EQ;
		using type = ::dcan::ast::node::EQ;
	};

	template<>
	struct NodeEnumToType<::dcan::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::dcan::ast::Type::ESCAPE_CHARS;
		using type = ::dcan::ast::node::ESCAPE_CHARS;
	};


template<::dcan::ast::Type T>
constexpr static auto NodeEnumToType_v = ::dcan::ast::relation::NodeEnumToType<T>::value;

template<::dcan::ast::Type T>
using NodeEnumToType_t = typename ::dcan::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DCAN_AST_RELATION_NODEENUMTOTYPE_H