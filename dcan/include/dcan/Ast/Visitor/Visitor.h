#ifndef dcan_AST_VISITOR_DEAMER_VISITOR_H
#define dcan_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
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

namespace dcan { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<dcan::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case dcan::ast::Type::SINGLE_COMMENT:
			{
				Visit(static_cast<const dcan::ast::node::SINGLE_COMMENT*>(node));
				break;
			}
			case dcan::ast::Type::MULTI_COMMENT:
			{
				Visit(static_cast<const dcan::ast::node::MULTI_COMMENT*>(node));
				break;
			}
			case dcan::ast::Type::CURRENT:
			{
				Visit(static_cast<const dcan::ast::node::CURRENT*>(node));
				break;
			}
			case dcan::ast::Type::VOLTAGE:
			{
				Visit(static_cast<const dcan::ast::node::VOLTAGE*>(node));
				break;
			}
			case dcan::ast::Type::RESISTANCE:
			{
				Visit(static_cast<const dcan::ast::node::RESISTANCE*>(node));
				break;
			}
			case dcan::ast::Type::NODE:
			{
				Visit(static_cast<const dcan::ast::node::NODE*>(node));
				break;
			}
			case dcan::ast::Type::IDEAL_SOURCE:
			{
				Visit(static_cast<const dcan::ast::node::IDEAL_SOURCE*>(node));
				break;
			}
			case dcan::ast::Type::GROUND:
			{
				Visit(static_cast<const dcan::ast::node::GROUND*>(node));
				break;
			}
			case dcan::ast::Type::VARNAME:
			{
				Visit(static_cast<const dcan::ast::node::VARNAME*>(node));
				break;
			}
			case dcan::ast::Type::NUMBER:
			{
				Visit(static_cast<const dcan::ast::node::NUMBER*>(node));
				break;
			}
			case dcan::ast::Type::MIN:
			{
				Visit(static_cast<const dcan::ast::node::MIN*>(node));
				break;
			}
			case dcan::ast::Type::EQ:
			{
				Visit(static_cast<const dcan::ast::node::EQ*>(node));
				break;
			}
			case dcan::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const dcan::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case dcan::ast::Type::program:
			{
				Visit(static_cast<const dcan::ast::node::program*>(node));
				break;
			}
			case dcan::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const dcan::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case dcan::ast::Type::stmt:
			{
				Visit(static_cast<const dcan::ast::node::stmt*>(node));
				break;
			}
			case dcan::ast::Type::node_declaration:
			{
				Visit(static_cast<const dcan::ast::node::node_declaration*>(node));
				break;
			}
			case dcan::ast::Type::ground_declaration:
			{
				Visit(static_cast<const dcan::ast::node::ground_declaration*>(node));
				break;
			}
			case dcan::ast::Type::source_declaration:
			{
				Visit(static_cast<const dcan::ast::node::source_declaration*>(node));
				break;
			}
			case dcan::ast::Type::assignment:
			{
				Visit(static_cast<const dcan::ast::node::assignment*>(node));
				break;
			}
			case dcan::ast::Type::unit_value:
			{
				Visit(static_cast<const dcan::ast::node::unit_value*>(node));
				break;
			}
			case dcan::ast::Type::current_value:
			{
				Visit(static_cast<const dcan::ast::node::current_value*>(node));
				break;
			}
			case dcan::ast::Type::voltage_value:
			{
				Visit(static_cast<const dcan::ast::node::voltage_value*>(node));
				break;
			}
			case dcan::ast::Type::resistance_value:
			{
				Visit(static_cast<const dcan::ast::node::resistance_value*>(node));
				break;
			}
			case dcan::ast::Type::value:
			{
				Visit(static_cast<const dcan::ast::node::value*>(node));
				break;
			}
			case dcan::ast::Type::connection:
			{
				Visit(static_cast<const dcan::ast::node::connection*>(node));
				break;
			}
			case dcan::ast::Type::deamerreserved_plus__MIN__component_name__:
			{
				Visit(static_cast<const dcan::ast::node::deamerreserved_plus__MIN__component_name__*>(node));
				break;
			}
			case dcan::ast::Type::component_name:
			{
				Visit(static_cast<const dcan::ast::node::component_name*>(node));
				break;
			}
			case dcan::ast::Type::lhs_component_name:
			{
				Visit(static_cast<const dcan::ast::node::lhs_component_name*>(node));
				break;
			}
			case dcan::ast::Type::rhs_component_name:
			{
				Visit(static_cast<const dcan::ast::node::rhs_component_name*>(node));
				break;
			}
			case dcan::ast::Type::source_name:
			{
				Visit(static_cast<const dcan::ast::node::source_name*>(node));
				break;
			}
			case dcan::ast::Type::ground_name:
			{
				Visit(static_cast<const dcan::ast::node::ground_name*>(node));
				break;
			}
			case dcan::ast::Type::node_name:
			{
				Visit(static_cast<const dcan::ast::node::node_name*>(node));
				break;
			}
			}
		}
		virtual void Visit(const dcan::ast::node::SINGLE_COMMENT* node)
		{
		}
		virtual void Visit(const dcan::ast::node::MULTI_COMMENT* node)
		{
		}
		virtual void Visit(const dcan::ast::node::CURRENT* node)
		{
		}
		virtual void Visit(const dcan::ast::node::VOLTAGE* node)
		{
		}
		virtual void Visit(const dcan::ast::node::RESISTANCE* node)
		{
		}
		virtual void Visit(const dcan::ast::node::NODE* node)
		{
		}
		virtual void Visit(const dcan::ast::node::IDEAL_SOURCE* node)
		{
		}
		virtual void Visit(const dcan::ast::node::GROUND* node)
		{
		}
		virtual void Visit(const dcan::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const dcan::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const dcan::ast::node::MIN* node)
		{
		}
		virtual void Visit(const dcan::ast::node::EQ* node)
		{
		}
		virtual void Visit(const dcan::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const dcan::ast::node::program* node)
		{
		}
		virtual void Visit(const dcan::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const dcan::ast::node::stmt* node)
		{
		}
		virtual void Visit(const dcan::ast::node::node_declaration* node)
		{
		}
		virtual void Visit(const dcan::ast::node::ground_declaration* node)
		{
		}
		virtual void Visit(const dcan::ast::node::source_declaration* node)
		{
		}
		virtual void Visit(const dcan::ast::node::assignment* node)
		{
		}
		virtual void Visit(const dcan::ast::node::unit_value* node)
		{
		}
		virtual void Visit(const dcan::ast::node::current_value* node)
		{
		}
		virtual void Visit(const dcan::ast::node::voltage_value* node)
		{
		}
		virtual void Visit(const dcan::ast::node::resistance_value* node)
		{
		}
		virtual void Visit(const dcan::ast::node::value* node)
		{
		}
		virtual void Visit(const dcan::ast::node::connection* node)
		{
		}
		virtual void Visit(const dcan::ast::node::deamerreserved_plus__MIN__component_name__* node)
		{
		}
		virtual void Visit(const dcan::ast::node::component_name* node)
		{
		}
		virtual void Visit(const dcan::ast::node::lhs_component_name* node)
		{
		}
		virtual void Visit(const dcan::ast::node::rhs_component_name* node)
		{
		}
		virtual void Visit(const dcan::ast::node::source_name* node)
		{
		}
		virtual void Visit(const dcan::ast::node::ground_name* node)
		{
		}
		virtual void Visit(const dcan::ast::node::node_name* node)
		{
		}
	};

}}}

#endif // dcan_AST_VISITOR_DEAMER_VISITOR_H
