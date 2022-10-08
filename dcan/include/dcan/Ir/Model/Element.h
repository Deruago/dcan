#ifndef DCAN_IR_MODEL_ELEMENT_H
#define DCAN_IR_MODEL_ELEMENT_H

#include "dcan/Ir/Model/ElementType.h"
#include <memory>
#include <string>
#include <vector>

namespace dcan::ir::model
{
	class Node;
	class Model;
	class Source;

	class Element
	{
	private:
		ElementType type;
		std::vector<std::string> elementNames;

		Model* model;
		Node* output = nullptr;
		Node* input = nullptr;

	public:
		Element(Model* model_, ElementType type_, const std::vector<std::string>& elementNames_);
		Element(Model* model_, ElementType type_, const std::string& elementName_);
		Element(Model* model_, ElementType type_);
		~Element() = default;

	public:
		Node* GetOutput() const;
		Node* GetInput() const;

		std::string GetElementName() const;
		ElementType GetElementType() const;

	public:
		void LinkWithNode(Node* rhs);
		void LinkWithSource(Source* rhs);
		void ReplaceNode(Node* rhs, Node* node);

	protected:
		ElementType GetType();
		void SetType(ElementType type_);
	};
}

#endif // DCAN_IR_MODEL_ELEMENT_H
