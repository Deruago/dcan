#ifndef DCAN_IR_MODEL_SOURCE_H
#define DCAN_IR_MODEL_SOURCE_H

#include "dcan/Ir/Model/Element.h"
#include <memory>
#include <string>
#include <vector>

namespace dcan::ir::model
{
	class Model;
	class Node;

	class Source : public Element
	{
	private:
		std::string sourceName;
		int voltage = 0;
		int current = 0;
		int resistance = 0;

		Model* model;

	public:
		Source(Model* model_, const std::vector<std::string>& sourceNames_);
		Source(Model* model_, const std::string& sourceName_);
		~Source() = default;

	public:
		void AssignVoltage(int voltage_);
		void AssignCurrent(int current_);
		void AssignResistance(int resistance_);

		int GetVoltage();
		int GetCurrent();
		int GetResistance();
	};
}

#endif // DCAN_IR_MODEL_SOURCE_H
