#ifndef dcan_AST_NODE_source_name_H
#define dcan_AST_NODE_source_name_H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class source_name : public dcan<source_name>
	{
	private:
	public:
		source_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<source_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_source_name_H
