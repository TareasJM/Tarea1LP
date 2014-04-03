# Source, Executable, Includes, Library Defines
INCL   = Lista.h Color.h
SRC    = Main.c Lista.c Color.c
OBJ    = $(SRC:.c=.o)

# Compiler, Linker Defines
CC      = /usr/bin/gcc
CFLAGS  = -Wall
LDFLAGS = -o
CFDEBUG = -Wall -DDEBUG $(LDFLAGS)
RM      = /bin/rm -f

# Compile and Assemble C Source Files into Object Files
%.o: %.c
		$(CC) -c $(CFLAGS) $*.c

# Objects depend on these Libraries
$(OBJ): $(INCL)

# Create a gdb/dbx Capable Executable with DEBUG flags turned on
debug:
		$(CC) $(CFDEBUG) $(SRC)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
		$(RM) $(OBJ) core a.out