
#include <stdio.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

GLFWwindow *g_wnd;
char g_close = 0;

void close (GLFWwindow *wnd)
{
  (void) wnd;
  g_close = -1;
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

int create_window (char full)
{
  GLFWmonitor *m = NULL;
  if (full)
    m = glfwGetPrimaryMonitor();
  if (!(g_wnd = glfwCreateWindow(800, 600, "gldemo", m, NULL)))
    return -1;
  printf("g_wnd %p\n", g_wnd);
  glfwSetWindowCloseCallback(g_wnd, close);
  glfwSetFramebufferSizeCallback(g_wnd, size);
  return 0;
}

int main (int argc, char *argv[])
{
  (void) argc;
  (void) argv;
  if (glfwInit() == GLFW_TRUE) {
    if (create_window(0))
      return 1;
    while (!g_close) {
      glfwPollEvents();
      draw();
    }
    glfwDestroyWindow(g_wnd);
    glfwTerminate();
    return 0;
  }
  return 1;
}
