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

set( CLI_TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}  CACHE INTERNAL "" )

message( STATUS "Creating target cli test - start" )

# load all files
file( GLOB CLI_TEST_CXX_HEADERS ${CLI_SOURCE_DIR}/*.hpp )
file( GLOB CLI_TEST_HEADERS ${CLI_SOURCE_DIR}/*.h )
file( GLOB CLI_TEST_SOURCES ${CLI_SOURCE_DIR}/*.cpp )

# include folders
set( INCLUDE_DIRS ${GLOBAL_INCLUDE_DIRS} ${TCLAP_HEADERS_PATH} ${CLI_SOURCE_DIR} )

# set sources
include_directories( ${INCLUDE_DIRS} )
set( SOURCE_FILES ${CLI_TEST_HEADERS} ${CLI_TEST_CXX_HEADERS} ${CLI_TEST_SOURCES} )
source_group( test_cli FILES ${CLI_TEST_HEADERS} ${CLI_TEST_CXX_HEADERS} ${CLI_TEST_SOURCES} )

# build application
add_executable( test_cli ${SOURCE_FILES} )

message( STATUS "Creating target cli test - done" )
