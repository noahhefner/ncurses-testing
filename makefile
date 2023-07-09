all: src/main.c src/login_box.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h src/login_box.h
	gcc -g src/main.c src/login_box.c src/config.c src/draw.c src/state.c src/input.c src/config.h src/draw.h src/state.h src/input.h src/login_box.h -o tui-dm -lncurses -lform -Wall

form: src/main.c src/login_box.c src/draw.c src/draw.h src/login_box.h src/util.h
	gcc -g -O0 src/main.c src/login_box.c src/draw.c src/util.h src/draw.h src/login_box.h -o tui-dm -lncurses -lform -Wall


