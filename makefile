CC = gcc
CFLAGS = -Wall -ansi
TARGET = ass1
OBJ = chain.o 

stats: $(OBJ)
	$(CC) $(CFLAGS) -o ass1 $(OBJ)
chain.o : chain.c
	$(CC) $(CFLAGS) -c chain.c
clean:
	/bin/rm -f *.o $(TARGET)
