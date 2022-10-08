#ifndef DCAN_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DCAN_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "dcan/Ast/Relation/NodeEnumToType.h"
#include "dcan/Ast/Relation/NodeTypeToEnum.h"
#include "dcan/Ast/Relation/NodeIsInlined.h"

#include "dcan/Ast/Enum/Type.h"
#include "dcan/Ast/Node/program.h"
#include "dcan/Ast/Node/deamerreserved_star__stmt__.h"
#include "dcan/Ast/Node/stmt.h"
#include "dcan/Ast/Node/node_declaration.h"
#include "dcan/Ast/Node/ground_declaration.h"
#include "dcan/Ast/Node/source_declaration.h"
#include "dcan/Ast/Node/assignment.h"
#include "dcan/Ast/Node/unit_value.h"
#include "dcan/Ast/Node/current_value.h"
#include "dcan/Ast/Node/voltage_value.h"
#include "dcan/Ast/Node/resistance_value.h"
#include "dcan/Ast/Node/value.h"
#include "dcan/Ast/Node/connection.h"
#include "dcan/Ast/Node/deamerreserved_plus__MIN__component_name__.h"
#include "dcan/Ast/Node/component_name.h"
#include "dcan/Ast/Node/lhs_component_name.h"
#include "dcan/Ast/Node/rhs_component_name.h"
#include "dcan/Ast/Node/source_name.h"
#include "dcan/Ast/Node/ground_name.h"
#include "dcan/Ast/Node/node_name.h"
#include "dcan/Ast/Node/SINGLE_COMMENT.h"
#include "dcan/Ast/Node/MULTI_COMMENT.h"
#include "dcan/Ast/Node/CURRENT.h"
#include "dcan/Ast/Node/VOLTAGE.h"
#include "dcan/Ast/Node/RESISTANCE.h"
#include "dcan/Ast/Node/NODE.h"
#include "dcan/Ast/Node/IDEAL_SOURCE.h"
#include "dcan/Ast/Node/GROUND.h"
#include "dcan/Ast/Node/VARNAME.h"
#include "dcan/Ast/Node/NUMBER.h"
#include "dcan/Ast/Node/MIN.h"
#include "dcan/Ast/Node/EQ.h"
#include "dcan/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace dcan { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::dcan::ast::Type T>
		void Get(std::vector<const ::dcan::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::dcan::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::dcan::ast::relation::NodeIsInlined(static_cast<::dcan::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::dcan::ast::Type T, typename Q>
		inline std::vector<const ::dcan::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::dcan::ast::relation::NodeEnumToType_t<T>*> foundNodes;

			for (const auto* const currentNode : currentNodes)
			{
				AccessBase::Get<T>(foundNodes, currentNode);
			}

			return foundNodes;
		}
	};

	/*!	\class AccessTemplateBase
	 *
	 *	\brief Used to access AST nodes. It contains various helper functions to ease navigation through AST nodes.
	 *
	 *	\details This class contains the type dependent implementation of Access<T>.
	 *	Refrain from using this class, as there is no backwards compatibility
	 *	guarantee of this implementation class,
	 *	Use Access<T> instead, this is backwards compatible and offers different benefits.
	 *
	 *	\see Access
	 */
	template<typename T>
	struct AccessTemplateBase : public AccessBase
	{
		AccessTemplateBase() = delete;
		~AccessTemplateBase() = delete;
	};

	/*! \class Access
	 *
	 *	\brief Used to access AST nodes. It contains various helper functions to ease navigation through AST nodes.
	 *
	 *	\details Type dispatcher for logic.
	 *
	 *	\see AccessTemplateBase
	 */
	template<typename T>
	struct Access : public AccessTemplateBase<T>
	{
		Access(std::vector<const T*> ts_) : AccessTemplateBase<T>(ts_)
		{
		}

		Access(const T& t) : AccessTemplateBase<T>(t)
		{
		}

		Access(const T* t) : AccessTemplateBase<T>(t)
		{
		}

		Access(const AccessTemplateBase<T>& rhs) : AccessTemplateBase<T>(rhs)
		{
		}

		Access() = default;
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::program>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::node_declaration>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::ground_declaration>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::source_declaration>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::assignment>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::unit_value>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::current_value>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::voltage_value>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::resistance_value>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::value>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::connection>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::component_name>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::lhs_component_name>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::rhs_component_name>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::source_name>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::ground_name>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::node_name>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::SINGLE_COMMENT>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::MULTI_COMMENT>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::CURRENT>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::VOLTAGE>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::RESISTANCE>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::NODE>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::GROUND>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::MIN>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::EQ>;
	template<>
	struct AccessTemplateBase<::dcan::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::dcan::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::program>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::dcan::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::program>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::dcan::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::stmt>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::node_declaration> node_declaration();
AccessTemplateBase<::dcan::ast::node::ground_declaration> ground_declaration();
AccessTemplateBase<::dcan::ast::node::source_declaration> source_declaration();
AccessTemplateBase<::dcan::ast::node::assignment> assignment();
AccessTemplateBase<::dcan::ast::node::connection> connection();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::stmt>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::node_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::node_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::node_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::node_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::node_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::node_declaration>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::node_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::node_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::node_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::node_name> node_name();
AccessTemplateBase<::dcan::ast::node::NODE> NODE();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::node_declaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::ground_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::ground_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::ground_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::ground_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::ground_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::ground_declaration>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::ground_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::ground_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::ground_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::ground_name> ground_name();
AccessTemplateBase<::dcan::ast::node::GROUND> GROUND();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::ground_declaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::source_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::source_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::source_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::source_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::source_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::source_declaration>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::source_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::source_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::source_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::source_name> source_name();
AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE> IDEAL_SOURCE();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::source_declaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::assignment> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::assignment*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::assignment*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::assignment& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::assignment* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::assignment>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::assignment>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::assignment*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::assignment*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::unit_value> unit_value();
AccessTemplateBase<::dcan::ast::node::lhs_component_name> lhs_component_name();
AccessTemplateBase<::dcan::ast::node::EQ> EQ();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::assignment>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::unit_value> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::unit_value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::unit_value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::unit_value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::unit_value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::unit_value>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::unit_value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::unit_value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::unit_value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::current_value> current_value();
AccessTemplateBase<::dcan::ast::node::voltage_value> voltage_value();
AccessTemplateBase<::dcan::ast::node::resistance_value> resistance_value();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::unit_value>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::current_value> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::current_value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::current_value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::current_value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::current_value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::current_value>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::current_value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::current_value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::current_value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::value> value();
AccessTemplateBase<::dcan::ast::node::CURRENT> CURRENT();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::current_value>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::voltage_value> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::voltage_value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::voltage_value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::voltage_value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::voltage_value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::voltage_value>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::voltage_value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::voltage_value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::voltage_value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::value> value();
AccessTemplateBase<::dcan::ast::node::VOLTAGE> VOLTAGE();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::voltage_value>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::resistance_value> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::resistance_value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::resistance_value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::resistance_value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::resistance_value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::resistance_value>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::resistance_value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::resistance_value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::resistance_value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::value> value();
AccessTemplateBase<::dcan::ast::node::RESISTANCE> RESISTANCE();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::resistance_value>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::value> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::value>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::value>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::connection> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::connection*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::connection*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::connection& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::connection* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::connection>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::connection>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::connection*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::connection*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__> deamerreserved_plus__MIN__component_name__();
AccessTemplateBase<::dcan::ast::node::component_name> component_name();
AccessTemplateBase<::dcan::ast::node::MIN> MIN();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::connection>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::deamerreserved_plus__MIN__component_name__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__> deamerreserved_plus__MIN__component_name__();
AccessTemplateBase<::dcan::ast::node::component_name> component_name();
AccessTemplateBase<::dcan::ast::node::MIN> MIN();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::component_name> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::component_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::component_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::component_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::component_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::component_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::component_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::component_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::component_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::component_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::lhs_component_name> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::lhs_component_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::lhs_component_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::lhs_component_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::lhs_component_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::lhs_component_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::lhs_component_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::lhs_component_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::lhs_component_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::lhs_component_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::rhs_component_name> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::rhs_component_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::rhs_component_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::rhs_component_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::rhs_component_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::rhs_component_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::rhs_component_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::rhs_component_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::rhs_component_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::rhs_component_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::source_name> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::source_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::source_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::source_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::source_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::source_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::source_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::source_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::source_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::source_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::ground_name> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::ground_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::ground_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::ground_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::ground_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::ground_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::ground_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::ground_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::ground_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::ground_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::node_name> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::node_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::node_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::node_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::node_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::node_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::node_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::node_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::node_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dcan::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::node_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::SINGLE_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::SINGLE_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::SINGLE_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::SINGLE_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::SINGLE_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::SINGLE_COMMENT>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::SINGLE_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::SINGLE_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::SINGLE_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::SINGLE_COMMENT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::MULTI_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::MULTI_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::MULTI_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::MULTI_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::MULTI_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::MULTI_COMMENT>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::MULTI_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::MULTI_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::MULTI_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::MULTI_COMMENT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::CURRENT> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::CURRENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::CURRENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::CURRENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::CURRENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::CURRENT>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::CURRENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::CURRENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::CURRENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::CURRENT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::VOLTAGE> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::VOLTAGE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::VOLTAGE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::VOLTAGE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::VOLTAGE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::VOLTAGE>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::VOLTAGE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::VOLTAGE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::VOLTAGE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::VOLTAGE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::RESISTANCE> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::RESISTANCE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::RESISTANCE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::RESISTANCE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::RESISTANCE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::RESISTANCE>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::RESISTANCE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::RESISTANCE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::RESISTANCE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::RESISTANCE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::NODE> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::NODE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::NODE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::NODE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::NODE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::NODE>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::NODE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::NODE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::NODE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::NODE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::IDEAL_SOURCE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::IDEAL_SOURCE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::IDEAL_SOURCE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::IDEAL_SOURCE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::IDEAL_SOURCE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::IDEAL_SOURCE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::GROUND> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::GROUND*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::GROUND*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::GROUND& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::GROUND* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::GROUND>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::GROUND>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::GROUND*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::GROUND*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::GROUND>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::VARNAME>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::VARNAME>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::NUMBER>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::NUMBER>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::MIN> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::MIN*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::MIN*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::MIN& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::MIN* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::MIN>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::MIN>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::MIN*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::MIN*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::MIN>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::EQ> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::EQ*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::EQ*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::EQ& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::EQ* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::EQ>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::EQ>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::EQ*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::EQ*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::EQ>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dcan::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::dcan::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dcan::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dcan::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dcan::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dcan::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dcan::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dcan::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dcan::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};


	
		inline AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::dcan::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>(Get<::dcan::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::stmt> AccessTemplateBase<::dcan::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::stmt>(Get<::dcan::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>(Get<::dcan::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::stmt> AccessTemplateBase<::dcan::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::stmt>(Get<::dcan::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::node_declaration> AccessTemplateBase<::dcan::ast::node::stmt>::node_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::node_declaration>(Get<::dcan::ast::Type::node_declaration>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::ground_declaration> AccessTemplateBase<::dcan::ast::node::stmt>::ground_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::ground_declaration>(Get<::dcan::ast::Type::ground_declaration>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::source_declaration> AccessTemplateBase<::dcan::ast::node::stmt>::source_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::source_declaration>(Get<::dcan::ast::Type::source_declaration>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::assignment> AccessTemplateBase<::dcan::ast::node::stmt>::assignment()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::assignment>(Get<::dcan::ast::Type::assignment>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::connection> AccessTemplateBase<::dcan::ast::node::stmt>::connection()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::connection>(Get<::dcan::ast::Type::connection>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::node_name> AccessTemplateBase<::dcan::ast::node::node_declaration>::node_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::node_name>(Get<::dcan::ast::Type::node_name>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::NODE> AccessTemplateBase<::dcan::ast::node::node_declaration>::NODE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::NODE>(Get<::dcan::ast::Type::NODE>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::ground_name> AccessTemplateBase<::dcan::ast::node::ground_declaration>::ground_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::ground_name>(Get<::dcan::ast::Type::ground_name>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::GROUND> AccessTemplateBase<::dcan::ast::node::ground_declaration>::GROUND()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::GROUND>(Get<::dcan::ast::Type::GROUND>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::source_name> AccessTemplateBase<::dcan::ast::node::source_declaration>::source_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::source_name>(Get<::dcan::ast::Type::source_name>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE> AccessTemplateBase<::dcan::ast::node::source_declaration>::IDEAL_SOURCE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::IDEAL_SOURCE>(Get<::dcan::ast::Type::IDEAL_SOURCE>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::unit_value> AccessTemplateBase<::dcan::ast::node::assignment>::unit_value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::unit_value>(Get<::dcan::ast::Type::unit_value>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::lhs_component_name> AccessTemplateBase<::dcan::ast::node::assignment>::lhs_component_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::lhs_component_name>(Get<::dcan::ast::Type::lhs_component_name>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::EQ> AccessTemplateBase<::dcan::ast::node::assignment>::EQ()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::EQ>(Get<::dcan::ast::Type::EQ>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::current_value> AccessTemplateBase<::dcan::ast::node::unit_value>::current_value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::current_value>(Get<::dcan::ast::Type::current_value>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::voltage_value> AccessTemplateBase<::dcan::ast::node::unit_value>::voltage_value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::voltage_value>(Get<::dcan::ast::Type::voltage_value>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::resistance_value> AccessTemplateBase<::dcan::ast::node::unit_value>::resistance_value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::resistance_value>(Get<::dcan::ast::Type::resistance_value>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::value> AccessTemplateBase<::dcan::ast::node::current_value>::value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::value>(Get<::dcan::ast::Type::value>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::CURRENT> AccessTemplateBase<::dcan::ast::node::current_value>::CURRENT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::CURRENT>(Get<::dcan::ast::Type::CURRENT>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::value> AccessTemplateBase<::dcan::ast::node::voltage_value>::value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::value>(Get<::dcan::ast::Type::value>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::VOLTAGE> AccessTemplateBase<::dcan::ast::node::voltage_value>::VOLTAGE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::VOLTAGE>(Get<::dcan::ast::Type::VOLTAGE>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::value> AccessTemplateBase<::dcan::ast::node::resistance_value>::value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::value>(Get<::dcan::ast::Type::value>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::RESISTANCE> AccessTemplateBase<::dcan::ast::node::resistance_value>::RESISTANCE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::RESISTANCE>(Get<::dcan::ast::Type::RESISTANCE>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::NUMBER> AccessTemplateBase<::dcan::ast::node::value>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::NUMBER>(Get<::dcan::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__> AccessTemplateBase<::dcan::ast::node::connection>::deamerreserved_plus__MIN__component_name__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>(Get<::dcan::ast::Type::deamerreserved_plus__MIN__component_name__>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::component_name> AccessTemplateBase<::dcan::ast::node::connection>::component_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::component_name>(Get<::dcan::ast::Type::component_name>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::MIN> AccessTemplateBase<::dcan::ast::node::connection>::MIN()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::MIN>(Get<::dcan::ast::Type::MIN>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__> AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>::deamerreserved_plus__MIN__component_name__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>(Get<::dcan::ast::Type::deamerreserved_plus__MIN__component_name__>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::component_name> AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>::component_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::component_name>(Get<::dcan::ast::Type::component_name>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::MIN> AccessTemplateBase<::dcan::ast::node::deamerreserved_plus__MIN__component_name__>::MIN()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::MIN>(Get<::dcan::ast::Type::MIN>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::VARNAME> AccessTemplateBase<::dcan::ast::node::component_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::VARNAME>(Get<::dcan::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::VARNAME> AccessTemplateBase<::dcan::ast::node::lhs_component_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::VARNAME>(Get<::dcan::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::VARNAME> AccessTemplateBase<::dcan::ast::node::rhs_component_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::VARNAME>(Get<::dcan::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::VARNAME> AccessTemplateBase<::dcan::ast::node::source_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::VARNAME>(Get<::dcan::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::VARNAME> AccessTemplateBase<::dcan::ast::node::ground_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::VARNAME>(Get<::dcan::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::dcan::ast::node::VARNAME> AccessTemplateBase<::dcan::ast::node::node_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dcan::ast::node::VARNAME>(Get<::dcan::ast::Type::VARNAME>(ts));
		}


	/*!	\class Access_if
	 *
	 *	\brief Accesses the node if it is of the given type.
	 *
	 *	\note A lambda has to be supplied as second argument with paramater: "Access<T>".
	 */
	template<typename T>
	struct Access_if
	{
		const ::deamer::external::cpp::ast::Node* node;

		template<typename FunctionType>
		Access_if(const ::deamer::external::cpp::ast::Node* node_, FunctionType function) : node(node_)
		{
			if (node->GetType() == static_cast<::std::size_t>(::dcan::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DCAN_AST_REFERENCE_ACCESSTEMPLATEBASE_H