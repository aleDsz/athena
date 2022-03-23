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

set( CLI_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}  CACHE INTERNAL "" )

message( STATUS "Creating target cli - start" )

# load all files
file( GLOB CLI_HEADERS ${CLI_SOURCE_DIR}/*.hpp )
file( GLOB CLI_SOURCES ${CLI_SOURCE_DIR}/*.cpp )

# include folders
set( INCLUDE_DIRS ${GLOBAL_INCLUDE_DIRS} ${TCLAP_HEADERS_PATH} )
include_directories( ${INCLUDE_DIRS} )

# set sources
set( SOURCE_FILES ${CLI_HEADERS} ${CLI_SOURCES} )
source_group( cli FILES ${CLI_HEADERS} ${CLI_SOURCES} )

# build application
add_executable( cli ${SOURCE_FILES} )

# build lib for testing
add_library( cli_lib STATIC ${SOURCE_FILES} )

# install lib
install( TARGETS cli_lib EXPORT cli_lib_targets
	       ARCHIVE DESTINATION lib
				 LIBRARY DESTINATION lib
				 INCLUDES DESTINATION include )

install( FILES ${CLI_HEADERS} DESTINATION include )
install( EXPORT cli_lib_targets NAMESPACE athena:: DESTINATION lib/cmake/cli_lib )

# generate lib target/config for cmake
include( CMakePackageConfigHelpers )

write_basic_package_version_file( ${CMAKE_CURRENT_BINARY_DIR}/cli_lib-config.cmake
	                                VERSION 0.1.0
                                  COMPATIBILITY AnyNewerVersion )

install( FILES cli_lib-config.cmake
	             ${CMAKE_CURRENT_BINARY_DIR}/cli_lib-config.cmake
         DESTINATION lib/cmake/cli_lib )

message( STATUS "Creating target cli - done" )
