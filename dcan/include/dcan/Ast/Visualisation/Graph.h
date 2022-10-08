#ifndef DCAN_AST_VISUALISATION_GRAPH_H
#define DCAN_AST_VISUALISATION_GRAPH_H

#include "dcan/Ast/Listener/EnterExitListener.h"

namespace dcan { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph dcan_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::dcan::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::node_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"node_declaration\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::ground_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ground_declaration\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::source_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"source_declaration\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::assignment* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"assignment\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::unit_value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"unit_value\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::current_value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"current_value\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::voltage_value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"voltage_value\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::resistance_value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"resistance_value\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::connection* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"connection\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_plus__MIN__component_name__\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::component_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"component_name\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::lhs_component_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"lhs_component_name\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::rhs_component_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"rhs_component_name\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::source_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"source_name\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::ground_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ground_name\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::node_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"node_name\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::SINGLE_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SINGLE_COMMENT\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::MULTI_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MULTI_COMMENT\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::CURRENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"CURRENT\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::VOLTAGE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VOLTAGE\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::RESISTANCE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RESISTANCE\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::NODE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NODE\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::IDEAL_SOURCE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"IDEAL_SOURCE\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::GROUND* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"GROUND\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::MIN* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MIN\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::EQ* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"EQ\"];\n";
		}

		void ListenEntry(const ::dcan::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::dcan::ast::node::program* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::node_declaration* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::ground_declaration* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::source_declaration* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::assignment* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::unit_value* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::current_value* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::voltage_value* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::resistance_value* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::value* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::connection* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::component_name* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::lhs_component_name* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::rhs_component_name* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::source_name* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::ground_name* node) override
		{
		}

		void ListenExit(const ::dcan::ast::node::node_name* node) override
		{
		}


	public:
		Graph()
		{
			Init();
		}


		std::string GetGraph()
		{
			End();
			return output;
		}
	};

}}}}}

#endif // DCAN_AST_VISUALISATION_GRAPH_H