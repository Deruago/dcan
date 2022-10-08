#ifndef dcan_AST_NODE_VARNAME_H
#define dcan_AST_NODE_VARNAME_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class VARNAME : public dcan<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_VARNAME_H
