#pragma once

#include <cstdlib>
#include <glheaders.h>
#include <string>

namespace {

	int windowWidth = 1024;
	int windowHeight = 680;
	std::string windowTitle = "SmoothLife";

	void glfwErrorCallback(int error, const char * description)
	{
		fprintf(stderr, "GLFW error:\n\t%s (%i)\n", description, error);
	}

}

namespace glwindow {

	GLFWwindow * create()
	{
		// Initialise GLFW
		if (!glfwInit()) {
			fprintf(stderr, "GLFW init failure\n");
			exit(EXIT_FAILURE);
		}

		glfwSetErrorCallback(glfwErrorCallback);

		// Create window
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, true);

		GLFWwindow * window =
			glfwCreateWindow(windowWidth, windowHeight,
			                 windowTitle.c_str(), nullptr, nullptr);

		if (!window) {
			fprintf(stderr, "GLFW window creation failure\n");
			exit(EXIT_FAILURE);
		}

		// Let the window be the current OpenGL context and run glad
		glfwMakeContextCurrent(window);
		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
			fprintf(stderr, "GLAD loader error\n");
			exit(EXIT_FAILURE);
		}

		return window;
	}

}
