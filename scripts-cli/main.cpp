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
	CmdLine cmd("Athena's CLI", ' ', VERSION, false);

	UnlabeledValueArg<string> literalCommand("command", "Execute a command from Athena CLI", true, "test", "test|compile");
	UnlabeledValueArg<string> fileArg("file", "File path to be tested", false, "", "file path/directory");

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
	}
}
