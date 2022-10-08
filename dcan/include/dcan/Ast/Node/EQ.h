#ifndef dcan_AST_NODE_EQ_H
#define dcan_AST_NODE_EQ_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class EQ : public dcan<EQ>
	{
	private:
	public:
		EQ(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<EQ>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_EQ_H
