#include <glwindow.cpp>
#include <visualization.cpp>

int main()
{
	GLFWwindow * window = glwindow::create();

	visualization::run(window);

	return EXIT_SUCCESS;
}
