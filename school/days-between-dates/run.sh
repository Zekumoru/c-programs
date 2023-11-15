#!/bin/bash
mkdir -p output && gcc **/*.c *.c -o output/main -lncurses -lm && output/main
