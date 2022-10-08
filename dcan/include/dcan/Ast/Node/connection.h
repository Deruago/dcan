#ifndef dcan_AST_NODE_connection_H
#define dcan_AST_NODE_connection_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class connection : public dcan<connection>
	{
	private:
	public:
		connection(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<connection>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_connection_H
