#ifndef dcan_AST_NODE_NUMBER_H
#define dcan_AST_NODE_NUMBER_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class NUMBER : public dcan<NUMBER>
	{
	private:
	public:
		NUMBER(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<NUMBER>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_NUMBER_H
