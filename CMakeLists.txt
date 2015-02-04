cmake_minimum_required(VERSION 2.8.4)
project(Yage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(SOURCE_DIR src)

add_subdirectory(external/glfw)
add_subdirectory(external/assimp)

include_directories(external/glfw/include)
include_directories(external/glm/include)
include_directories(external/glew/include)
include_directories(external/assimp/include)

add_definitions(-DGLEW_STATIC)

file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.h" "${SOURCE_DIR}/*.cpp")
file(COPY shaders DESTINATION ${PROJECT_BINARY_DIR})

add_executable(Yage external/glew/src/glew.c ${SOURCE_FILES})
target_link_libraries(Yage glfw assimp ${GLFW_LIBRARIES})