/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DCAN_IDENTITY_H
#define DCAN_IDENTITY_H

#include "Deamer/Language/Generator/Definition/Property/User/Special/Identity.h"

namespace dcan
{
	class Language;

	/*!	\class Identity
	 *
	 *	\brief This contains the identity LPD of the language dcan
	 *
	 *	\note This is auto-generated via the DLDL definition.
	 */
	class Identity : public ::deamer::language::generator::definition::property::user::Identity<
								::dcan::Language>
	{
	public:
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Name> name;

	public:
		Identity(::dcan::Language* language)
			:	::deamer::language::generator::definition::property::user::Identity<
					::dcan::Language>(language)
		{
		}

		void GenerateObjects() override
		{
			name.Set(::deamer::language::type::definition::object::main::Name("dcan"));
			
			AddObject(name);

			// Place higher level operations here.
			// ReplaceObject(..., ...)
			// DeleteObject(..., ...)
			
		}
	};
}

#endif // DCAN_IDENTITY_H
