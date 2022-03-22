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
#include "scripts-cli/utils.cpp"

TEST(utils, getCurrentWorkingDirectoryTest)
{
	std::string cwd = getCurrentWorkingDirectory();
	EXPECT_TRUE(isValidPath(cwd));
}

TEST(utils, isValidPathTest)
{
	EXPECT_TRUE(isValidPath(TEMP_PATH));
	EXPECT_TRUE(isValidPath(HOME_PATH));
}
