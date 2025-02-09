#!/bin/bash

# Bucle que recorre todos los archivos dentro del directorio "test7/"
for ARCHIVO in test7/*; do
    # Verifica si el nombre del archivo termina en ".conf"
    if [[ "$ARCHIVO" == *.conf ]]; then  
        # Usa 'sed' para reemplazar "localhost" por "127.0.0.1" en el archivo (de forma permanente con -i)
        sed -i 's/localhost/127.0.0.1/g' "$ARCHIVO"
        
        # Muestra un mensaje indicando que el archivo ha sido modificado
        echo "El archivo $ARCHIVO ha sido modificado."
    fi
done
