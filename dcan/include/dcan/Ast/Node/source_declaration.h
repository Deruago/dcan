#ifndef dcan_AST_NODE_source_declaration_H
#define dcan_AST_NODE_source_declaration_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class source_declaration : public dcan<source_declaration>
	{
	private:
	public:
		source_declaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<source_declaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_source_declaration_H
