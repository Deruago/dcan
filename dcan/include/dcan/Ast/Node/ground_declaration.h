#ifndef dcan_AST_NODE_ground_declaration_H
#define dcan_AST_NODE_ground_declaration_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class ground_declaration : public dcan<ground_declaration>
	{
	private:
	public:
		ground_declaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<ground_declaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_ground_declaration_H
