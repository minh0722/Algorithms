cmake_minimum_required(VERSION 3.15)

file(GLOB TEST_FILES "*.cpp")

# add the googletest directory to the build
add_subdirectory(${CMAKE_BINARY_DIR}/third-party/googletest bin/googletest)

# create test executable
add_executable(unittest ${TEST_FILES})

# link googletest and algorithms to the executable
target_link_libraries(unittest gmock gtest algorithms)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

# need to call the test exe here. Check https://stackoverflow.com/questions/18961650/use-cmake-to-run-a-c-program-post-build
# The custom command will run the executable (and build it first, if necessary). 
# The custom target will drive the custom command - it depends on the command's 
# output, so when the target is built, it will require its dependency to be built, causing the custom command to run.
add_custom_command(
	OUTPUT stamped_file.lic
	COMMAND unittest)

add_custom_target(
	StampTheLicense ALL
	DEPENDS stamped_file.lic
)