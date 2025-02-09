#!/bin/bash

# Bucle que recorre todos los archivos con extensión .txt dentro del directorio "test1"
for archivo in test1/*.txt 
do
    # Verifica si el archivo contiene al menos un carácter
    if grep -q '.' "$archivo"; then  
        echo "El archivo $archivo NO está vacío."  # Mensaje si el archivo tiene contenido
    else
        echo "El archivo $archivo está vacío."  # Mensaje si el archivo está vacío
    fi
done
