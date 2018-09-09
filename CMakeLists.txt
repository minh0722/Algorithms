cmake_minimum_required(VERSION 3.1.3)

project(Algorithms)

file(GLOB SOURCE_FILES "src/*.cpp" "src/*.hpp")
file(GLOB HEADER_FILES "src/*.h")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_CXX_STANDARD 11)

# define preprocessor macro
add_definitions(-DALGO_API_EXPORT)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# add_executable(
#	Algorithms
#	${SOURCE_FILES}
#	${HEADER_FILES}
#)

# create dynamic library if BUILD_SHARED_LIBS is true, static library if BUILD_SHARED_LIBS is false. Or add flag SHARED or STATIC
add_library(
	algorithms SHARED
	${SOURCE_FILES}
	${HEADER_FILES}
)

# where algorithms headers can be found
include_directories(${CMAKE_BINARY_DIR}/src)

# specify compiler to use c++17 flag
# TARGET target - target is in the add_library() or add_executable()
set_property(TARGET algorithms PROPERTY CXX_STANDARD 11)

add_subdirectory(${CMAKE_BINARY_DIR}/tests)

# how to link external libraries in cmake
# include_directories(dir1 dir2) - add include directories to the build
# link_directories(directory1 directory2 ...) - Specify directories in which the linker will look for libraries
# target_link_libraries(<target> lib1 lib2 ...)
