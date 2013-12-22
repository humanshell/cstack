
AR ?= ar
CC ?= gcc
PREFIX ?= /usr/local

CFLAGS = -O3 -std=c99 -Wall

SRCS = src/stack.c

OBJS = $(SRCS:.c=.o)

all: build/libstack.a

install: all
	cp -f build/libstack.a $(PREFIX)/lib/libstack.a
	cp -f src/stack.h $(PREFIX)/include/stack.h

uninstall:
	rm -f $(PREFIX)/lib/libstack.a
	rm -f $(PREFIX)/include/stack.h

build/libstack.a: $(OBJS)
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

