#include <ncurses.h>
#include <string.h>

#include "state.h"
#include "draw.h"
#include "input.h"
#include "config.h"

struct config config;
struct state state;

// Term
int main()
{
  initscr();
  noecho();

  bool run = true;
  int rows, cols, input, input_x, input_y;

  getmaxyx(stdscr, rows, cols);
  init_state(rows, cols);
  init_config();
  parse_config_file("config");
  validate_config();

  draw_login();

  if (config.draw_options == 1) draw_options();

  input_x = config.login_x + (config.login_width / 2) + 4;
  input_y = config.login_y + (config.login_height / 2) - 1;

  // Position cursor at user field
  move(input_y, input_x);

  bool add_char = true;

  while (run) {

    refresh();

    add_char = true;

    input = getch();

    //char *check = unctrl(input);
    //int safe = (check != 0 && strlen(check) == 1);

    switch (input)
    {
    case KEY_BACKSPACE:
    case 127:
    case '\b':
      add_char = false;
      handle_backspace();
    }

    if (input == 'q')
    {
      run = false;
    }

    if (add_char)
    {
      addch(input);
    }

  }

  endwin();
  
  return 0;
}
