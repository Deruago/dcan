#include "dcan/Ast/Listener/User/ModelExtractor.h"
#include "dcan/Ast/Visualisation/Graph.h"
#include "dcan/Bison/Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string ReadInFile(const std::string& file)
{
	const std::ifstream inputFile(file);

	std::ostringstream sstr;
	sstr << inputFile.rdbuf();

	std::string input = sstr.str();

	return input;
}

int main(int argc, const char* argv[])
{
	std::vector<std::string> filenames = {"./test.dcan"};
	bool simplifyGraph = true;

	for (auto i = 1; i < argc; i++)
	{
		std::string argument = argv[i];
		if (argument.empty())
		{
			continue;
		}

		if (argument[0] == '-')
		{
			if (argument == "-simplify-graph")
			{
				simplifyGraph = true;
			}

			continue;
		}

		filenames.emplace_back(argument);
	}

	for (auto filename : filenames)
	{
		auto parser = dcan::bison::parser::Parser();
		auto tree = std::unique_ptr<::deamer::external::cpp::ast::Tree>(
			parser.Parse(ReadInFile(filename) + "\n"));

		if (tree == nullptr || tree->GetStartNode() == nullptr)
		{
			std::cout << "Could not parse file: " << filename << "\n";
			continue;
		}

		auto visualizer = dcan::ast::listener::deamer::visualisation::Graph();
		visualizer.Dispatch(tree->GetStartNode());
		// std::cout << visualizer.GetGraph() << "\n";

		auto modelExtractor = dcan::ast::listener::model::ModelExtractor();
		modelExtractor.Dispatch(tree->GetStartNode());
		auto model = modelExtractor.GetModel();

		if (simplifyGraph)
		{
			model->Simplify();
		}

		for (auto node : model->GetNodesCircuit())
		{
			if (!model->IsNodePartOfCircuit(node))
			{
				continue;
			}

			std::cout << "Node: " << node->GetNodeName() << " Aliases: [ ";
			for (auto alias : node->GetAliasedNodes())
			{
				std::cout << alias->GetNodeName() << ", ";
			}

			std::cout << "]\n";
			for (auto linkedElement : node->GetLinkedElements())
			{
				std::cout << "\tElement: " << linkedElement->GetElementName() << "\n";
			}
			std::cout << "\n";
		}

		std::map<std::size_t, std::size_t> mapNumberWithIndex;
		std::set<dcan::ir::model::Element*> alreadyLabeled;
		auto getIndex = [&](std::size_t ptr) {
			auto iter = mapNumberWithIndex.find(ptr);
			if (iter == mapNumberWithIndex.end())
			{
				auto newValue = mapNumberWithIndex.size();
				mapNumberWithIndex.insert({ptr, newValue});
				return newValue;
			}
			return iter->second;
		};

		std::string output;
		output += "graph circuit {\n";
		for (auto node : model->GetNodesCircuit())
		{
			output += std::to_string(getIndex((std::size_t)node)) + " [label = \"" +
					  node->GetNodeName() + "\"];\n";
			for (auto linkedElement : node->GetLinkedElements())
			{
				if (alreadyLabeled.find(linkedElement) == alreadyLabeled.end())
				{
					output += std::to_string(getIndex((std::size_t)linkedElement)) +
							  " [label = \"" + linkedElement->GetElementName() + "\"];\n";
					alreadyLabeled.insert(linkedElement);
				}

				output += std::to_string(getIndex((std::size_t)node)) + " -- " +
						  std::to_string(getIndex((std::size_t)linkedElement)) + "\n";
			}
		}
		output += "}\n";
		std::cout << output;
	}
}
