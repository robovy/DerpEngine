#include "window.h"

namespace Derp {
	namespace graphics {

		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Error" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "EPIC FAIL!!!" << std::endl;
				return false;
			}
			glfwSetWindowSizeCallback(m_Window, windowResize);
			glfwMakeContextCurrent(m_Window);
			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);			
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}
	}
}