#ifndef dcan_AST_NODE_MIN_H
#define dcan_AST_NODE_MIN_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class MIN : public dcan<MIN>
	{
	private:
	public:
		MIN(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<MIN>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_MIN_H
