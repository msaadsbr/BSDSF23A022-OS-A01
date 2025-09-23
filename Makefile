.PHONY: all lib_static lib_dynamic client_static client_dynamic clean distclean

all: lib_static lib_dynamic client_static client_dynamic

lib_static:
	$(MAKE) -C lib static

lib_dynamic:
	$(MAKE) -C lib dynamic

client_static:
	$(MAKE) -C src client_static

client_dynamic:
	$(MAKE) -C src client_dynamic

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C src clean

distclean: clean
	-rm -rf obj/* bin/*

