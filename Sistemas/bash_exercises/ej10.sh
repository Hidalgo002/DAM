#!/bin/bash

#ps es 'process status'

ps aux >> processes.txt #Guardamos la salida del estado de todos los procesos de ejecución en el .txt de forma iterativa

for PROC in $(cat processes.txt)
do

    if ps aux | grep -q "$PROC"; then #Lee cada palabra del archivo.
        #Si el patrón se encuentra en el texto, grep -q devuelve un código de salida 0 (VERDADERO).
        # Si el patrón no se encuentra, devuelve un codigo de salida 1 (FALSO)
        echo "El proceso '$PROC' está en ejecución"
    else
        echo "El proceso '$PROC' no está en ejecución"
    fi
done

# MAS DE PS

#ps aux -> Muestra todos los procesos del sistema, incluidos los de otros usuarios y sin terminal.
#ps -e -> Muestra todos los procesos en ejecución.
#ps -f -> Muestra detalles adicionales como el usuario y el PID padre.
#ps -u usuario -> Muestra solo los procesos de un usuario específico.
#ps -p PID -> Muestra información de un proceso específico por su PID.