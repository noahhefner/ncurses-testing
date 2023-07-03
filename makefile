all: src/term.c src/config.c src/draw.c src/config.h src/draw.h
	gcc src/term.c src/config.c src/draw.c src/config.h src/draw.h -o term -lncurses -Wall
