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
#include "scripts-cli/command_dispatcher.cpp"

TEST(command_dispatcher, isValidCommandTest)
{
	EXPECT_TRUE(isValidCommand("test"));
	EXPECT_TRUE(isValidCommand("compile"));
	EXPECT_FALSE(isValidCommand("foo"));
}

TEST(command_dispatcher, executeTestCommandWithoutPathTest)
{
	int result = executeCommand(TEMP_PATH, "test");
	EXPECT_EQ(0, result);
}
