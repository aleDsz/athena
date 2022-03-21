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

# set sources
include_directories( ${INCLUDE_DIRS} )
set( SOURCE_FILES ${CLI_HEADERS} ${CLI_SOURCES} )
source_group( cli FILES ${CLI_HEADERS} ${CLI_SOURCES} )

# build application
add_executable( cli ${SOURCE_FILES} )

message( STATUS "Creating target cli - done" )
