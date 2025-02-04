#!/usr/bin/env bash

# Ejemplo: leer un archivo línea a línea y procesar su contenido
# Guardar este archivo como 'leer_lineas.sh'

ARCHIVO="nombres.txt"

# Comprobamos que el archivo existe
if [[ ! -f "$ARCHIVO" ]]; then
  echo "El archivo '$ARCHIVO' no existe."
  exit 1
fi

# IFS indica el "Internal Field Separator".
# Al establecer IFS= (vacío) evitamos que se partan las líneas por espacios.
# Con read -r impedimos que se interpreten barras invertidas (\).
while IFS= read -r LINEA
do
  echo "He leído la línea: '$LINEA'"
  # Aquí podrías usar otras instrucciones con cada línea
done < "$ARCHIVO"


