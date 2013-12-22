
AR ?= ar
CC ?= gcc
PREFIX ?= /usr/local

CFLAGS = -O3 -std=c99 -Wall

SRCS = src/cstack.c

OBJS = $(SRCS:.c=.o)

all: build/libcstack.a

install: all
	cp -f build/libcstack.a $(PREFIX)/lib/libcstack.a
	cp -f src/cstack.h $(PREFIX)/include/cstack.h

uninstall:
	rm -f $(PREFIX)/lib/libcstack.a
	rm -f $(PREFIX)/include/cstack.h

build/libcstack.a: $(OBJS)
	@mkdir -p build
	$(AR) rcs $@ $^

bin/test: test.o $(OBJS)
	@mkdir -p bin
	$(CC) $^ -o $@

bin/benchmark: benchmark.o $(OBJS)
	@mkdir -p bin
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	rm -fr bin build *.o src/*.o

test: bin/test
	@./$<

benchmark: bin/benchmark
	@./$<

.PHONY: test benchmark clean install uninstall

