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

#include "commands.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tclap/CmdLine.h>

using namespace std;
using namespace TCLAP;

class Option
{
public:
	string name;
	string value;

	Option(string name, string value)
	{
		this->name = name;
		this->value = value;
	}
};

class Command
{
public:
	string command;
	string value;
	vector<Option> options;
	vector<string> args;

	Command(const int argumentCount, char* argumentValues[])
	{
		this->args.assign(argumentValues + 1, argumentValues + argumentCount);
	}
};

bool optionExist(Command command, string optionName)
{
	for (auto& option : command.options)
	{
		if (option.name == optionName)
			return true;
	}

	return false;
}

bool isHelpCommand(Command command)
{
	if (command.command == "") return true;
	if (command.command == "help") return true;
	if (optionExist(command, "--help") || optionExist(command, "-h")) return true;

	return false;
}

Command buildCommand(const int argumentCount, char* argumentValues[])
{
	Command command(argumentCount, argumentValues);

	for (auto& value : command.args)
	{
		if (value.rfind("--", 0) == 0)
			command.options.push_back(Option(value, ""));
		else if (value.rfind("-", 0) == 0)
			command.options.push_back(Option(value, ""));
		else if (command.command == "")
			command.command = value;
		else if (command.value == "")
			command.value = value;
	}

	return command;
}

void showHelp()
{
	cout << ATHENA_LOGO << endl;
	cout << endl;
}

int executeCommand(Command command)
{
	return 13;
}

bool isValidCommand(Command command)
{
	return true;
}

int maybeExecuteCommand(const int argumentCount, char* argumentValues[])
{
	Command command = buildCommand(argumentCount, argumentValues);

	if (isValidCommand(command)) {
		return executeCommand(command);
	}

	return 1;
}
