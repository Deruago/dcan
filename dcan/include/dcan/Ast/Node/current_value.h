#ifndef dcan_AST_NODE_current_value_H
#define dcan_AST_NODE_current_value_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class current_value : public dcan<current_value>
	{
	private:
	public:
		current_value(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<current_value>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_current_value_H
