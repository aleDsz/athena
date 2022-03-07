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
