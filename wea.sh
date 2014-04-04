#!/bin/bash  
rm a.out
rm Main.o
rm colors.txt
> colors.txt
make
gcc -Wall Main.o
clear

echo "rojo"
./a.out -i rojo 0 0 0
echo "azul"
./a.out -i azul 0 0 0
echo "rojo"
./a.out -i rojo 0 0 0
echo "verde"
./a.out -i verde 0 0 0





