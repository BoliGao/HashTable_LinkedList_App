CC=gcc
CFLAGS=-I -Wall
DEPS = application.h hashTable.h
OBJ = application.o hashTable.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) app


