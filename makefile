CC=gcc
CFLAGS=-I -Wall
DEPS = application.h hashTable.h linked_list.h
OBJ = main.o application.o hashTable.o linked_list.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) app


