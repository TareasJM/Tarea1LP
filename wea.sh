#!/bin/bash  
make clean
make
gcc -Wall Main.o -lncurses

# ./a.out -i rojo 1000 0 0
# ./a.out -i azul 0 0 1000
# ./a.out -i verde 0 1000 0
# ./a.out -i blanco 1000 1000 1000

./a.out -list
