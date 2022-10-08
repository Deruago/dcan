#ifndef dcan_AST_NODE_node_declaration_H
#define dcan_AST_NODE_node_declaration_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class node_declaration : public dcan<node_declaration>
	{
	private:
	public:
		node_declaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<node_declaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_node_declaration_H
