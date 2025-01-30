#!/bin/bash

for archivo in test3/*.txt
do
  if grep -q "ERROR" "$archivo"; then
    echo "El archivo $archivo contiene errores"
  else
    echo "El archivo $archivo está limpio"
  fi
done

#grep -q suprime la salida y solo fija un estado de éxito si encontró el patrón. Entonces, si buscamos con grep -q la palabra "ERROR" en nuestro archivo .txt y existe la palabra, se imprime "contiene errores"