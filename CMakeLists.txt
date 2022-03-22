#####################################################################
#
# "Getting Started with CMake", a tutorial video by Eric Wing.
#   Part 1 of 6: http://www.youtube.com/watch?v=CLvZTyji_Uw
#   Part 2 of 6: http://www.youtube.com/watch?v=gUW-RrRQjEg
#   Part 3 of 6: http://www.youtube.com/watch?v=sz6cPhbuTk4
#   Part 4 of 6: http://www.youtube.com/watch?v=JICZOkyNXbg
#   Part 5 of 6: http://www.youtube.com/watch?v=lAiuLHy4dCk
#   Part 6 of 6: http://www.youtube.com/watch?v=fAtJNzDZdH8
#
# You can use notepad++ for syntax highlighting.
# Naming conventions:
#   WITH_*   : option to use an external package or not
#   ENABLE_* : option to use an internal feature/code or not
#   HAVE_*   : internal variable indicating if we have and are using something
#
#####################################################################

# CMake version check
cmake_minimum_required( VERSION 3.22.2 FATAL_ERROR )

# Project
project( Athena LANGUAGES CXX )

#####################################################################
#
# Configurations
#
#####################################################################

# Enable C++ 17
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# NuGet Packages path
set( INCLUDE_NUGET_PACKAGES_PATH ${CMAKE_SOURCE_DIR}/packages )

# Athena's src path
set( ATHENA_SOURCE_PATH ${CMAKE_SOURCE_DIR}/src )

# Set current system architecture
EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )

# Fix when x86_64
if( ${ARCHITECTURE} STREQUAL "x86_64" )
	set( ARCHITECTURE "x64" )
endif()

message( STATUS "Current System Architecture: ${ARCHITECTURE}" )

# Set current build type
if( CMAKE_BUILD_TYPE STREQUAL "" )
	set( gtest_BUILD_TYPE "Debug" )
elseif(NOT CMAKE_BUILD_TYPE STREQUAL "Release" )
	set( gtest_BUILD_TYPE "Debug" )
endif()

message( STATUS "Current Build Type: ${gtest_BUILD_TYPE}" )

#####################################################################
#
# Dependencies
#
#####################################################################
find_program(NUGET_EXE NAMES nuget)

if(NOT NUGET_EXE)
	message("NUGET.EXE not found.")
	message(FATAL_ERROR "Please install this executable, and run CMake again.")
endif()

# Install dependencies
exec_program( ${NUGET_EXE} ARGS restore ${CMAKE_SOURCE_DIR}/Athena.sln -MSBuildVersion 14 )

# Set path for each of them
set( TCLAP_HEADERS_PATH ${INCLUDE_NUGET_PACKAGES_PATH}/tclap.1.2.1/build/native/include/tclap )
set( GTEST_PATH ${INCLUDE_NUGET_PACKAGES_PATH}/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.5 )

set( GTEST_HEADERS_PATH ${GTEST_PATH}/build/native/include )
set( GTEST_SOURCES_PATH ${GTEST_PATH}/lib/native/v140/windesktop/msvcstl/static/rt-dyn/${ARCHITECTURE}/${gtest_BUILD_TYPE} )

# Include gtest and main source folders
include_directories( src ${GTEST_HEADERS_PATH} ${GTEST_SOURCES_PATH} )
enable_testing()

#####################################################################
#
# Projects
#
#####################################################################
add_subdirectory( src )
add_subdirectory( test )
