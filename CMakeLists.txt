cmake_minimum_required(VERSION 2.8.4)
project(Yage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(SOURCE_DIR src)
set(FITBOS_EXAMPLE_DIR examples/fitbos)
set(SHADER_DIR shaders)
set(TEXTURE_DIR textures)
set(MODEL_DIR models)

add_subdirectory(external/glfw)
add_subdirectory(external/assimp)

include_directories(external/glfw/include)
include_directories(external/glm/include)
include_directories(external/glew/include)
include_directories(external/assimp/include)

include_directories(${SOURCE_DIR})

add_definitions(-DGLEW_STATIC)

file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.h" "${SOURCE_DIR}/*.cpp" "${FITBOS_EXAMPLE_DIR}/*.h" "${FITBOS_EXAMPLE_DIR}/*.cpp")
file(GLOB SHADER_FILES "${SHADER_DIR}/*.glsl")
file(GLOB TEXTURE_FILES "${TEXTURE_DIR}/*")
file(COPY ${SHADER_DIR} DESTINATION ${PROJECT_BINARY_DIR})
file(COPY ${TEXTURE_DIR} DESTINATION ${PROJECT_BINARY_DIR})
file(COPY ${MODEL_DIR} DESTINATION ${PROJECT_BINARY_DIR})

if(UNIX)
    find_package(ImageMagick COMPONENTS Magick++)
    if(NOT ImageMagick_Magick++_FOUND)
        message(FATAL_ERROR "The ImageMagick++ headers and libraries are not found. Please install libmagick++-dev.")
    endif()
    include_directories(${ImageMagick_INCLUDE_DIRS})
endif(UNIX)

add_executable(Yage external/glew/src/glew.c ${SOURCE_FILES})
target_link_libraries(Yage glfw assimp ${GLFW_LIBRARIES} ${ImageMagick_LIBRARIES})