#ifndef dcan_AST_NODE_stmt_H
#define dcan_AST_NODE_stmt_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class stmt : public dcan<stmt>
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_stmt_H
