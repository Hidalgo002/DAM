#!/bin/bash

for (( i=1; i<=5; i++ ))
do
  if (( i == 3 )); then # También se puede expresar como [ $i -eq 3 ]
  	echo "Saltamos el número $i."
  	continue
  fi
  	echo "i = $i"
done
