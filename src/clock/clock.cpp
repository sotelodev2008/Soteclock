#include <chrono>
#include "clock.hpp"

std::string uhr::clock() {
    auto ahora_utc = std::chrono::system_clock::now();     // obtenemos el punto de tiempo actual del sistema (siempre devuelve la hora base UTC, independienteente del UTC que uses)

    std::chrono::hours desfase_utc(2); // Aqui le añadimos el UTC que queramos

    auto hora_ajustada = ahora_utc + desfase_utc; // Sumamos las 2 horas para saber que hora tienen en esa franja horaria

    auto hora_segundos = std::chrono::floor<std::chrono::seconds>(hora_ajustada); // Sumamos la diferencia de tiempo

    return std::format("{:%T}", hora_segundos); // Devolvemos la hora ("{:%T}" es el código de formato estándar para HH:MM:SS)
}
