#ifndef dcan_AST_NODE_RESISTANCE_H
#define dcan_AST_NODE_RESISTANCE_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class RESISTANCE : public dcan<RESISTANCE>
	{
	private:
	public:
		RESISTANCE(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<RESISTANCE>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_RESISTANCE_H
