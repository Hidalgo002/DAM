
🐉
Práctica 8 - "Cazadores de Dragones"
Descripción
Eres el encargado de diseñar un juego basado en un universo de cazadores que luchan contra dragones. Los jugadores podrán seleccionar un cazador y enfrentarse a diversos dragones en un combate por turnos, ganando recompensas en oro si los derrotan. Además, podrán añadir cazadores o dragones especiales para hacer el juego más dinámico y retador.

Esta práctica se realizará en parejas. Cada función debe incluir un comentario indicando si ha sido implementada por un miembro del equipo, el otro, o entre los dos. Algunas funciones deben ser implementadas individualmente.

Las restricciones e indicaciones que se ofrecen son guías y mínimos. Si implementas el juego tal cual se propone, no va a ser un superjuego top en ventas. Tienes libertad absoluta para mejorar y reorientar este juego para hacerlo una experiencia jugable. Por ejemplo, ¿hay formas de curarse? ¿Los dragones dejan objetos además de dinero? No te vuelvas loco (porque hay una fecha de entrega a la que llegar), pero disfrútalo.

Objetivos de la Práctica
Aplicar programación modular en C, dividiendo el código en múltiples archivos.
Practicar estructuras de datos definiendo estructuras para cazadores y dragones.
Implementar un sistema de combate por turnos, con ataques aleatorios de los dragones.
Manejar memoria dinámica correctamente, asegurando su liberación con free().
Desarrollar un menú interactivo para gestionar la selección de personajes y combate.
Mecánica del Juego
El juego seguirá una estructura de menú donde el jugador podrá realizar diversas acciones antes y después de los combates.

Flujo del Juego
Pantalla de inicio y menú principal
Se muestra un mensaje de bienvenida y las opciones disponibles.
Selección de cazador
El jugador elige entre los cazadores disponibles, viendo sus atributos.
Selección de dragón enemigo
Se muestra una lista con los dragones disponibles.
Cada dragón tiene un nivel de dificultad y recompensa en oro distinta.
Sistema de combate por turnos
Todos los cazadores atacan primero, reduciendo la vida del dragón elegido.
Luego, cada dragón ataca a un cazador aleatorio, reduciendo su vida.
Se repite el proceso hasta que todos los dragones o cazadores sean eliminados.
Fin del combate
Se muestran los resultados.
Si el cazador ha ganado, obtiene el oro del dragón.
Si el cazador ha perdido, puede elegir otro cazador o salir del juego.
Opciones después del combate
Volver al menú principal.
Elegir otro dragón para luchar.
Agregar nuevos cazadores o dragones.
Finalizar el juego.
Condiciones de finalización
El juego termina cuando el jugador lo decide o no quedan cazadores disponibles.
Gana el cazador que haya acumulado más oro.
Menú Principal
El menú principal del juego debe permitir al usuario seleccionar entre las siguientes opciones:

Seleccionar un cazador
Muestra una lista de los cazadores disponibles con sus atributos.
Permite elegir un cazador para jugar.
Luchar contra un dragón
Muestra la lista de dragones disponibles con sus atributos.
Permite elegir un dragón para el combate.
Añadir un nuevo cazador
Permite al usuario introducir un nuevo cazador con sus atributos (nombre, habilidad, vida, oro inicial).
Añadir un nuevo dragón
Permite al usuario introducir un nuevo dragón con sus atributos (nombre, vida, nivel, ataque, oro).
Mostrar los resultados finales
Muestra un ranking de los cazadores según el oro acumulado.
Salir del juego
Termina la ejecución del programa.
Estructura del Proyecto
Para organizar correctamente el código, el juego debe dividirse en varios archivos:

main.c: Controla el flujo del juego y el menú principal.
cazador.h y cazador.c: Definición e implementación de los cazadores.
dragon.h y dragon.c: Definición e implementación de los dragones.
combate.h y combate.c: Implementación del sistema de combate.
utilidades.h y utilidades.c: Funciones auxiliares como validaciones y entrada de datos (si son necesarias).
Sistema de Combate con Turnos
El combate se realiza por turnos entre los cazadores y los dragones.

Inicio del combate
Se muestra un mensaje indicando que el combate ha comenzado.
Se muestran los atributos del cazador y el dragón.
Turno del cazador
Cada cazador elige a qué dragón atacar.
Se calcula el daño del cazador en función de su habilidad.
Se resta ese valor a la vida del dragón.
Se muestra la cantidad de daño causado.
Turno del dragón
Si el dragón aún tiene vida, ataca a un cazador aleatorio.
Se resta su ataque a la vida del cazador elegido.
Se muestra el daño recibido.
Condiciones de victoria y derrota
Si la vida del dragón llega a 0, el cazador gana el combate y obtiene su oro.
Si la vida del cazador llega a 0 antes de derrotar al dragón, el jugador pierde y debe elegir otro cazador o salir.
Mostrar resultados del combate
Se muestra un mensaje indicando si el cazador ha ganado o perdido.
Se actualizan los atributos del cazador (oro y vida).
Se da la opción de continuar el juego o salir.
Ejemplo de Combate
--- ¡Comienza el combate! ---
Cazador: Arthur (Vida: 100, Habilidad: 12, Oro: 0)
Vs.
Dragón: Smaug (Vida: 80, Nivel: 5, Ataque: 10, Oro: 50)

Turno 1:
Arthur ataca a Smaug y le causa 12 de daño.
Smaug ahora tiene 68 de vida.

Smaug ataca a un cazador aleatorio... ¡Gornak recibe 15 de daño!
Gornak ahora tiene 105 de vida.

...

Turno 7:
Arthur ataca y derrota a Smaug.

--- ¡Victoria! ---
Arthur ha derrotado a Smaug y ha ganado 50 de oro.

Compilación y Uso de Archivos
Para compilar el programa con múltiples archivos en GCC:

gcc main.c cazador.c dragon.c combate.c utilidades.c memoria.c -o cazadores
Para ejecutar:

./cazadores
Uso de Makefile
Para facilitar la compilación, se recomienda un Makefile:

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = main.o cazador.o dragon.o combate.o utilidades.o memoria.o

cazadores: $(OBJ)$(CC) $(CFLAGS) -o cazadores $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o cazadores

Compilar con:

make
Eliminar archivos temporales:

make clean
Entrega Parcial
Antes de la fecha final de entrega, se revisará el código para corregir errores y proporcionar feedback.

Evaluación
Se evaluará según los siguientes criterios:

Estructura del código: Uso de archivos .h y .c, modularidad y encapsulación.
Corrección del programa: Funcionamiento sin errores en distintos escenarios.
Gestión de memoria: Uso correcto de malloc/calloc/free, sin fugas de memoria (verificado con Valgrind).
Legibilidad del código: Código limpio, comentado y organizado.
Trabajo en equipo: Evidencia de contribuciones individuales y en conjunto.
Se realizará una defensa pública de tu solución.
Líneas de mejora (que no suben nota pero molan que flipas)
La terminal de ubuntu acepta colores en los mensajes que se imprimen.
Guardar partida almacenando la información del estado en un archivo.
Desarrollar una inteligencia en el dragón para que intente ganar y sea difícil.
¡Buena suerte, cazadores! 🏹🐉
