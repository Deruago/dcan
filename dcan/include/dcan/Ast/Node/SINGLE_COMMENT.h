#ifndef dcan_AST_NODE_SINGLE_COMMENT_H
#define dcan_AST_NODE_SINGLE_COMMENT_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class SINGLE_COMMENT : public dcan<SINGLE_COMMENT>
	{
	private:
	public:
		SINGLE_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<SINGLE_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_SINGLE_COMMENT_H
