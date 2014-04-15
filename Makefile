INCL   = Lista.h Color.h Dibujador.h
SRC    = Main.c Lista.c Color.c Dibujador.c
OBJ    = $(SRC:.c=.o)

CC      = gcc
CFLAGS  = -Wall
RM      = rm -f

%.o: %.c
		$(CC) $(CFLAGS) $*.c -lncurses

$(OBJ): $(INCL)

clean:
		$(RM) $(OBJ) a.out