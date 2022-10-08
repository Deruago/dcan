#ifndef dcan_AST_NODE_resistance_value_H
#define dcan_AST_NODE_resistance_value_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class resistance_value : public dcan<resistance_value>
	{
	private:
	public:
		resistance_value(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<resistance_value>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_resistance_value_H
