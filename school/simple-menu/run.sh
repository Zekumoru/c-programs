#!/bin/bash
gcc main.c lib/*.c -o output/main -lm -lncurses && output/main 
