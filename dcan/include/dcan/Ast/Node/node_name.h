#ifndef dcan_AST_NODE_node_name_H
#define dcan_AST_NODE_node_name_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class node_name : public dcan<node_name>
	{
	private:
	public:
		node_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<node_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_node_name_H
