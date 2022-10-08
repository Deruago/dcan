#ifndef dcan_AST_NODE_assignment_H
#define dcan_AST_NODE_assignment_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class assignment : public dcan<assignment>
	{
	private:
	public:
		assignment(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<assignment>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_assignment_H
