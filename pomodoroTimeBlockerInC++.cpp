#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

void blockPC();

int tiempoDeTrabajo = 45;         // tiempo del pomodoro en minutos (periodo de trabajo)
int tiempoDeDescanso = 15;         // tiempo de descanso en minutos
int cantidadTotalDePomodoros = 2; // ciclos totales que van a ocurrir
//comentario de prueba
int main()
{
    std::cout << "Bienvenido al PC time blocker\nelija a continuacion los tiempos en los cuales desea que la PC siga activa\n";
    std::cout << "elija tiempo de trabajo:\n";
    std::cin >> tiempoDeTrabajo;
    std::cout << "elija tiempo de descanso:\n";
    std::cin >> tiempoDeDescanso;
    std::cout << "elija cantidad total de pomodoros a realizarse:\n";
    std::cin >> cantidadTotalDePomodoros;
    std::cout << "Usted ha elegido " << tiempoDeTrabajo << " minutos de trabajo, " << tiempoDeDescanso << " de descanso y " << cantidadTotalDePomodoros << " pomodoros totales\n";
    std::cout << "Dando un total de " << ((tiempoDeTrabajo + tiempoDeDescanso) * cantidadTotalDePomodoros) / 60.0 << " horas\n";

    for (int i = 0; i < cantidadTotalDePomodoros; i++) // repetir todo el ciclo "cantidadTotalDePomodoros" veces
    {
        std::cout << "Pomodoro " << i + 1 << " en proceso...\n";
        for (int j = tiempoDeTrabajo; j > 0; j--) // loop para que el programa espere "tiempoDeTrabajo" minutos antes de llamar a blockPC()
        {
            std::this_thread::sleep_for(std::chrono::minutes(1)); // esperar 1 minuto
        }

        blockPC();
    }
    std::cout << "\nEsperamos que le haya resultado util el programa!\n";
    system("pause");
    return 0;
}

void blockPC() // manda comando de bloquear PC cada 5s, por "tiempoDeDescanso" minutos. Así te obliga a salir de la PC sí o sí y levantarte
{
    time_t time = 3;
    int lockEveryXSeconds = 1;

    std::cout << "Tiempo de descanso\n\n";
    for (int i = 0; i < tiempoDeDescanso; i++)
    {
        for (int j = 0; j < 60 / lockEveryXSeconds; j++) // al dividir 60/cada cuanto quiero que se mande el comando de bloquear, hago que ese loop
                                                         // se ejecute por 1 min exactamente
        {
            system("rundll32.exe user32.dll,LockWorkStation"); // bloquear PC en sesión actual
            std::this_thread::sleep_for(std::chrono::seconds(lockEveryXSeconds)); // esperar lockEveryXSeconds segundos
        }
    }
}

