#pragma once
#include <string>

namespace config{
    struct configreloj {
        std::string idioma;
        int utc;
        float r_fondo;
        float g_fondo;
        float b_fondo;
        bool dark_text;
    };
    void config_ini(configreloj& config, const std::string& file);
    void config_check(configreloj& config, const std::string& file);
}