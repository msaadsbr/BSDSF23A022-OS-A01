.PHONY: all lib client_static clean distclean

all: lib client_static

lib:
	$(MAKE) -C lib

client_static:
	$(MAKE) -C src client_static

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C src clean

distclean: clean
	-rm -rf obj/*
	-rm -rf bin/*
