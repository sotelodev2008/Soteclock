#include <mini/ini.h>
#include <string>
#include "config.hpp"

void config::config_ini(config::configreloj& config, const std::string& file) { //Las variables comparten la misma dirección de memoria que las definidas en el hpp
    mINI::INIFile filename(file); // Permite al programa comunicarse con el archivo que se encuentre en la variable
    mINI::INIStructure ini; // Crea un pequeño espacio en la ram para que todos los datos del ini esten dentro
    filename.read(ini); // Lee el archivo ini

    config.idioma = ini["idioma"]["idioma"].empty() ? "español" : ini["idioma"]["idioma"]; // Accede al apartado idioma y mediante el operador ?, este se activa en caso de que se cumpla la condición anterior
    config.utc = ini["Reloj"]["utc"].empty() ? 2 : std::stoi(ini["Reloj"]["utc"]);
    config.r_fondo = ini["Reloj"]["r_fondo"].empty() ? 0.0f : std::stof(ini["Reloj"]["r_fondo"]);
    config.g_fondo = ini["Reloj"]["g_fondo"].empty() ? 0.0f : std::stof(ini["Reloj"]["g_fondo"]);
    config.b_fondo = ini["Reloj"]["b_fondo"].empty() ? 0.0f : std::stof(ini["Reloj"]["b_fondo"]);
    config.dark_text = (ini["Reloj"]["usar_texto_claro"] == "true");

    filename.write(ini);
}

void config::config_check(config::configreloj &config, const std::string &file) {
    mINI::INIFile filename(file); // Permite al programa comunicarse con el archivo que se encuentre en la variable
    mINI::INIStructure ini; // Crea un pequeño espacio en la ram para que todos los datos del ini esten dentro
    filename.read(ini); // Lee el archivo ini

    bool file_exists = filename.read(ini);

    if (file_exists || !ini.has("Reloj")) { // Comprueba si el archivo fue creado, en caso negativo, lo crea y coloca la configuración predeterminada
        // El operador || comprueba si el primer valor es verdadero, en caso de serlo se salta la siguiente comprobación
        ini["idioma"]["idioma"] = "español";
        ini["Reloj"]["utc"] = "2";
        ini["Reloj"]["r_fondo"] = "0.15";
        ini["Reloj"]["g_fondo"] = "0.15";
        ini["Reloj"]["b_fondo"] = "0.20";
        ini["Reloj"]["usar_texto_claro"] = "true";
        
        // Creamos el archivo físico limpio en el disco
        bool save = filename.generate(ini, true); 
    }

    filename.write(ini);
}
