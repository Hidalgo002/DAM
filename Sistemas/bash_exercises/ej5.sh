#!/bin/bash

for archivo in test5/*
do
	if [[ $archivo == *.jpg ]]; then
		sed "/.jpg$/.old" "$archivo"
	fi	
done