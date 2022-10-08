/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#include "dcan/CompilerGenerator.h"

#include "Deamer/File/Generate/Compiler.h"

int main(int argc, char* argv[])
{
		// Generate: dcan
	::dcan::CompilerGenerator dcan_compiler;
	::deamer::file::generate::Compiler dcan_WriteToDisk(dcan_compiler.Generate());
	dcan_WriteToDisk.SetProjectType(::deamer::file::generate::Compiler::ProjectType::single);
	
	dcan_WriteToDisk.Generate();


	return 0;
}
