/*

 $$$$$$\    $$\     $$\
$$  __$$\   $$ |    $$ |
$$ /  $$ |$$$$$$\   $$$$$$$\   $$$$$$\  $$$$$$$\   $$$$$$\
$$$$$$$$ |\_$$  _|  $$  __$$\ $$  __$$\ $$  __$$\  \____$$\
$$  __$$ |  $$ |    $$ |  $$ |$$$$$$$$ |$$ |  $$ | $$$$$$$ |
$$ |  $$ |  $$ |$$\ $$ |  $$ |$$   ____|$$ |  $$ |$$  __$$ |
$$ |  $$ |  \$$$$  |$$ |  $$ |\$$$$$$$\ $$ |  $$ |\$$$$$$$ |
\__|  \__|   \____/ \__|  \__| \_______|\__|  \__| \_______|

 */

#include "cli.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <tclap/CmdLine.h>

using namespace std;
using namespace TCLAP;

int main(int argumentCount, char* argumentValues[])
{
	try
	{
		CmdLine cmd(LOGO, ' ', VERSION);

		UnlabeledValueArg<string> literalCommand("command", "Execute a command from Athena CLI", true, "test", "string");
		UnlabeledValueArg<string> fileArg("file", "File path to be tested", false, "", "string");

		cmd.add(literalCommand);
		cmd.add(fileArg);
		cmd.parse(argumentCount, argumentValues);

		if (literalCommand.isSet()) {
			if (literalCommand.getValue() == "test")
			{

			}
			else if (literalCommand.getValue() == "compile")
			{

			}
			else
			{
				throw("Wrong command value");
			}
		}
	}
	catch (const std::exception&)
	{

	}

	// return maybeExecuteCommand(argumentsCount, argumentsValues);
}
