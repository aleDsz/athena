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

#ifndef __ATHENA_COMMAND_DISPATCHER_H__
#define __ATHENA_COMMAND_DISPATCHER_H__

int executeCommand(std::string currentPath, std::string command);
int executeCommand(std::string currentPath, std::string command, std::shared_ptr<std::string> path);

#endif // __ATHENA_COMMAND_DISPATCHER_H__
