#!/bin/bash

for archivo in test5/*.jpg; 
do
    mv "$archivo" "${archivo%.jpg}.old"
done
