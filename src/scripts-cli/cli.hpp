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

#ifndef __ATHENA_CLI_H__
#define __ATHENA_CLI_H__

#ifndef VERSION
#define VERSION "0.0.1"
#endif // VERSION

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define WINDOWS true
#elif __APPLE__
	#define MACOS true
#elif defined(__linux__) || defined(__unix__) || defined(_POSIX_VERSION)
	#define LINUX true
#endif

#endif // __ATHENA_CLI_H__
