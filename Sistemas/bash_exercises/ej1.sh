#!/bin/bash

for archivo in test1/*.txt 
	do
		if grep -q '.' "$archivo"; then
			echo "El archivo $archivo NO está vacío."
		else
			echo "El archivo $archivo está vacío."
		fi
	done
