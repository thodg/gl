
#include <GL/gl.h>
#include <GLFW/glfw3.h>

GLFWwindow *g_wnd;

void close (GLFWwindow *wnd)
{
  (void) wnd;
  glfwSetWindowShouldClose(g_wnd, GLFW_TRUE);
}

void size (GLFWwindow *wnd, int w, int h)
{
  (void) wnd;
  (void) w;
  (void) h;
}

void draw ()
{
  glClear(GL_COLOR);
}

void create_window (char full)
{
  GLFWmonitor *m = NULL;
  if (full)
    m = glfwGetPrimaryMonitor();
  g_wnd = glfwCreateWindow(800, 600, "gldemo", m, NULL);
  glfwSetWindowCloseCallback(g_wnd, close);
  glfwSetFramebufferSizeCallback(g_wnd, size);
}

int main (int argc, char *argv[])
{
  (void) argc;
  (void) argv;
  if (glfwInit() == GLFW_TRUE) {
    create_window(0);
    while (!glfwWindowShouldClose(g_wnd)) {
      glfwPollEvents();
      draw();
    }
    glfwDestroyWindow(g_wnd);
    glfwTerminate();
    return 0;
  }
  return 1;
}
