#ifndef dcan_AST_NODE_dcan_H
#define dcan_AST_NODE_dcan_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace dcan { namespace ast { namespace node {

	template<typename Derived>
	class dcan : public ::deamer::external::cpp::ast::TemplateNodeBase<dcan<Derived>, Derived>
	{
	private:
		
	public:
		dcan() = default;
		
		dcan(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<dcan<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // dcan_AST_NODE_dcan_H
