#ifndef dcan_AST_NODE_deamerreserved_star__stmt___H
#define dcan_AST_NODE_deamerreserved_star__stmt___H

#include "dcan/Ast/Node/dcan.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dcan { namespace ast { namespace node { 

	class deamerreserved_star__stmt__ : public dcan<deamerreserved_star__stmt__>
	{
	private:
	public:
		deamerreserved_star__stmt__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dcan<deamerreserved_star__stmt__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dcan_AST_NODE_deamerreserved_star__stmt___H
