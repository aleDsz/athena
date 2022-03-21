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

#include <iostream>
#include <filesystem>

#include "files.hpp"
#include "utils.hpp"

namespace fs = std::filesystem;

static std::vector<std::string> listDirectoriesFrom(std::string baseDirectory);

 /*
  * List contents from given directory.
  *
  * \param directory The given directory to list contents
  * \param contentType The content type to be filtered
  * \return The content list from given directory
  */
static std::vector<std::string> listDirectoryContent(std::string directory, enum entry_type contentType)
{
	std::vector<std::string> contentList;

	for (const auto& entry : fs::directory_iterator(directory))
	{
		if (contentType == ENT_DIRECTORY) {
			if (entry.is_directory())
				contentList.push_back(entry.path());
		} else if (contentType == ENT_FILE) {
			if (!entry.is_directory())
				contentList.push_back(entry.path());
		}
	}

	return contentList;
}

/*
 * List files from given directory.
 *
 * \param directory The given directory to list files
 * \return The file list from given directory with Athena's extension
 */
static std::vector<std::string> listFilesFrom(std::string directory)
{
	std::vector<std::string> tempFileList = listDirectoryContent(directory, ENT_FILE);
	std::vector<std::string> fileList;

	for (const auto& content : tempFileList) {
		if (content.length() > 5) {
			std::string ext = content.substr(content.size() - 4);

			if (ext == ATHENA_SCRIPT_EXTENSION) {
				fileList.push_back(content);
			}
		}
	}

	return fileList;
}

/*
 * List directories from given directory.
 *
 * \param baseDirectory The given directory to list directories
 * \param sourceList The given directory to list directories
 * \param directoryList The given directory to list directories
 */
static void listDirectoriesFrom(std::string baseDirectory, std::vector<std::string> sourceList, std::vector<std::string>* directoryList)
{
	if (directoryList->empty()) {
		sourceList = listDirectoryContent(baseDirectory, ENT_DIRECTORY);
	}

	for (std::string directory : sourceList) {
		if (directory.length() > 2)
		{
			// std::shared_ptr<std::string> c_directory(directory);

			directoryList->push_back(directory);
			// std::string path = getFullPath(baseDirectory, directory);
			// std::vector<std::string> directories = listDirectoriesFrom(baseDirectory);

			// listDirectoriesFrom(path, directories, directoryList);
		}
	}
}

/*
 * List directories from given directory.
 *
 * \param baseDirectory The given directory to list directories
 * \return The directory list from given directory
 */
static std::vector<std::string> listDirectoriesFrom(std::string baseDirectory)
{
	std::vector<std::string> sourceList = listDirectoryContent(baseDirectory, ENT_DIRECTORY);
	std::vector<std::string>* directoryList;

	listDirectoriesFrom(baseDirectory, sourceList, directoryList);

	return *directoryList;
}

/*
 * List all file tree under the given base directory.
 *
 * \param baseDirectory The base directory to discover the file tree
 * \return A map with path as key and vector of string of files
 */
std::map<std::string, std::vector<std::string>> listFileTreeFrom(std::string baseDirectory)
{
	std::map<std::string, std::vector<std::string>> fileTree;
	std::vector<std::string> directories = listDirectoriesFrom(baseDirectory);

	for (const auto& directory : directories) {
		std::vector<std::string> fileList = listFilesFrom(directory);
		std::pair<std::string, std::vector<std::string>> directoryFileListPair(directory, fileList);

		fileTree.insert(directoryFileListPair);
	}

	return fileTree;
}
