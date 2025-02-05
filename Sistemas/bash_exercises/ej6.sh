#!/bin/bash

for ARCHIVO in test6/*.txt
do
	TOTAL_LINEAS=$(wc -l < "$ARCHIVO"); #variable TOTAL_LINEAS

	if [[ "$TOTAL_LINEAS" -ge 3 ]]; then #-ge es un comparador de números
		echo "El archivo $ARCHIVO tiene más de 3 líneas"
	else
		echo "El archivo $ARCHIVO tiene 3 líneas o menos"	
	fi
done

#OTROS COMPARADORES EN LUGAR DE -ge
# - eq: igual a (`==`)
# - ne: distinto de (`!=`)
# - gt: mayor que (`>`)
# - ge: mayor o igual que (`>=`)
# - lt: menor que (`<`)
# - le: menor o igual que (`<=`)