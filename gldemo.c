
#include <stdio.h>
#include <GLFW/glfw3.h>

void size (GLFWwindow *wnd, int w, int h)
{
  (void) wnd;
  (void) w;
  (void) h;
}

void draw ()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

GLFWwindow * create_window (char full)
{
  GLFWmonitor *m = NULL;
  GLFWwindow *wnd;
  if (full)
    m = glfwGetPrimaryMonitor();
  if (!(wnd = glfwCreateWindow(800, 600, "gldemo", m, NULL)))
    return 0;
  printf("wnd %p\n", wnd);
  glfwSetFramebufferSizeCallback(wnd, size);
  return wnd;
}

int main ()
{
  GLFWwindow *wnd;
  if (glfwInit() != GLFW_TRUE)
    return 1;
  if (!(wnd = create_window(0)))
    return 1;
  while (!glfwWindowShouldClose(wnd)) {
    draw();
    glfwSwapBuffers(wnd);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
