#!/bin/bash

for USUARIO in $(cat test8/usuarios.txt); # En nuestra variable USUARIO se van almacenando los nombres

do

    if [ "$USUARIO" == "maria" ]; then #Comprueba si el usuario es "maria"
        echo "Hola maria"
    else 
        echo "Hola, $USUARIO"
    fi

done
 