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
  load_config();

  while (run) {
    getmaxyx(stdscr, rows, cols);

    draw_login();

    draw_rectangle(0, 0, cols - 1, 2);

    input = getch();

    if (input == 'q')
    {
      run = false;
    }

  }

  endwin();
  
  return 0;
}
