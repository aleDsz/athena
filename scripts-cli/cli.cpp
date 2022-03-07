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

void startCommandLine(const int argumentCount, char* argumentValues[])
{
	CmdLine cmd(LOGO, ' ', VERSION);

	UnlabeledValueArg<string> literalCommand("command", "Execute a command from Athena CLI", true, "test", "string");

	SwitchArg help("h", "help", "Displays the Athena CLI helper", false);
	SwitchArg version("v", "version", "Displays the current cli version", false);

	cmd.add(literalCommand);
	cmd.add(help);

	cmd.parse(argumentCount, argumentValues);
}
