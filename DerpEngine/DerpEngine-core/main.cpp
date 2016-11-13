#include <iostream>
#include <GLFW/glfw3.h>

#include "src/graphics/window.h"

int main()
{
	using namespace Derp;
	using namespace graphics;

	Window window("Derp", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5,  0.5);
		glVertex2f( 0.5,  0.5);
		glVertex2f( 0.5, -0.5);
		glEnd();
		window.update();
	}

	return 0;
}