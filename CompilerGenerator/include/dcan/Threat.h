/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DCAN_THREAT_H
#define DCAN_THREAT_H

#include "Deamer/Language/Generator/Definition/Property/Standard/Main/Threat.h"
#include "Deamer/Language/Type/Definition/Object/Main/Threat/Analyzer/Combined/Deamer/DeamerCore.h"

namespace dcan
{
	class Language;

	/*!	\class Threat
	 *
	 *	\brief This contains the threat LPD of the language dcan
	 *
	 *	\note This is auto-generated via the DLDL definition.
	 */
	class Threat : public ::deamer::language::generator::definition::property::standard::Threat<
			  ::dcan::Language, ::deamer::language::type::definition::object::main::threat::
											analyzer::deamer::DeamerCore>
	{
	public:
		Threat(::dcan::Language* language)
			: ::deamer::language::generator::definition::property::standard::Threat<
				  ::dcan::Language, ::deamer::language::type::definition::object::main::
												threat::analyzer::deamer::DeamerCore>(language)
		{
		}
		~Threat() override = default;
	};
}

#endif // DCAN_THREAT_H
