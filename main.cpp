#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "headers/header.h"

int main() {
    if (!glfwInit()) {
        CallbackHelpers::log_error("GLFW Initialization failed.");
        return -1;
    }

    glfwSetErrorCallback(Callbacks::error_callback);

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window) {
        CallbackHelpers::log_error("Window creation failed.");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        CallbackHelpers::log_error("Failed to initialize GLAD.");
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, Callbacks::key_callback);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
