#include "dcan/Ir/Model/Element.h"
#include "dcan/Ir/Model/Model.h"
#include "dcan/Ir/Model/Node.h"
#include "dcan/Ir/Model/Source.h"
#include <iostream>

dcan::ir::model::Element::Element(Model* model_, ElementType type_,
								  const std::vector<std::string>& elementNames_)
	: type(type_),
	  elementNames(elementNames_),
	  model(model_)
{
	output = model->CreateAutoNode();
	output->AddLinkedElement(this);
	input = model->CreateAutoNode();
	input->AddLinkedElement(this);
}

dcan::ir::model::Element::Element(Model* model_, ElementType type_, const std::string& elementName_)
	: type(type_),
	  elementNames({elementName_}),
	  model(model_)
{
	output = model->CreateAutoNode();
	output->AddLinkedElement(this);
	input = model->CreateAutoNode();
	input->AddLinkedElement(this);
}

dcan::ir::model::Element::Element(Model* model_, ElementType type_) : type(type_), model(model_)
{
	output = model->CreateAutoNode();
	output->AddLinkedElement(this);
	input = model->CreateAutoNode();
	input->AddLinkedElement(this);
}

dcan::ir::model::Node* dcan::ir::model::Element::GetOutput() const
{
	return output;
}

dcan::ir::model::Node* dcan::ir::model::Element::GetInput() const
{
	return input;
}

std::string dcan::ir::model::Element::GetElementName() const
{
	if (elementNames.empty())
	{
		return {};
	}
	return elementNames[0];
}

dcan::ir::model::ElementType dcan::ir::model::Element::GetElementType() const
{
	return type;
}

void dcan::ir::model::Element::LinkWithNode(Node* rhs)
{
	// Links output with rhs
	if (output->IsGenerated())
	{
		model->NodeIsMerged(output);
		rhs->Merge(output);
		ReplaceNode(output, rhs);
		rhs->AddLinkedElement(this);
	}
	else
	{
		model->NodeIsMerged(rhs);
		output->Merge(rhs);
	}
}

void dcan::ir::model::Element::LinkWithSource(Source* rhs)
{
	// Links output with rhs input
	if (output->IsGenerated())
	{
		model->NodeIsMerged(output);
		rhs->GetInput()->Merge(output);
		ReplaceNode(output, rhs->GetInput());
	}
	else
	{
		model->NodeIsMerged(rhs->GetInput());
		output->Merge(rhs->GetInput());
		rhs->ReplaceNode(rhs->input, output);
	}
}

void dcan::ir::model::Element::ReplaceNode(Node* rhs, Node* node)
{
	if (input == rhs)
	{
		input = node;
		input->AddLinkedElement(this);
	}
	else if (output == rhs)
	{
		output = node;
		output->AddLinkedElement(this);
	}
	else
	{
		std::cout << "Issue\n";
	}
}

dcan::ir::model::ElementType dcan::ir::model::Element::GetType()
{
	return type;
}

void dcan::ir::model::Element::SetType(ElementType type_)
{
	type = type_;
}
