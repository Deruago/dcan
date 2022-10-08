#ifndef DCAN_IR_MODEL_MODEL_H
#define DCAN_IR_MODEL_MODEL_H

#include "dcan/Ir/Model/Element.h"
#include "dcan/Ir/Model/Node.h"
#include "dcan/Ir/Model/Source.h"
#include <memory>
#include <string>
#include <vector>

namespace dcan::ir::model
{
	class Model
	{
	private:
		std::vector<Node*> nodesInCircuit;
		std::vector<std::unique_ptr<Node>> nodes;
		std::vector<std::unique_ptr<Element>> elements;

	public:
		Model() = default;
		~Model() = default;

	public:
		void NodeIsMerged(Node* rhs);

		Node* GetNode(const std::string& nodeName);
		Node* CreateNode(const std::string& nodeName, bool isGenerated = true);
		Element* CreateElement(const std::string& nodeName, ElementType type);
		Element* CreateElement(const std::vector<std::string>& nodeNames, ElementType type);
		Source* GetSource(const std::string& sourceName);
		Node* CreateAutoNode();

		std::vector<Node*> GetNodesCircuit();
		bool IsNodePartOfCircuit(Node* node);
		std::vector<dcan::ir::model::Element*> GetElements();
		std::vector<dcan::ir::model::Element*> GetElementsInCircuit();
		void Simplify();
	};
}

#endif // DCAN_IR_MODEL_MODEL_H
