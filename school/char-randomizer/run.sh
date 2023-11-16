#!/bin/bash
mkdir -p output && gcc **/*.c *.c -o output/main -lncurses && output/main
