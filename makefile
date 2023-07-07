all: src/main.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h
	gcc -g src/main.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h -o tui-dm -lncurses -Wall
