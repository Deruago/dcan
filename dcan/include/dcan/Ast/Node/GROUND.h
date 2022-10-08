#ifndef dcan_AST_NODE_GROUND_H
#define dcan_AST_NODE_GROUND_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class GROUND : public dcan<GROUND>
	{
	private:
	public:
		GROUND(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<GROUND>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_GROUND_H
