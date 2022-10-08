#ifndef dcan_AST_NODE_program_H
#define dcan_AST_NODE_program_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class program : public dcan<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_program_H
