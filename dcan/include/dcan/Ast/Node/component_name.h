#ifndef dcan_AST_NODE_component_name_H
#define dcan_AST_NODE_component_name_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class component_name : public dcan<component_name>
	{
	private:
	public:
		component_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<component_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_component_name_H
