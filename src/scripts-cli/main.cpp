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

#include <tclap/CmdLine.h>

#include <memory>
#include <string>
#include <vector>

#include "cli.hpp"
#include "colors.hpp"
#include "command_dispatcher.hpp"
#include "utils.hpp"

using namespace TCLAP;

int main(int argumentCount, const char* const *argumentValues)
{
	CmdLine cmd(GRN("Athena's CLI"), ' ', VERSION, false);

	UnlabeledValueArg<std::string> literalCommand(RED("command"), CYN("Execute a command from Athena CLI"), true, "test", RED("test|compile"));
	UnlabeledValueArg<std::string> pathArg(BLU("path"), CYN("File path/directory"), false, "", BLU("file path/directory"));

	cmd.add(literalCommand);
	cmd.add(pathArg);
	cmd.parse(argumentCount, argumentValues);

	std::string currentPath = getCurrentWorkingDirectory();

	if (!literalCommand.isSet()) return 1;

	std::string command = literalCommand.getValue();

	if (pathArg.isSet()) {
		std::shared_ptr<std::string> path(&pathArg.getValue());
		return executeCommand(currentPath, command, path);
	}

	return executeCommand(currentPath, command);
}
