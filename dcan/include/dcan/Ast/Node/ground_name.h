#ifndef dcan_AST_NODE_ground_name_H
#define dcan_AST_NODE_ground_name_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class ground_name : public dcan<ground_name>
	{
	private:
	public:
		ground_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<ground_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_ground_name_H
