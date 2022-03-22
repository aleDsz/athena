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

#include "pch.h"
#include "scripts-cli/files.cpp"

TEST(files, listFilesFromTest)
{
	std::vector<std::string> fileList = listFilesFrom(TEMP_PATH);
	EXPECT_FALSE(fileList.empty());
}

TEST(files, listDirectoriesFromTest)
{
	std::vector<std::string> directoryList = listDirectoriesFrom(TEMP_PATH);
	EXPECT_FALSE(directoryList.empty());
}

TEST(files, listDirectoryContentTest)
{
	std::vector<std::string> fileList = listDirectoryContent(TEMP_PATH, ENT_FILE);
	std::vector<std::string> directoryList = listDirectoryContent(TEMP_PATH, ENT_DIRECTORY);

	EXPECT_FALSE(fileList.empty());
	EXPECT_FALSE(directoryList.empty());
}

TEST(files, listFileTreeFromTest)
{
	std::map<std::string, std::vector<std::string>> fileTree = listFileTreeFrom(TEMP_PATH);

	EXPECT_FALSE(fileTree.empty());
}
