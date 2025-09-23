PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man

.PHONY: all install uninstall clean

# This assumes you already have rules for client_dynamic
all: client_dynamic

client_dynamic:
	$(MAKE) -C src client_dynamic

install: all
	install -d $(BINDIR)
	install -m 755 bin/client_dynamic $(BINDIR)/client
	install -d $(MANDIR)/man1
	install -m 644 man/man1/client.1 $(MANDIR)/man1/client.1

uninstall:
	rm -f $(BINDIR)/client
	rm -f $(MANDIR)/man1/client.1

clean:
	$(MAKE) -C src clean
	-rm -f bin/client_dynamic
