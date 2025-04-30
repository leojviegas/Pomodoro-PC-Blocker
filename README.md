# Pomodoro PC Blocker

Este programa implementa un **bloqueador de PC basado en la técnica Pomodoro**, diseñado para fomentar la productividad y el descanso saludable durante sesiones de trabajo o estudio. Utiliza la técnica Pomodoro, que consiste en alternar períodos de trabajo concentrado con descansos cortos y largos, bloqueando la PC durante los descansos para evitar distracciones.

## **Características principales**
- **Configuración personalizada**:
  - Define la duración de los Pomodoros (trabajo) y descansos (cortos y largos).
  - Configura la frecuencia de descansos largos y la cantidad total de Pomodoros.
- **Cálculo automático**:
  - Calcula el tiempo total de la sesión y lo muestra en minutos y en formato horas:minutos.
- **Bloqueo de la PC**:
  - Durante los descansos, la PC se bloquea automáticamente para garantizar que el usuario descanse.
- **Interfaz interactiva**:
  - Solicita parámetros al usuario y muestra mensajes claros sobre el progreso de la sesión.

## **Requisitos**
- **Sistema operativo**: Windows (utiliza el comando `LockWorkStation` para bloquear la PC).
- **Compilador**: Compatible con cualquier compilador de C estándar (por ejemplo, GCC).

## **Cómo usarlo**
1. Compila el programa:
   ```bash
   gcc -o pomodoroPCBlocker pomodoroPCBlocker.c