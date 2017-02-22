cmake_minimum_required (VERSION 3.0)
project (smoothlife)

# Use modern C++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

# Warning everything
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Build GLFW
option (GLFW_INSTALL OFF)
option (GLFW_BUILD_DOCS OFF)
option (GLFW_BUILD_EXAMPLES OFF)
option (GLFW_BUILD_TESTS OFF)
add_subdirectory (vendor/glfw)

# Build GLAD
add_library(
	glad
		vendor/glad/src/glad.c
	)

# Set include paths
include_directories (
	src
	vendor/glad/include
	vendor/glfw/include
	)

# Compile and link
add_executable (
	${PROJECT_NAME}
		src/main.cpp
	)

target_link_libraries (
	${PROJECT_NAME}
		glfw ${GLFW_LIBRARIES}
		glad dl
	)
