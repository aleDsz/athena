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

#include <stdio.h>

#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include "cli.hpp"

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

/*
 * Validates the existence of given path.
 *
 * \return a boolean, indicating if the given path exists.
 */
bool isValidPath(std::string path) noexcept
{
	struct stat buffer;
	return (stat(path.c_str(), &buffer) == 0);
}

/*
 * Gets the current working directory
 *
 * \return The current working directory string
 */
std::string getCurrentWorkingDirectory()
{
	char workingDirectory[FILENAME_MAX];
	GetCurrentDir(workingDirectory, FILENAME_MAX);

	return workingDirectory;
}

/*
 * Gets the full path from given directory and path
 *
 * \param baseDirectory The base directory
 * \param path The path to concatenate
 * \return The full path from a base dir and a path
 */
std::string getFullPath(std::string baseDirectory, std::shared_ptr<std::string> path)
{
	if (path == nullptr) return baseDirectory;

	std::string s_path = path->c_str();
	std::string slash;

#ifdef WINDOWS
	slash = "\\";
#else
	slash = "/";
#endif

	return baseDirectory + slash + s_path;
}
