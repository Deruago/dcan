#include "dcan/Ir/Model/Node.h"
#include "dcan/Ir/Model/Element.h"
#include "dcan/Ir/Model/Model.h"
#include "dcan/Ir/Model/Source.h"

dcan::ir::model::Node::Node(Model* model_, const std::string& nodeName_, bool isGenerated_)
	: nodeName(nodeName_),
	  model(model_),
	  isGenerated(isGenerated_)
{
}

std::string dcan::ir::model::Node::GetNodeName() const
{
	return nodeName;
}

void dcan::ir::model::Node::SetGround()
{
	voltage = 0;
}

void dcan::ir::model::Node::Merge(Node* rhs)
{
	auto iter = aliasedNodes.find(rhs);
	if (iter != aliasedNodes.end())
	{
		return;
	}

	aliasedNodes.insert(rhs);
	model->NodeIsMerged(rhs);
	for (auto element : rhs->linkedElements)
	{
		element->ReplaceNode(rhs, this);
		linkedElements.insert(element);
	}

	for (auto aliasNode : rhs->aliasedNodes)
	{
		aliasedNodes.insert(aliasNode);
	}
}

void dcan::ir::model::Node::LinkWithSource(Source* rhs)
{
	Merge(rhs->GetInput());
	AddLinkedElement(rhs);
}

bool dcan::ir::model::Node::IsGenerated()
{
	return isGenerated;
}

std::set<dcan::ir::model::Element*> dcan::ir::model::Node::GetLinkedElements()
{
	return linkedElements;
}

void dcan::ir::model::Node::AddLinkedElement(Element* element)
{
	linkedElements.insert(element);
}

void dcan::ir::model::Node::RemoveElement(Element* value)
{
	auto iter = linkedElements.find(value);
	if (iter == linkedElements.end())
	{
		return;
	}

	linkedElements.erase(iter);
}

bool dcan::ir::model::Node::IsPartOfCircuit()
{
	return model->IsNodePartOfCircuit(this);
}

std::set<dcan::ir::model::Node*> dcan::ir::model::Node::GetAliasedNodes()
{
	return aliasedNodes;
}

std::vector<dcan::ir::model::Element*> dcan::ir::model::Node::GetLinkedElementsVector()
{
	std::vector<dcan::ir::model::Element*> result;
	for (auto element : linkedElements)
	{
		result.push_back(element);
	}
	return result;
}
