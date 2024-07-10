#include "../headers/header.h"

void Callbacks::error_callback(int error, const char* description) {
    CallbackHelpers::log_error(description);
}

void Callbacks::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
