#include "input.h"
#include <ncurses.h>

void handle_backspace()
{
  int input_y, input_x;
  getyx(stdscr, input_y, input_x);
  move(input_y, input_x - 1);
  addch(' ');
  move(input_y, input_x - 1);

}
