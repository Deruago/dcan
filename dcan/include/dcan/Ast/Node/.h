#ifndef dcan_AST_NODE__H
#define dcan_AST_NODE__H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class  : public dcan<>
	{
	private:
	public:
		(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE__H
