CC = gcc
CFLAGS = -g -wall
all : Color Lista
Color : Color.o Main.o
		$(CC) -o $@ $^
Lista : Lista.o Main.o
		$(CC) -o $@ $^

#chupaloooooooooooo
