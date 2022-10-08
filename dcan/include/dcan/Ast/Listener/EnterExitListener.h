#ifndef DCAN_AST_LISTENER_ENTEREXITLISTENER_H
#define DCAN_AST_LISTENER_ENTEREXITLISTENER_H

#include "dcan/Ast/Node/dcan.h"
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

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace dcan { namespace ast { namespace listener { 

	class EnterExitListener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		EnterExitListener() = default;
		~EnterExitListener() override = default;

	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node)  override
		{
			::deamer::algorithm::tree::DFS::Execute::Heap::Search(node,
				&::deamer::external::cpp::ast::Node::GetParent,
				&::deamer::external::cpp::ast::Node::GetNodes,
				&EnterExitListener::DispatchEntry,
				&EnterExitListener::DispatchExit,
				this);
		}

		void DispatchEntry(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<dcan::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case dcan::ast::Type::SINGLE_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::SINGLE_COMMENT*>(node));
				break;
			}

			case dcan::ast::Type::MULTI_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::MULTI_COMMENT*>(node));
				break;
			}

			case dcan::ast::Type::CURRENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::CURRENT*>(node));
				break;
			}

			case dcan::ast::Type::VOLTAGE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::VOLTAGE*>(node));
				break;
			}

			case dcan::ast::Type::RESISTANCE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::RESISTANCE*>(node));
				break;
			}

			case dcan::ast::Type::NODE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::NODE*>(node));
				break;
			}

			case dcan::ast::Type::IDEAL_SOURCE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::IDEAL_SOURCE*>(node));
				break;
			}

			case dcan::ast::Type::GROUND:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::GROUND*>(node));
				break;
			}

			case dcan::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::VARNAME*>(node));
				break;
			}

			case dcan::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::NUMBER*>(node));
				break;
			}

			case dcan::ast::Type::MIN:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::MIN*>(node));
				break;
			}

			case dcan::ast::Type::EQ:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::EQ*>(node));
				break;
			}

			case dcan::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case dcan::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::program*>(node));
				break;
			}

			case dcan::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case dcan::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::stmt*>(node));
				break;
			}

			case dcan::ast::Type::node_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::node_declaration*>(node));
				break;
			}

			case dcan::ast::Type::ground_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::ground_declaration*>(node));
				break;
			}

			case dcan::ast::Type::source_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::source_declaration*>(node));
				break;
			}

			case dcan::ast::Type::assignment:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::assignment*>(node));
				break;
			}

			case dcan::ast::Type::unit_value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::unit_value*>(node));
				break;
			}

			case dcan::ast::Type::current_value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::current_value*>(node));
				break;
			}

			case dcan::ast::Type::voltage_value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::voltage_value*>(node));
				break;
			}

			case dcan::ast::Type::resistance_value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::resistance_value*>(node));
				break;
			}

			case dcan::ast::Type::value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::value*>(node));
				break;
			}

			case dcan::ast::Type::connection:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::connection*>(node));
				break;
			}

			case dcan::ast::Type::deamerreserved_plus__MIN__component_name__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::deamerreserved_plus__MIN__component_name__*>(node));
				break;
			}

			case dcan::ast::Type::component_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::component_name*>(node));
				break;
			}

			case dcan::ast::Type::lhs_component_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::lhs_component_name*>(node));
				break;
			}

			case dcan::ast::Type::rhs_component_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::rhs_component_name*>(node));
				break;
			}

			case dcan::ast::Type::source_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::source_name*>(node));
				break;
			}

			case dcan::ast::Type::ground_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::ground_name*>(node));
				break;
			}

			case dcan::ast::Type::node_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dcan::ast::node::node_name*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<dcan::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case dcan::ast::Type::SINGLE_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::SINGLE_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::MULTI_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::MULTI_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::CURRENT:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::CURRENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::VOLTAGE:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::VOLTAGE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::RESISTANCE:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::RESISTANCE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::NODE:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::NODE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::IDEAL_SOURCE:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::IDEAL_SOURCE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::GROUND:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::GROUND*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::MIN:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::MIN*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::EQ:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::EQ*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const dcan::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case dcan::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::node_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::node_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::ground_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::ground_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::source_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::source_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::assignment:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::assignment*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::unit_value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::unit_value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::current_value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::current_value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::voltage_value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::voltage_value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::resistance_value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::resistance_value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::connection:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::connection*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::deamerreserved_plus__MIN__component_name__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::deamerreserved_plus__MIN__component_name__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::component_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::component_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::lhs_component_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::lhs_component_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::rhs_component_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::rhs_component_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::source_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::source_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::ground_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::ground_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dcan::ast::Type::node_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dcan::ast::node::node_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const dcan::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::CURRENT* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::VOLTAGE* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::RESISTANCE* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::NODE* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::IDEAL_SOURCE* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::GROUND* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::MIN* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::EQ* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const dcan::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::CURRENT* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::VOLTAGE* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::RESISTANCE* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::NODE* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::IDEAL_SOURCE* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::GROUND* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::MIN* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::EQ* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const dcan::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::node_declaration* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::ground_declaration* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::source_declaration* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::assignment* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::unit_value* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::current_value* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::voltage_value* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::resistance_value* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::value* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::connection* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::deamerreserved_plus__MIN__component_name__* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::component_name* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::lhs_component_name* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::rhs_component_name* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::source_name* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::ground_name* node) 
		{
		}

		virtual void ListenEntry(const dcan::ast::node::node_name* node) 
		{
		}

		
		virtual void ListenExit(const dcan::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::node_declaration* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::ground_declaration* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::source_declaration* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::assignment* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::unit_value* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::current_value* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::voltage_value* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::resistance_value* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::value* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::connection* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::deamerreserved_plus__MIN__component_name__* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::component_name* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::lhs_component_name* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::rhs_component_name* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::source_name* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::ground_name* node) 
		{
		}

		virtual void ListenExit(const dcan::ast::node::node_name* node) 
		{
		}


		
		virtual void EnterTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void ExitTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void EnterNonTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void ExitNonTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void EnterAnything(const ::deamer::external::cpp::ast::Node* node) 
		{
		}

		virtual void ExitAnything(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
	};

}}}

#endif // DCAN_AST_LISTENER_ENTEREXITLISTENER_H