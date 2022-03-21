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

#include <sys/stat.h>

#include <algorithm>
#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include "cli.hpp"
#include "command_dispatcher.hpp"
#include "files.hpp"
#include "utils.hpp"

/*
 * All valid commands to be executed by this software.
 *
 * \return A string vector of valid commands to be executed
 */
static const std::vector<std::string> VALID_COMMANDS = { "test", "compile" };

/*
 * Validates the existence of corresponding command.
 *
 * \return a boolean, indicating if the given command is valid.
 */
static bool isValidCommand(std::string command)
{
	return std::find(VALID_COMMANDS.begin(), VALID_COMMANDS.end(), command) != VALID_COMMANDS.end();
}

/*
 * Runs the command without a path/file defined
 *
 * \param command Command to be executed
 * \return The exit code from given command to be executed
 */
int executeCommand(std::string currentPath, std::string command)
{
	return executeCommand(currentPath, command, nullptr);
}

/*
 * Runs the command with a path/file defined
 *
 * \param command Command to be executed
 * \param path The path to execute the given command
 *
 * \return The exit code from given command to be executed
 */
int executeCommand(std::string currentPath, std::string command, std::shared_ptr<std::string> path)
{
	std::string fullPath = getFullPath(currentPath, path);

	if (!isValidCommand(command)) return 1;
	if (!isValidPath(fullPath)) return 1;

	auto fileTree = listFileTreeFrom(fullPath);

	return 0;
}
