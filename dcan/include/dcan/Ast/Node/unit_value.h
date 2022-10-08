#ifndef dcan_AST_NODE_unit_value_H
#define dcan_AST_NODE_unit_value_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class unit_value : public dcan<unit_value>
	{
	private:
	public:
		unit_value(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<unit_value>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_unit_value_H
