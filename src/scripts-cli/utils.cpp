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

#include <filesystem>
#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include "cli.hpp"

namespace fs = std::filesystem;

/*
 * Validates the existence of given path.
 *
 * \return a boolean, indicating if the given path exists.
 */
bool isValidPath(std::string path) noexcept
{
	return fs::exists(path);
}

/*
 * Gets the current working directory
 *
 * \return The current working directory string
 */
std::string getCurrentWorkingDirectory()
{
	auto current_path = fs::current_path();
	return current_path.string();
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
