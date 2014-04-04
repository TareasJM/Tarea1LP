#!/bin/bash  
gcc -Wall Main.o

echo "i rojo"
./a.out -i rojo 0 0 0
echo "i azul"
./a.out -i azul 0 0 0
echo "i rojo"
./a.out -i rojo 0 0 0
echo "i verde"
./a.out -i verde 0 0 0
echo "d azul"
./a.out -d azul
echo "d verde"
./a.out -d verde
echo "d verde"
./a.out -d verde
echo "d rojo"
./a.out -d rojo
echo "i amarillo"
./a.out -i amarillo 1 2 3
