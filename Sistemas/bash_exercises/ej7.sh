#!/bin/bash

for ARCHIVO in test7

	do
		if [[ "$ARCHIVO" == '*.conf' ]]; then
			sed -i 's/localhost/127.0.0.1/g' "$ARCHIVO"
			echo "El archivo $ARCHIVO ha sido modificado."
		continue
		fi

	done