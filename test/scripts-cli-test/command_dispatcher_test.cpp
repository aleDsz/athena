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
#include <memory>

#include "pch.h"
#include "scripts-cli/command_dispatcher.hpp"

TEST(command_dispatcher, executeInvalidCommandTest)
{
	int result = executeCommand(TEMP_PATH, "foo");
	EXPECT_EQ(1, result);
}

TEST(command_dispatcher, executeTestCommandWithoutPathTest)
{
	int result = executeCommand(TEMP_PATH, "test");
	EXPECT_EQ(0, result);
}
