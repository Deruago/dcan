#ifndef dcan_AST_NODE_IDEAL_SOURCE_H
#define dcan_AST_NODE_IDEAL_SOURCE_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class IDEAL_SOURCE : public dcan<IDEAL_SOURCE>
	{
	private:
	public:
		IDEAL_SOURCE(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<IDEAL_SOURCE>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_IDEAL_SOURCE_H
