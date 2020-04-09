#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "main.h"

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

using namespace std;
using namespace application;

float red = 0.0f;
float green = 0.0f;
float blue = 0.0f;
int screenWidth = 800;
int screenHeight = 600;
char title[12] = "Exercicio 1";


void InputManager(GLFWwindow* window, int key, int scancode, int action, int mods);
void modsInput(GLFWwindow* window, unsigned int codepoint, int mods);
void setFullScreen(GLFWwindow* window);
void setWindowedScreen(GLFWwindow* window);

int main() {
	GLFWwindow *window;

	if (!glfwInit()) return -1;

	GLFWmonitor* monitor = glfwGetPrimaryMonitor(); //gets monitor
	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor); //Gets Video Settings

	cout << "w: " << videoMode->width << "h: " << videoMode->height << "@ " << videoMode->refreshRate << "fps" << endl;

	window = glfwCreateWindow(screenWidth, screenHeight, title, nullptr , nullptr); //Creates window with glfw

	if (!window) { //If window is null
		glfwTerminate(); //Terminate glfw //~bug preventing measure
		return -1;
	}

	glfwMakeContextCurrent(window); //make the context the window

	//Callback Functions
	glfwSetKeyCallback(window, InputManager); //Input with keys
	glfwSetCharModsCallback(window, modsInput); //Input with Mods

	glfwSwapInterval(1); //sets v-Sync
	
	App app = App(); //Initiate app that runs

	while (!glfwWindowShouldClose(window)) { //Indica pedido de fecho glfwSetWindowShouldClose(window, 1); //Pede para fechar
		
		app.update(); //app's update

		glClearColor(red, green, blue, 1.0f); //select Color clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //open gl clear

		glfwSwapBuffers(window); //Buffers
		glfwPollEvents(); //Events
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}



void InputManager(GLFWwindow* window, int key, int scancode, int action, int mods) { //Keys Input manager

	if (action == GLFW_PRESS) {
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			cout << "pressed esc" << endl;
			glfwSetWindowShouldClose(window, 1); //Pede para fechar
			break;
		case GLFW_KEY_R:
			red = 1.0f;
			break;
		case GLFW_KEY_G:
			green = 1.0f;
			break;
		case GLFW_KEY_B:
			blue = 1.0f;
			break;
		case GLFW_KEY_P:
			red = 0.0f; green = 0.0f; blue = 0.0f;
			break;
		case GLFW_KEY_1:
			setFullScreen(window);
			break;
		case GLFW_KEY_2:
			setWindowedScreen(window);
			break;

		}
	}
}

void modsInput(GLFWwindow* window, unsigned int codepoint, int mods) { //Mods Inputmanager

	if (codepoint == 'a' && mods == GLFW_MOD_SHIFT) {
		cout << "shift + a" << endl;

	}


}

void setFullScreen(GLFWwindow* window) { //Set Full screen
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	glfwSetWindowMonitor(window, monitor, 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);

}

void setWindowedScreen(GLFWwindow* window) { //Set Windowed

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	glfwSetWindowMonitor(window, NULL, videoMode->width / 2, videoMode->height / 2, screenWidth, screenHeight, videoMode->refreshRate);

}


