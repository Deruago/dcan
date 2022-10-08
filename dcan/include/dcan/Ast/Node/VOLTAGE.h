#ifndef dcan_AST_NODE_VOLTAGE_H
#define dcan_AST_NODE_VOLTAGE_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node {

	class VOLTAGE : public dcan<VOLTAGE>
	{
	private:
	public:
		VOLTAGE(deamer::external::cpp::ast::NodeInformation information_)
		: dcan<VOLTAGE>(information_, {}, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_VOLTAGE_H
