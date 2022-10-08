#ifndef dcan_AST_NODE_lhs_component_name_H
#define dcan_AST_NODE_lhs_component_name_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class lhs_component_name : public dcan<lhs_component_name>
	{
	private:
	public:
		lhs_component_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<lhs_component_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_lhs_component_name_H
