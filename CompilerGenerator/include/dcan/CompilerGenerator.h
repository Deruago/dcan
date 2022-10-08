/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DCAN_COMPILERGENERATOR_H
#define DCAN_COMPILERGENERATOR_H

#include "Deamer/Compiler/Generator/Compiler.h"
#include "Deamer/Language/Reference/PropertyDefinition.h"
#include "dcan/Language.h"


#include "Deamer/Ast/Generation/CPP/CPP.h"
#include "Deamer/Lexer/Generator/Flex/Flex.h"
#include "Deamer/Parser/Generator/Bison/Bison.h"
#include "Deamer/Tool/Type/DeamerDefaultApplication/DeamerDefaultApplication.h"


namespace dcan
{
	/*!	\class CompilerGenerator
	 *
	 *	\brief This contains the CompilerGenerator of the language dcan
	 *
	 *	\details The CompilerGenerator class generates the compiler and various ecosystems.
	 *
	 *	\note This is auto-generated via the DLDL definitions.
	 */
	class CompilerGenerator : public ::deamer::compiler::generator::Compiler<::dcan::Language>
	
	{
	public:
		CompilerGenerator()
			: deamer::compiler::generator::Compiler<::dcan::Language>()
			
		{
		}

		deamer::file::compiler::Output Generate() override
		{
			// Retrieve the Language Definition (LD)
			::deamer::file::compiler::Output output(::deamer::compiler::generator::Compiler<::dcan::Language>::GetLanguageDefinition());
			::deamer::language::reference::PropertyDefinition(
				::deamer::compiler::generator::Compiler<::dcan::Language>::GetLanguageDefinition())
				.GetDefinition<::deamer::language::type::definition::property::Type::Threat>()
				.PrintThreats();

			

			// Initialize language outputs
			::deamer::ast::generation::cpp::CPP CPP(::deamer::compiler::generator::Compiler<::dcan::Language>::GetLanguageDefinition());
::deamer::lexer::generator::flex::Flex Flex(::deamer::compiler::generator::Compiler<::dcan::Language>::GetLanguageDefinition());
::deamer::parser::generator::bison::Bison Bison(::deamer::compiler::generator::Compiler<::dcan::Language>::GetLanguageDefinition());
::deamer::tool::type::deamerdefaultapplication::DeamerDefaultApplication DeamerDefaultApplication(::deamer::compiler::generator::Compiler<::dcan::Language>::GetLanguageDefinition());


			// The language generation targets
			output.AddLanguageToolOutput(CPP.Generate());
output.AddLanguageToolOutput(Flex.Generate());
output.AddLanguageToolOutput(Bison.Generate());
output.AddLanguageToolOutput(DeamerDefaultApplication.Generate());


			return output;
		}

		~CompilerGenerator() override = default;
	};
}

#endif // DCAN_COMPILERGENERATOR_H
