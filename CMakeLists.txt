cmake_minimum_required(VERSION 3.18)

project(APiR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)
set(OpenGL_GL_PREFERENCE LEGACY)

if(MSVC)
  set(CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS} /W4 /WX")
  set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS} /MT /O2 ${INTRINSICS} /Zi /MP /GL /DNDEBUG")
  set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS} /MTd /Od /Ob0 ${INTRINSICS} /RTC1 /Zi /D_DEBUG")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pthread -lGL -lGLU -lglut")
endif()

set(THIRD_PARTIES "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParties" CACHE PATH "" FORCE)
set(CMAKE_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/cmake" CACHE PATH "" FORCE)

option(ENABLE_CUDA "Turn on/off CUDA usage")
option(ENABLE_OPENCL "Turn on/off CUDA usage")
option(ENABLE_PYTHON_WRAPPER "Turn on/off Python wrappers")

# find/setuo all needed packages
include("${THIRD_PARTIES}/ThirdParties.cmake")

# Macros and other predefined stuff
include_directories(${CMAKE_FOLDER}/include)

# to future testing libs
enable_testing()

# main lib
include("cmake/generate_project.cmake")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_subdirectory(APiR)
