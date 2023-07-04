all: src/term.c src/config.c src/draw.c src/config.h src/draw.h
	gcc src/term.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h -o term -lncurses -Wall
