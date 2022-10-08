/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DCAN_LANGUAGE_H
#define DCAN_LANGUAGE_H

#include "Deamer/Language/Generator/Definition/Language.h"
#include "dcan/Threat.h"
#include "dcan/Identity.h"
#include "dcan/Generation.h"
#include "dcan/Grammar.h"
#include "dcan/Lexicon.h"


namespace dcan
{
	/*!	\class Language
	 *
	 *	\brief This contains the Language Definition of the language dcan
	 *
	 *	\details The LD initializes all base LPD's with its own pointer (this).
	 *	This allows the LPD's to access other LPD's via the language object.
	 *
	 *	\note This is auto-generated via the DLDL definition.
	 */
	class Language : public ::deamer::language::generator::definition::Language<
						 ::dcan::Language , ::dcan::Threat
, ::dcan::Identity
, ::dcan::Generation
, ::dcan::Grammar
, ::dcan::Lexicon
>
						 , public ::dcan::Threat
, public ::dcan::Identity
, public ::dcan::Generation
, public ::dcan::Grammar
, public ::dcan::Lexicon

	{
	public:
		Language() : ::deamer::language::generator::definition::Language<
						 ::dcan::Language , ::dcan::Threat
, ::dcan::Identity
, ::dcan::Generation
, ::dcan::Grammar
, ::dcan::Lexicon
>()
		, ::dcan::Threat::Threat(this)
, ::dcan::Identity::Identity(this)
, ::dcan::Generation::Generation(this)
, ::dcan::Grammar::Grammar(this)
, ::dcan::Lexicon::Lexicon(this)

		{
		}

		~Language() override = default;
	};
}

#endif // DCAN_LANGUAGE_H
