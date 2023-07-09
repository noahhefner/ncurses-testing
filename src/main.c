#include <ncurses.h>

#include "login_box.h"

int main () {

  init_login_box(5, 5, 20, 8);
  
 
  initscr();
  noecho();
  keypad(stdscr, TRUE);

  bool run = true;
  int input;//, rows, cols;

  //getmaxyx(stdscr, rows, cols);

  while (run) {

    draw_login_box();

    refresh();

    input = getch();

    if (input == 'q') {

      run = false;

    }

  }

  endwin();

  return 0;

}
