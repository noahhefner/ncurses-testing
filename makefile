all: src/main.c src/login_box.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h src/login_box.h
	gcc -g src/main.c src/login_box.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h src/login_box.h -o tui-dm -lncurses -Wall
