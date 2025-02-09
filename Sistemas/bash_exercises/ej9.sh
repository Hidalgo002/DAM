#!/bin/bash

for SUBDIR in test9/*; do
    if [ -d "$SUBDIR" ]; then #-d comprieba si estamos en un directorio
        for archivo in "$SUBDIR"/*.txt; do
            if [ -f "$archivo" ]; then #-f comprueba si el archivo existe
            head -n 1 "$archivo" #Muestra la primera línea del archivo de todos los archivos
            fi
        done
    fi
done