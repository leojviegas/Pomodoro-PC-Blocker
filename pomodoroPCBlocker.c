#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int pedirNumero(const char *mensaje);
void tiempoTrabajo();
void blockPC(int tiempoDescanso);

int tiempoPomodoro = 0;     // tiempo del pomodoro en minutos (periodo de trabajo)
int tiempoDescansoCorto = 0; // tiempo de descanso en minutos
int tiempoDescansoLargo = 0;
int cantidadPomodoros = 0;
int descansoLargoCada = 0;

int main()
{
    printf("Bienvenido al PC time blocker\n");
    tiempoPomodoro = pedirNumero("Elija tiempo de trabajo (en minutos):\n");
    tiempoDescansoCorto = pedirNumero("Elija tiempo de descanso corto (en minutos):\n");
    tiempoDescansoLargo = pedirNumero("Elija tiempo de descanso largo (en minutos):\n");
    descansoLargoCada = pedirNumero("Cada cuántos pomodoros desea un descanso largo? (si se eligio 25/5, se recomienda cada 4; si se eligio 50/10, cada 2):\n");
    cantidadPomodoros = pedirNumero("Elija cantidad total de pomodoros a realizarse:\n");

    printf("Usted ha elegido %d minutos de trabajo, %d de descanso corto, %d de descanso largo y %d pomodoros totales.\n", tiempoPomodoro, tiempoDescansoCorto, tiempoDescansoLargo, cantidadPomodoros);
    printf("Dando un total de %.2f horas\n", ((tiempoPomodoro + tiempoDescansoCorto) * cantidadPomodoros) / 60.0);

    tiempoTrabajo();
    printf("\nEsperamos que le haya resultado útil el programa!\n");
    system("pause");
    return 0;
}

int pedirNumero(const char *mensaje) {
    int numero;
    int resultado;
    do {
        printf("%s", mensaje);
        resultado = scanf("%d", &numero);
        while (getchar() != '\n'); // Limpiar el buffer de entrada
        if (resultado != 1) {
            printf("Entrada inválida. Por favor, ingrese un número.\n");
        }
    } while (resultado != 1);
    return numero;
}


void tiempoTrabajo()
{
    for (int i = 0; i < cantidadPomodoros; i++) // repetir todo el ciclo "cantidadTotalDePomodoros" veces
    {
        printf("Pomodoro %d en proceso...\n", i + 1);
        for (int j = tiempoPomodoro; j > 0; j--) // loop para que el programa espere "tiempoDeTrabajo" minutos antes de llamar a blockPC()
        {
            // printf("quedan %d minutos para el descanso\n", j);
            Sleep(60 * 1000); // esperar 1 minuto
        }

        if (descansoLargoCada > 0 && (i + 1) % descansoLargoCada == 0) // Verificar si corresponde un descanso largo
        {
            printf("Descanso largo en proceso...\n");
            blockPC(tiempoDescansoLargo);
        }
        else
        {
            printf("Descanso corto en proceso...\n");
            blockPC(tiempoDescansoCorto);
        }
    }
}

void blockPC(int tiempoDescanso) // Modificar para aceptar el tiempo de descanso como parámetro
{
    int lockEveryXSeconds = 1;

    printf("Tiempo de descanso\n\n");
    for (int i = 0; i < tiempoDescanso; i++)
    {
        for (int j = 0; j < 60 / lockEveryXSeconds; j++) // al dividir 60/cada cuanto quiero que se mande el comando de bloquear, hago que ese loop
                                                         // se ejecute por 1 min exactamente
        {
            system("rundll32.exe user32.dll,LockWorkStation"); // bloquear PC en sesión actual
            Sleep(lockEveryXSeconds * 1000);                   // esperar lockEveryXSeconds segundos
        }
    }
}
