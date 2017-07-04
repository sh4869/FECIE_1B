CC=gcc
CFLAGS=-g -lncurses
DEPS=redraw.h redraw2.h
OBJ=redraw.o
11_OBJ=redraw2.o ncurses-game2.o
10_OBJ=redraw.o ncurse-test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

redraw: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

10: $(10_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

11: $(11_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
