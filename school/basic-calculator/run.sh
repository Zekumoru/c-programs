#!/bin/bash
gcc main.c lib/*.c -o output/main -lncurses && output/main
