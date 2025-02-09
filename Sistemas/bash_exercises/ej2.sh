#!/bin/bash

# Bucle que recorre los números del 0 al 5
for ((i=0; i<=5; i++))
do
    # Verifica si el número es par o impar
    if (( i % 2 == 0 )); then  # Si el residuo de la división entre 2 es 0, es par
        echo "El número $i es par"
    else
        echo "El número $i es impar"
    fi
done
