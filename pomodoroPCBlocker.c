#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void blockPC();

int tiempoDeTrabajo = 45;         // tiempo del pomodoro en minutos (periodo de trabajo)
int tiempoDeDescanso = 15;         // tiempo de descanso en minutos
int cantidadTotalDePomodoros = 2; // ciclos totales que van a ocurrir

int main()
{
    printf("Bienvenido al PC time blocker\nelija a continuacion los tiempos en los cuales desea que la PC siga activa\n");
    printf("elija tiempo de trabajo:\n");
    scanf("%i", &tiempoDeTrabajo);
    printf("elija tiempo de descanso:\n");
    scanf("%i", &tiempoDeDescanso);
    printf("elija cantidad total de pomodoros a realizarse:\n");
    scanf("%i", &cantidadTotalDePomodoros);
    printf("Usted ha elegido %d minutos de trabajo, %d de descanso y %d pomodoros totales\n", tiempoDeTrabajo, tiempoDeDescanso, cantidadTotalDePomodoros);
    printf("Dando un total de %.2f horas\n", ((tiempoDeTrabajo + tiempoDeDescanso) * cantidadTotalDePomodoros)/60.0);
    

    for (int i = 0; i < cantidadTotalDePomodoros; i++) // repetir todo el ciclo "cantidadTotalDePomodoros" veces
    {
        printf("Pomodoro %d en proceso...\n", i + 1);
        for (int j = tiempoDeTrabajo; j > 0; j--) // loop para que el programa espere "tiempoDeTrabajo" minutos antes de llamar a blockPC()
        {
            //printf("quedan %d minutos para el descanso\n", j);
            Sleep(60 * 1000); // esperar 1 minuto
        }

        blockPC();
    }
    printf("\nEsperamos que le haya resultado util el programa!\n");
    system("pause");
    return 0;
}

void blockPC() // manda comando de bloquear PC cada 5s, por "tiempoDeDescanso" minutos. Así te obliga a salir de la PC sí o sí y levantarte
{
    int lockEveryXSeconds = 1;

    printf("Tiempo de descanso\n\n");
    for (int i = 0; i < tiempoDeDescanso; i++)
    {
        for (int j = 0; j < 60 / lockEveryXSeconds; j++) // al dividir 60/cada cuanto quiero que se mande el comando de bloquear, hago que ese loop
                                                         // se ejecute por 1 min exactamente
        {
            system("rundll32.exe user32.dll,LockWorkStation"); // bloquear PC en sesión actual
            Sleep(lockEveryXSeconds * 1000); // esperar lockEveryXSeconds segundos
        }
    }
}
