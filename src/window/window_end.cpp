#include <cstring>
#include <GL/glew.h> // Se comunica con tu tarjeta grafica
#include <GL/gl.h> // Controla la iluminación y efectos especiales
#include <GLFW/glfw3.h>  // Libreria de opengl que maneja entrada de teclado y ratón
#include <imgui.h> // Nucleo de ImGui
#include <imgui_impl_glfw.h> // Libreria que permite entender teclado y ratón a ImGui
#include <imgui_impl_opengl3.h> // Libreria puente que permite que ImGui pueda dibujar en pantalla
#include <sqlite3.h> // Libreria de de base de datos
#include <cstdlib> // Usada para salir del codigo
#include "window.hpp"

using namespace std;

int window::end() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(ventana); // Cierra la ventana y la elimina de la memoria ram
    glfwTerminate(); // Termina esta instancia de OpenGL
    return 0;
}
