#include <cstring>
#include <GL/glew.h> // Se comunica con tu tarjeta grafica
#include <GL/gl.h> // Controla la iluminación y efectos especiales
#include <GLFW/glfw3.h>  // Libreria de opengl que maneja entrada de teclado y ratón
#include <imgui.h> // Nucleo de ImGui
#include <imgui_impl_glfw.h> // Libreria que permite entender teclado y ratón a ImGui
#include <imgui_impl_opengl3.h> // Libreria puente que permite que ImGui pueda dibujar en pantalla
#include <sqlite3.h> // Libreria de de base de datos
#include <string>
#include <cstdlib> // Usada para salir del codigo
#include "window.hpp"
#include "../clock/clock.hpp"

using namespace std;

void window::loop() {

    static bool Menu = true; // Comprueba si el usuario esta en el menu
    while (!glfwWindowShouldClose(ventana)) { // Comprueba si la ventana se tiene que cerrar
        glClearColor(0.171875f, 0.25f, 0.640625f, 1.0f); // Le dice a OpenGL los colores que debe usar para el proximo frame, estos son Rojo, Verde, Azul y Alfa (Transparencia)
        glClear(GL_COLOR_BUFFER_BIT); // Limpia cada frame antes de dibujar el siguiente
        ImGui_ImplOpenGL3_NewFrame(); // Le digo a OpenGL que se prepare para el siguiente frame
        ImGui_ImplGlfw_NewFrame(); // Le digo a OpenGL que se prepare para recibir operaciones i/o

        ImGui::NewFrame(); // Crea un nuevo frame de ImGui
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar;
        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetNextWindowSize(ImVec2(400.0f, 150.0f));
        ImGui::Begin("Sotewatch", NULL, flags);

        window::menu();

        string hour = uhr::clock();
        ImGui::GetFont()->Scale = 7.0f; //Accede a la variable fuente y modifica el valor scales
        ImGui::PushFont(ImGui::GetFont()); // Actualiza la fuente volviendo a comprobar su valor actual
        ImGui::SetCursorPos(ImVec2((400 - (ImGui::CalcTextSize(hour.c_str()).x + (ImGui::GetStyle().FramePadding.x * 2.0f))) * 0.5f, ImGui::GetCursorPosY() + 5.0f)); // Dummy se mueve el cursor usando como punto base la posición actual de este
            
        ImGui::Text("%s", hour.c_str());
        ImGui::PopFont();
        ImGui::GetFont()->Scale = 1.2f; // Restaura el tamaño a la normalidad
        ImGui::PushFont(ImGui::GetFont());
        ImGui::PopFont();

        ImGui::End(); // CIerra la ventana, ya que en ImGui la ventana se abre y cierra en bucle
        ImGui::Render(); // Reune y compila lo dibujado en el frame
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Muestra el nuevo frame por pantalla
        glfwSwapBuffers(ventana); // Actualiza la información en pantalla/Cambio de frame
        glfwPollEvents(); // Procesa los eventos de teclado y ratón
        }
    }