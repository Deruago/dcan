#include "dcan/Ir/Model/Model.h"

void dcan::ir::model::Model::NodeIsMerged(Node* rhs)
{
	for (auto iter = std::begin(nodesInCircuit); iter != std::end(nodesInCircuit); ++iter)
	{
		if ((*iter)->GetNodeName() == rhs->GetNodeName())
		{
			nodesInCircuit.erase(iter);
			return;
		}
	}
}

dcan::ir::model::Node* dcan::ir::model::Model::GetNode(const std::string& nodeName)
{
	for (auto& node : nodes)
	{
		if (node->GetNodeName() == nodeName)
		{
			return node.get();
		}
	}
	return nullptr;
}

dcan::ir::model::Node* dcan::ir::model::Model::CreateNode(const std::string& nodeName,
														  bool isGenerated)
{
	auto newNode = std::make_unique<Node>(this, nodeName, isGenerated);
	auto newNodePtr = newNode.get();
	nodesInCircuit.push_back(newNodePtr);
	nodes.push_back(std::move(newNode));
	return newNodePtr;
}

dcan::ir::model::Element* dcan::ir::model::Model::CreateElement(const std::string& nodeName,
																ElementType type)
{
	auto newNode = std::make_unique<Source>(this, nodeName);
	auto newNodePtr = newNode.get();
	elements.push_back(std::move(newNode));
	return newNodePtr;
}

dcan::ir::model::Element*
dcan::ir::model::Model::CreateElement(const std::vector<std::string>& nodeNames, ElementType type)
{
	auto newNode = std::make_unique<Source>(this, nodeNames);
	auto newNodePtr = newNode.get();
	elements.push_back(std::move(newNode));
	return newNodePtr;
}

dcan::ir::model::Source* dcan::ir::model::Model::GetSource(const std::string& sourceName)
{
	for (auto& node : elements)
	{
		if (node->GetElementName() == sourceName)
		{
			return static_cast<Source*>(node.get());
		}
	}
	return nullptr;
}

dcan::ir::model::Node* dcan::ir::model::Model::CreateAutoNode()
{
	static int counter = 0;
	std::string automaticName = "auto" + std::to_string(counter++);

	return CreateNode(automaticName, true);
}

std::vector<dcan::ir::model::Node*> dcan::ir::model::Model::GetNodesCircuit()
{
	return nodesInCircuit;
}

bool dcan::ir::model::Model::IsNodePartOfCircuit(Node* node)
{
	for (auto circuitNode : nodesInCircuit)
	{
		if (circuitNode->GetNodeName() == node->GetNodeName())
		{
			return true;
		}
	}

	return false;
}

std::vector<dcan::ir::model::Element*> dcan::ir::model::Model::GetElements()
{
	std::vector<dcan::ir::model::Element*> result;
	for (auto& element : elements)
	{
		result.push_back(element.get());
	}
	return result;
}

std::vector<dcan::ir::model::Element*> dcan::ir::model::Model::GetElementsInCircuit()
{
	std::set<dcan::ir::model::Element*> elementsInCircuit;
	for (auto node : nodesInCircuit)
	{
		for (auto element : node->GetLinkedElementsVector())
		{
			elementsInCircuit.insert(element);
		}
	}

	std::vector<dcan::ir::model::Element*> result;
	for (auto element : elementsInCircuit)
	{
		result.push_back(element);
	}
	return result;
}

void dcan::ir::model::Model::Simplify()
{
	bool somethingChanged = false;
	do
	{
		somethingChanged = false;
		// Remove elements that are connected to themselves
		for (auto& element : GetElementsInCircuit())
		{
			if (element->GetInput() != element->GetOutput())
			{
				continue;
			}

			NodeIsMerged(element->GetInput());
			element->GetInput()->RemoveElement(element);
			somethingChanged = true;
		}

		// Remove elements that are connected to nodes that only have 1 element connected
		// These are dead-ends and thus useless
		for (auto& element : GetElementsInCircuit())
		{
			if (element->GetInput()->GetLinkedElementsVector().size() == 1)
			{
				NodeIsMerged(element->GetInput());
				element->GetInput()->RemoveElement(element);
				element->GetOutput()->RemoveElement(element);
				somethingChanged = true;
			}
			else if (element->GetOutput()->GetLinkedElementsVector().size() == 1)
			{
				NodeIsMerged(element->GetOutput());
				element->GetOutput()->RemoveElement(element);
				element->GetInput()->RemoveElement(element);
				somethingChanged = true;
			}
		}

		// Combine elements whenever possible
		for (auto element : GetElementsInCircuit())
		{
			auto source = static_cast<Source*>(element);
			if (source->GetElementType() == ElementType::resistor)
			{
			}
			else if (source->GetElementType() == ElementType::voltage)
			{
			}
			else if (source->GetElementType() == ElementType::current)
			{
				auto outputNode = source->GetOutput();
				if (outputNode->GetLinkedElements().size() == 2 && outputNode->IsGenerated())
				{
					auto lhs = outputNode->GetLinkedElementsVector()[0];
					auto rhs = outputNode->GetLinkedElementsVector()[1];
					if (!(lhs->GetElementType() == ElementType::current &&
						  rhs->GetElementType() == ElementType::current))
					{
						continue;
					}

					if (lhs != source)
					{
						if (rhs != source)
						{
							continue;
						}
						auto tmp = lhs;
						lhs = rhs;
						rhs = tmp;
					}

					if (rhs->GetInput() == outputNode)
					{
						// Add both current sources
						// i.e. lhs.current + rhs.current
						auto newElement =
							CreateElement({lhs->GetElementName() + " + " + rhs->GetElementName()},
										  ElementType::current);
						NodeIsMerged(newElement->GetInput());
						NodeIsMerged(newElement->GetOutput());
						newElement->ReplaceNode(newElement->GetInput(), source->GetInput());
						newElement->ReplaceNode(newElement->GetOutput(), rhs->GetOutput());
						static_cast<Source*>(newElement)
							->AssignCurrent(static_cast<Source*>(lhs)->GetCurrent() +
											static_cast<Source*>(rhs)->GetCurrent());
					}
					else
					{
						// Substract rhs from lhs
						// i.e. lhs.current - rhs.current
						auto newElement =
							CreateElement({lhs->GetElementName() + " - " + rhs->GetElementName()},
										  ElementType::current);
						NodeIsMerged(newElement->GetInput());
						NodeIsMerged(newElement->GetOutput());
						newElement->ReplaceNode(newElement->GetInput(), source->GetInput());
						newElement->ReplaceNode(newElement->GetOutput(), rhs->GetInput());
						static_cast<Source*>(newElement)
							->AssignCurrent(static_cast<Source*>(lhs)->GetCurrent() -
											static_cast<Source*>(rhs)->GetCurrent());
					}

					lhs->GetInput()->RemoveElement(lhs);
					lhs->GetOutput()->RemoveElement(lhs);
					rhs->GetInput()->RemoveElement(rhs);
					rhs->GetOutput()->RemoveElement(rhs);
					lhs->GetInput()->RemoveElement(rhs);
					lhs->GetOutput()->RemoveElement(rhs);
					rhs->GetInput()->RemoveElement(lhs);
					rhs->GetOutput()->RemoveElement(lhs);

					NodeIsMerged(outputNode);
					somethingChanged = true;
				}
			}
		}

		// Use color model to simplify parallel resistors
	} while (!somethingChanged);
}
