#include <ncurses.h>
#include <form.h>

#include "login_box.h"

int main () {

  initscr();
  noecho();
  keypad(stdscr, TRUE);

  bool run = true;
  int input;//, rows, cols;

  //getmaxyx(stdscr, rows, cols);

  init_login_box(20, 20, 40, 40);

  draw_login_box();

  refresh();

  while (run) {

    input = getch();

    if (input == 'q') {

      run = false;

    }

  }

  endwin();

  return 0;

}
