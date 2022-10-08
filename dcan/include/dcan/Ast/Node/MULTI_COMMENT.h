#ifndef dcan_AST_NODE_MULTI_COMMENT_H
#define dcan_AST_NODE_MULTI_COMMENT_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class MULTI_COMMENT : public dcan<MULTI_COMMENT>
	{
	private:
	public:
		MULTI_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<MULTI_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_MULTI_COMMENT_H
