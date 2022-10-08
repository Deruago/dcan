#ifndef DCAN_AST_UTILITY_CREATENODE_H
#define DCAN_AST_UTILITY_CREATENODE_H

#include "dcan/Ast/Enum/Type.h"
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


#include <Deamer/External/Cpp/Ast/Node.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <string>
#include <vector>

namespace dcan { namespace ast { namespace utility { 

	struct CreateNode
	{
	private:
		std::string nodeValue;
		std::size_t nodeType = 0;
		
		std::vector<::deamer::external::cpp::ast::Node*> nodes;
		std::vector<std::size_t> baseValues;

		int lineNumber = -1;
		int columnNumber = -1;

		std::size_t productionRuleId = 0;
		::deamer::external::cpp::ast::ProductionRuleType productionRuleType =
					::deamer::external::cpp::ast::ProductionRuleType::unknown;
	
	public:
		CreateNode() = default;
		~CreateNode() = default;

	public:
		CreateNode& Node(const ::deamer::external::cpp::lexer::TerminalObject* terminalObject)
		{
			nodeValue = terminalObject->GetValue();
			nodeType = terminalObject->GetType();
			
			lineNumber = terminalObject->GetLineNumber();
			columnNumber = terminalObject->GetColumnNumber();

			return *this;
		}

		CreateNode& Node(std::size_t nodeType_)
		{
			nodeType = nodeType_;

			return *this;
		}

		CreateNode& ProductionRule(std::size_t productionRuleId_,
			::deamer::external::cpp::ast::ProductionRuleType productionRuleType_ = ::deamer::external::cpp::ast::ProductionRuleType::user)
		{
			productionRuleId = productionRuleId_;
			productionRuleType = productionRuleType_;

			return *this;
		}

		CreateNode& SubNode(::deamer::external::cpp::lexer::TerminalObject* terminalObject)
		{
			CreateNode tmp{};
			
			tmp.Node(terminalObject);
			nodes.push_back(tmp.GetNode());

			return *this;
		}

		CreateNode& SubNode(::deamer::external::cpp::ast::Node* subNode_)
		{
			nodes.push_back(subNode_);
			return *this;
		}

		::deamer::external::cpp::ast::Node* GetNode()
		{
			switch(static_cast<::dcan::ast::Type>(nodeType))
			{
			case ::dcan::ast::Type::deamerreserved_unknown: {
				return new ::deamer::external::cpp::ast::Node(
					deamer::external::cpp::ast::NodeInformation{
						nodeType, deamer::external::cpp::ast::NodeValue::terminal, nodeValue,
						lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::SINGLE_COMMENT: {
				return new ::dcan::ast::node::SINGLE_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::MULTI_COMMENT: {
				return new ::dcan::ast::node::MULTI_COMMENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::CURRENT: {
				return new ::dcan::ast::node::CURRENT({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::VOLTAGE: {
				return new ::dcan::ast::node::VOLTAGE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::RESISTANCE: {
				return new ::dcan::ast::node::RESISTANCE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::NODE: {
				return new ::dcan::ast::node::NODE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::IDEAL_SOURCE: {
				return new ::dcan::ast::node::IDEAL_SOURCE({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::GROUND: {
				return new ::dcan::ast::node::GROUND({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::VARNAME: {
				return new ::dcan::ast::node::VARNAME({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::NUMBER: {
				return new ::dcan::ast::node::NUMBER({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::MIN: {
				return new ::dcan::ast::node::MIN({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::EQ: {
				return new ::dcan::ast::node::EQ({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::ESCAPE_CHARS: {
				return new ::dcan::ast::node::ESCAPE_CHARS({nodeType, ::deamer::external::cpp::ast::NodeValue::terminal, nodeValue, lineNumber, columnNumber});
			}
			case ::dcan::ast::Type::program: {
				return new ::dcan::ast::node::program({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::deamerreserved_star__stmt__: {
				return new ::dcan::ast::node::deamerreserved_star__stmt__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::stmt: {
				return new ::dcan::ast::node::stmt({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::node_declaration: {
				return new ::dcan::ast::node::node_declaration({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::ground_declaration: {
				return new ::dcan::ast::node::ground_declaration({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::source_declaration: {
				return new ::dcan::ast::node::source_declaration({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::assignment: {
				return new ::dcan::ast::node::assignment({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::unit_value: {
				return new ::dcan::ast::node::unit_value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::current_value: {
				return new ::dcan::ast::node::current_value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::voltage_value: {
				return new ::dcan::ast::node::voltage_value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::resistance_value: {
				return new ::dcan::ast::node::resistance_value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::value: {
				return new ::dcan::ast::node::value({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::connection: {
				return new ::dcan::ast::node::connection({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::deamerreserved_plus__MIN__component_name__: {
				return new ::dcan::ast::node::deamerreserved_plus__MIN__component_name__({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::component_name: {
				return new ::dcan::ast::node::component_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::lhs_component_name: {
				return new ::dcan::ast::node::lhs_component_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::rhs_component_name: {
				return new ::dcan::ast::node::rhs_component_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::source_name: {
				return new ::dcan::ast::node::source_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::ground_name: {
				return new ::dcan::ast::node::ground_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}
			case ::dcan::ast::Type::node_name: {
				return new ::dcan::ast::node::node_name({nodeType, ::deamer::external::cpp::ast::NodeValue::nonterminal, {productionRuleId, productionRuleType}}, nodes);
			}

			}

			return nullptr;
		}
	};

}}}

#endif // DCAN_AST_UTILITY_CREATENODE_H