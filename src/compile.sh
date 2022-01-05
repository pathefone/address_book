#!/bin/bash


gcc -Wall -c write_addr.c
gcc -Wall -c main.c
gcc -Wall -c user_input.c
gcc -Wall -c read_addr.c
gcc -Wall -c menu.c
gcc -Wall -c remove_addr.c
gcc -Wall -c find_addr.c
gcc -Wall -c load.c
gcc -o program user_input.o write_addr.o main.o read_addr.o menu.o remove_addr.o find_addr.o load.o
rm write_addr.o main.o user_input.o read_addr.o menu.o remove_addr.o find_addr.o load.o

