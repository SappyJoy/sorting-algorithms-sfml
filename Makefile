#CFLAGS=--std=c++17 -Wall -pedantic -Isrc/ -ggdb -Wextra -Werror -DDEBUG
CFLAGS=--std=c++17
BUILDDIR=build
SRCDIR=src
CC=g++

all: $(BUILDDIR)/main.o $(BUILDDIR)/application.o $(BUILDDIR)/algorithms.o
	$(CC) $^ -o $(BUILDDIR)/main -lsfml-graphics -lsfml-window -lsfml-system

build:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/application.o: $(SRCDIR)/application.cpp build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/algorithms.o: $(SRCDIR)/algorithms.cpp build
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)/*.o

