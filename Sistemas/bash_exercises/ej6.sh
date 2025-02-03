#!/bin/bash

for ARCHIVO in test6/*.txt;
do
	TOTAL_LINEAS = $(wc -l "$ARCHIVO");
	if [[ TOTAL_LINEAS > 3 ]]; then
		echo "El archivo $ARCHIVO tiene más de 3 líneas"
	else
		echo "El archivo $ARCHIVO tiene 3 líneas o menos"	
	fi
done
