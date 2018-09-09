cmake_minimum_required(VERSION 3.1.3)

file(GLOB TEST_FILES "*.cpp")

# add the googletest directory to the build
add_subdirectory(${CMAKE_BINARY_DIR}/third-party/googletest bin/googletest)

# create test executable
add_executable(unittest ${TEST_FILES})

# link googletest and algorithms to the executable
target_link_libraries(unittest gmock gtest algorithms)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
