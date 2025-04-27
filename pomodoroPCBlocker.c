#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int pedirNumero(const char *mensaje);
void tiempoTrabajo();
void blockPC(int tiempoDescanso);

int tiempoPomodoro = 0;     // tiempo del pomodoro en minutos (periodo de trabajo)
int tiempoDescansoCorto = 0; // tiempo de descanso en minutos
int tiempoDescansoLargo = 0;
int frecuenciaDescLargo = 0;
int cantidadPomodoros = 0;
int cantDescansosCortos = 0;
int cantDescansosLargos = 0;
int minutosTotales = 0;
int main()
{
    printf("Bienvenido al PC time blocker\n");
    tiempoPomodoro = pedirNumero("Elegi tiempo del pomodoro (en minutos):\n");
    tiempoDescansoCorto = pedirNumero("Elegi tiempo de descanso corto (en minutos):\n");
    tiempoDescansoLargo = pedirNumero("Elegi tiempo de descanso largo (en minutos):\n");
    frecuenciaDescLargo = pedirNumero("Cada cuantos pomodoros deseas un descanso largo? (si se eligio 25/5, se recomienda cada 4; si se eligio 50/10, cada 2):\n");
    cantidadPomodoros = pedirNumero("Elegi cantidad total de pomodoros a realizarse:\n");
    
    cantDescansosLargos = cantidadPomodoros / frecuenciaDescLargo;
    cantDescansosCortos = cantidadPomodoros - cantDescansosLargos;
    minutosTotales = tiempoPomodoro * cantidadPomodoros + tiempoDescansoLargo * cantDescansosLargos + tiempoDescansoCorto * cantDescansosCortos;
    
    printf("\nElegiste %d minutos de pomodoro, %d de descanso corto, %d de descanso largo, descanso largo cada %d minutos y %d pomodoros totales.\n", tiempoPomodoro, tiempoDescansoCorto, tiempoDescansoLargo, frecuenciaDescLargo, cantidadPomodoros);

    printf("Dando un total de %d minutos, ", minutosTotales);
    printf("que serian %d:%d hs\n", (minutosTotales / 60), (minutosTotales % 60));

    printf("\n                             Presiona ENTER para comenzar el programa\n");
    getchar(); // Esperar a que el usuario presione ENTER antes de continuar

    tiempoTrabajo();
    printf("\nEsperamos que te haya resultado util el programa!\n");
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
            printf("Entrada invalida. Por favor, ingresa un numero.\n");
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

        if (frecuenciaDescLargo > 0 && (i + 1) % frecuenciaDescLargo == 0) // Verificar si corresponde un descanso corto o largo
        {
            printf("Descanso largo iniciado...\n");
            blockPC(tiempoDescansoLargo);
        }
        else
        {
            printf("Descanso corto iniciado...\n");
            blockPC(tiempoDescansoCorto);
        }
    }
}

void blockPC(int tiempoDescanso)
{
    int lockEveryXSeconds = 1;
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
