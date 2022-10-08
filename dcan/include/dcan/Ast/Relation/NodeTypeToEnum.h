#ifndef DCAN_AST_RELATION_NODETYPETOENUM_H
#define DCAN_AST_RELATION_NODETYPETOENUM_H

#include "dcan/Ast/Enum/Type.h"

namespace dcan { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class node_declaration;
class ground_declaration;
class source_declaration;
class assignment;
class unit_value;
class current_value;
class voltage_value;
class resistance_value;
class value;
class connection;
class deamerreserved_plus__MIN__component_name__;
class component_name;
class lhs_component_name;
class rhs_component_name;
class source_name;
class ground_name;
class node_name;
class SINGLE_COMMENT;
class MULTI_COMMENT;
class CURRENT;
class VOLTAGE;
class RESISTANCE;
class NODE;
class IDEAL_SOURCE;
class GROUND;
class VARNAME;
class NUMBER;
class MIN;
class EQ;
class ESCAPE_CHARS;

}}}

namespace dcan { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::dcan::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::dcan::ast::node::program>
	{
		constexpr static auto value = ::dcan::ast::Type::program;
		using type = ::dcan::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::dcan::ast::Type::deamerreserved_star__stmt__;
		using type = ::dcan::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::stmt>
	{
		constexpr static auto value = ::dcan::ast::Type::stmt;
		using type = ::dcan::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::node_declaration>
	{
		constexpr static auto value = ::dcan::ast::Type::node_declaration;
		using type = ::dcan::ast::node::node_declaration;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::ground_declaration>
	{
		constexpr static auto value = ::dcan::ast::Type::ground_declaration;
		using type = ::dcan::ast::node::ground_declaration;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::source_declaration>
	{
		constexpr static auto value = ::dcan::ast::Type::source_declaration;
		using type = ::dcan::ast::node::source_declaration;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::assignment>
	{
		constexpr static auto value = ::dcan::ast::Type::assignment;
		using type = ::dcan::ast::node::assignment;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::unit_value>
	{
		constexpr static auto value = ::dcan::ast::Type::unit_value;
		using type = ::dcan::ast::node::unit_value;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::current_value>
	{
		constexpr static auto value = ::dcan::ast::Type::current_value;
		using type = ::dcan::ast::node::current_value;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::voltage_value>
	{
		constexpr static auto value = ::dcan::ast::Type::voltage_value;
		using type = ::dcan::ast::node::voltage_value;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::resistance_value>
	{
		constexpr static auto value = ::dcan::ast::Type::resistance_value;
		using type = ::dcan::ast::node::resistance_value;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::value>
	{
		constexpr static auto value = ::dcan::ast::Type::value;
		using type = ::dcan::ast::node::value;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::connection>
	{
		constexpr static auto value = ::dcan::ast::Type::connection;
		using type = ::dcan::ast::node::connection;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>
	{
		constexpr static auto value = ::dcan::ast::Type::deamerreserved_plus__MIN__component_name__;
		using type = ::dcan::ast::node::deamerreserved_plus__MIN__component_name__;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::component_name>
	{
		constexpr static auto value = ::dcan::ast::Type::component_name;
		using type = ::dcan::ast::node::component_name;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::lhs_component_name>
	{
		constexpr static auto value = ::dcan::ast::Type::lhs_component_name;
		using type = ::dcan::ast::node::lhs_component_name;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::rhs_component_name>
	{
		constexpr static auto value = ::dcan::ast::Type::rhs_component_name;
		using type = ::dcan::ast::node::rhs_component_name;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::source_name>
	{
		constexpr static auto value = ::dcan::ast::Type::source_name;
		using type = ::dcan::ast::node::source_name;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::ground_name>
	{
		constexpr static auto value = ::dcan::ast::Type::ground_name;
		using type = ::dcan::ast::node::ground_name;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::node_name>
	{
		constexpr static auto value = ::dcan::ast::Type::node_name;
		using type = ::dcan::ast::node::node_name;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::SINGLE_COMMENT>
	{
		constexpr static auto value = ::dcan::ast::Type::SINGLE_COMMENT;
		using type = ::dcan::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::MULTI_COMMENT>
	{
		constexpr static auto value = ::dcan::ast::Type::MULTI_COMMENT;
		using type = ::dcan::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::CURRENT>
	{
		constexpr static auto value = ::dcan::ast::Type::CURRENT;
		using type = ::dcan::ast::node::CURRENT;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::VOLTAGE>
	{
		constexpr static auto value = ::dcan::ast::Type::VOLTAGE;
		using type = ::dcan::ast::node::VOLTAGE;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::RESISTANCE>
	{
		constexpr static auto value = ::dcan::ast::Type::RESISTANCE;
		using type = ::dcan::ast::node::RESISTANCE;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::NODE>
	{
		constexpr static auto value = ::dcan::ast::Type::NODE;
		using type = ::dcan::ast::node::NODE;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::IDEAL_SOURCE>
	{
		constexpr static auto value = ::dcan::ast::Type::IDEAL_SOURCE;
		using type = ::dcan::ast::node::IDEAL_SOURCE;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::GROUND>
	{
		constexpr static auto value = ::dcan::ast::Type::GROUND;
		using type = ::dcan::ast::node::GROUND;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::VARNAME>
	{
		constexpr static auto value = ::dcan::ast::Type::VARNAME;
		using type = ::dcan::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::NUMBER>
	{
		constexpr static auto value = ::dcan::ast::Type::NUMBER;
		using type = ::dcan::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::MIN>
	{
		constexpr static auto value = ::dcan::ast::Type::MIN;
		using type = ::dcan::ast::node::MIN;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::EQ>
	{
		constexpr static auto value = ::dcan::ast::Type::EQ;
		using type = ::dcan::ast::node::EQ;
	};

	template<>
	struct NodeTypeToEnum<::dcan::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::dcan::ast::Type::ESCAPE_CHARS;
		using type = ::dcan::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::dcan::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::dcan::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DCAN_AST_RELATION_NODETYPETOENUM_H