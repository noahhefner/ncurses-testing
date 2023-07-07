all: src/tui-dm.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h
	gcc src/tui-dm.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h -o tui-dm -lncurses -Wall
