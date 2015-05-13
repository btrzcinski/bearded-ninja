PKGS=libsoup-2.4 gobject-2.0 glib-2.0 gio-2.0
CFLAGS=-O2 -g -std=c99 `pkg-config --cflags $(PKGS)`
LDFLAGS=`pkg-config --libs $(PKGS)`
CC=gcc

all: bin bin/webradio

bin:
	mkdir -p bin

bin/%.o: src/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

bin/webradio: bin/webradio.o
	$(CC) $< $(LDFLAGS) -o $@

clean:
	rm -rf bin logs 


