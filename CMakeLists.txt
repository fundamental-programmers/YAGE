cmake_minimum_required(VERSION 2.8.4)
project(Yage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(SOURCE_DIR src)

add_subdirectory(external/glfw)

include_directories(external/glfw/include)
include_directories(external/glm/glm)
include_directories(external/glew/include)

add_definitions(-DGLEW_STATIC)

set(SOURCE_FILES external/glew/src/glew.c ${SOURCE_DIR}/*.cpp)
add_executable(Yage ${SOURCE_FILES})
target_link_libraries(Yage glfw ${GLFW_LIBRARIES})