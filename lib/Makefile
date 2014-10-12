include ../make.inc

OBJS := $(patsubst ../src/%.c,%.o,$(wildcard ../src/*.c))

all: $(OBJS)

%.o: ../src/%.c
	$(CC) -c -o $@ $< $(CFLAGS) -I../include
