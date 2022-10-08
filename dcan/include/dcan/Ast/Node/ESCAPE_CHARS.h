#ifndef dcan_AST_NODE_ESCAPE_CHARS_H
#define dcan_AST_NODE_ESCAPE_CHARS_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class ESCAPE_CHARS : public dcan<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_ESCAPE_CHARS_H
