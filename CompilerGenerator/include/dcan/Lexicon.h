/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DCAN_LEXICON_H
#define DCAN_LEXICON_H

#include "Deamer/Language/Generator/Definition/Property/User/Main/Lexicon.h"

namespace dcan
{
	class Language;

	class Lexicon : public ::deamer::language::generator::definition::property::user::Lexicon<
								::dcan::Language>
	{
	public:
		// Terminal declarations
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> SINGLE_COMMENT;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> MULTI_COMMENT;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> CURRENT;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> VOLTAGE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> RESISTANCE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> NODE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> IDEAL_SOURCE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> GROUND;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> VARNAME;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> NUMBER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> MIN;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> EQ;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> ESCAPE_CHARS;

	
	public:
		Lexicon(dcan::Language* language)
			:	::deamer::language::generator::definition::property::user::Lexicon<
					::dcan::Language>(language)
		{
		}

		void GenerateObjects() override
		{
			// Terminals
			SINGLE_COMMENT.Set(deamer::language::type::definition::object::main::Terminal("SINGLE_COMMENT", "[/][^\\n\\r]*[\\n\\r]{0,1}", ::deamer::language::type::definition::object::main::SpecialType::Delete));
MULTI_COMMENT.Set(deamer::language::type::definition::object::main::Terminal("MULTI_COMMENT", "[/][*][^*]*[*][/]{0,1}", ::deamer::language::type::definition::object::main::SpecialType::Delete));
CURRENT.Set(deamer::language::type::definition::object::main::Terminal("CURRENT", "(([Cc][Uu][Rr][Rr][Ee][Nn][Tt])|([Ii])|([Aa]))", ::deamer::language::type::definition::object::main::SpecialType::Standard));
VOLTAGE.Set(deamer::language::type::definition::object::main::Terminal("VOLTAGE", "(([Vv][Oo][Ll][Tt][Aa][Gg][Ee])|([Uu])|([Vv]))", ::deamer::language::type::definition::object::main::SpecialType::Standard));
RESISTANCE.Set(deamer::language::type::definition::object::main::Terminal("RESISTANCE", "(([Rr][Ee][Ss][Ii][Ss][Tt][Aa][Nn][Cc][Ee])|([Rr]))", ::deamer::language::type::definition::object::main::SpecialType::Standard));
NODE.Set(deamer::language::type::definition::object::main::Terminal("NODE", "[Nn][Oo][Dd][Ee]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
IDEAL_SOURCE.Set(deamer::language::type::definition::object::main::Terminal("IDEAL_SOURCE", "[Ss][Oo][Uu][Rr][Cc][Ee]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
GROUND.Set(deamer::language::type::definition::object::main::Terminal("GROUND", "[Gg][Rr][Oo][Uu][Nn][Dd]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
VARNAME.Set(deamer::language::type::definition::object::main::Terminal("VARNAME", "[a-zA-Z_][a-zA-Z0-9_]*", ::deamer::language::type::definition::object::main::SpecialType::Standard));
NUMBER.Set(deamer::language::type::definition::object::main::Terminal("NUMBER", "[-]{0,1}[0-9]+([\\.][0-9]+){0,1}", ::deamer::language::type::definition::object::main::SpecialType::Standard));
MIN.Set(deamer::language::type::definition::object::main::Terminal("MIN", "[-]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
EQ.Set(deamer::language::type::definition::object::main::Terminal("EQ", "[=]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
ESCAPE_CHARS.Set(deamer::language::type::definition::object::main::Terminal("ESCAPE_CHARS", "[ \\n\\r\\t\\f\\v\\b]+", ::deamer::language::type::definition::object::main::SpecialType::Delete));


			// Add object calls
			// AddObject(...)
			AddObject(SINGLE_COMMENT);
AddObject(MULTI_COMMENT);
AddObject(CURRENT);
AddObject(VOLTAGE);
AddObject(RESISTANCE);
AddObject(NODE);
AddObject(IDEAL_SOURCE);
AddObject(GROUND);
AddObject(VARNAME);
AddObject(NUMBER);
AddObject(MIN);
AddObject(EQ);
AddObject(ESCAPE_CHARS);


			// Place higher level operations here.
			// ReplaceObject(..., ...)
			// DeleteObject(..., ...)
			
		}
	};
}

#endif // DCAN_LEXICON_H
