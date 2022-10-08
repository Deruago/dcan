#ifndef dcan_AST_NODE_NODE_H
#define dcan_AST_NODE_NODE_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class NODE : public dcan<NODE>
	{
	private:
	public:
		NODE(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<NODE>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_NODE_H
