#pragma once

#include <glheaders.h>

namespace visualization {

	void run(GLFWwindow * window)
	{
		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

}
