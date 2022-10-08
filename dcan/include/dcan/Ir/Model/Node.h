#ifndef DCAN_IR_MODEL_NODE_H
#define DCAN_IR_MODEL_NODE_H

#include "dcan/Ir/Model/Element.h"
#include <memory>
#include <optional>
#include <set>
#include <string>

namespace dcan::ir::model
{
	class Source;
	class Model;

	class Node
	{
	private:
		std::string nodeName;
		Model* model;
		bool isGenerated;

		std::set<Node*> aliasedNodes;
		std::set<Element*> linkedElements;
		std::optional<int> voltage;

	public:
		Node(Model* model_, const std::string& nodeName_, bool isGenerated_ = true);
		~Node() = default;

	public:
		std::string GetNodeName() const;
		void SetGround();

		void Merge(Node* rhs);
		void LinkWithSource(Source* rhs);

		bool IsGenerated();
		std::set<Element*> GetLinkedElements();
		void AddLinkedElement(Element* element);
		void RemoveElement(Element* value);

		bool IsPartOfCircuit();
		std::set<Node*> GetAliasedNodes();
		std::vector<Element*> GetLinkedElementsVector();
	};
}

#endif // DCAN_IR_MODEL_NODE_H
