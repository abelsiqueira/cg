all: library

library:
	$(MAKE) -C lib all

tests:
	$(MAKE) -C unittest all

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C unittest clean

purge:
	$(MAKE) -C lib purge
	$(MAKE) -C unittest purge
