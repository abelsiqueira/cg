include ../make.inc

TESTS := $(patsubst %.c,%.tst,$(wildcard *.c))

all: $(TESTS)
	for test in $(TESTS); do ./$$test; done

%.tst: %.c
	$(CC) -o $@ $< $(CFLAGS) -I../include ../lib/*.o -lcheck
