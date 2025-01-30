#!/bin/bash

for ((i=0;i<=5;i++))
  do
    if (( i % 2 == 0 )); then
      echo "El número $i es par"
    else
      echo "El número $i es impar"
    fi
  done