#ifndef DCAN_IR_MODEL_ELEMENTTYPE_H
#define DCAN_IR_MODEL_ELEMENTTYPE_H

namespace dcan::ir::model
{
	enum class ElementType
	{
		unknown,
		voltage,
		current,
		resistor,
		capacitor,
		inductor,
		combined,
	};
}

#endif // DCAN_IR_MODEL_ELEMENTTYPE_H
