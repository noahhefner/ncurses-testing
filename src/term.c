#include <ncurses.h>
#include <string.h>

#include "draw.h"
#include "config.h"

struct config config;

// Term
int main()
{
  initscr();

  bool run = true;
  int rows, cols, input;

  getmaxyx(stdscr, rows, cols);
  init_config(rows, cols);
  parse_config_file("config");
  validate_config();

  while (run) {
    
    draw_login();

    if (config.draw_options == 1) draw_options();

    input = getch();

    if (input == 'q')
    {
      run = false;
    }

  }

  endwin();
  
  return 0;
}
