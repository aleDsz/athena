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

# Enable C++ 14
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# NuGet Packages path
set( INCLUDE_NUGET_PACKAGES_PATH ${CMAKE_SOURCE_DIR}/packages )

#####################################################################
#
# Projects & Dependencies
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

# Add source folder
add_subdirectory( src )
