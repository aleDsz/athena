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
file( GLOB CLI_TEST_HEADERS ${CLI_TEST_SOURCE_DIR}/*.h ${CLI_TEST_SOURCE_DIR}/*.hpp )
file( GLOB CLI_TEST_SOURCES ${CLI_TEST_SOURCE_DIR}/*.cpp )

# set sources
set( SOURCE_FILES ${GTEST_FILES} ${CLI_TEST_HEADERS} ${CLI_TEST_SOURCES} )

# build application
add_executable( cli_test ${SOURCE_FILES} )

# add dependency
add_dependencies( cli_test cli_lib )

# build tests
add_test( NAME cli_test COMMAND cli_test )

# link libs
target_link_libraries( cli_test cli_lib )

if( ${gtest_BUILD_TYPE} STREQUAL "Debug" )
	target_link_libraries( cli_test ${GTEST_SOURCES_PATH}/gtestd.lib )
	target_link_libraries( cli_test ${GTEST_SOURCES_PATH}/gtest_maind.lib )
else()
	target_link_libraries( cli_test ${GTEST_SOURCES_PATH}/gtest.lib )
	target_link_libraries( cli_test ${GTEST_SOURCES_PATH}/gtest_main.lib )
endif()

message( STATUS "Creating target cli test - done" )
