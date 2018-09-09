cmake_minimum_required(VERSION 3.0.2)

file(GLOB TEST_FILES "*.cpp")

# add the googletest directory to the build
add_subdirectory(${CMAKE_BINARY_DIR}/third-party/googletest bin/googletest)

# create test executable
add_executable(unittest ${TEST_FILES})

# link googletest and algorithms to the executable
target_link_libraries(unittest gmock gtest algorithms)

include_directories(${CMAKE_BINARY_DIR}/third-party/googletest/googletest/include)
include_directories(${CMAKE_BINARY_DIR}/third-party/googletest/googlemock/include)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
