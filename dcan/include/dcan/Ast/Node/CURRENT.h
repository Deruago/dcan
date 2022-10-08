#ifndef dcan_AST_NODE_CURRENT_H
#define dcan_AST_NODE_CURRENT_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class CURRENT : public dcan<CURRENT>
	{
	private:
	public:
		CURRENT(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<CURRENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_CURRENT_H
