include ../make.inc

OBJS := $(patsubst ../src/%.c,%.o,$(wildcard ../src/*.c))

all: $(OBJS)

%.o: ../src/%.c
	$(CC) -c -o $@ $< $(CFLAGS) -I../include

clean:
	rm -f *.o

purge: clean
