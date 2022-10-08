#include "dcan/Ir/Model/Source.h"
#include "dcan/Ir/Model/Model.h"

dcan::ir::model::Source::Source(Model* model_, const std::vector<std::string>& sourceNames_)
	: Element(model_, ElementType::unknown, sourceNames_),
	  model(model_)
{
}

dcan::ir::model::Source::Source(Model* model_, const std::string& sourceName_)
	: Element(model_, ElementType::unknown, sourceName_),
	  model(model_)
{
}

void dcan::ir::model::Source::AssignVoltage(int voltage_)
{
	if (GetType() == ElementType::unknown)
	{
		SetType(ElementType::voltage);
	}
	else
	{
		SetType(ElementType::combined);
	}
	voltage = voltage_;
}

void dcan::ir::model::Source::AssignCurrent(int current_)
{
	if (GetType() == ElementType::unknown)
	{
		SetType(ElementType::current);
	}
	else
	{
		SetType(ElementType::combined);
	}
	current = current_;
}

void dcan::ir::model::Source::AssignResistance(int resistance_)
{
	if (GetType() == ElementType::unknown)
	{
		SetType(ElementType::resistor);
	}
	else
	{
		SetType(ElementType::combined);
	}
	resistance = resistance_;
}

int dcan::ir::model::Source::GetVoltage()
{
	return voltage;
}

int dcan::ir::model::Source::GetCurrent()
{
	return current;
}

int dcan::ir::model::Source::GetResistance()
{
	return resistance;
}
