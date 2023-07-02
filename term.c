#include <ncurses.h>
#include <string.h>

void draw_box (int rows, int cols, int bw, int bh, char vert_char, char horiz_char);

/*
 * Draw the box around the login area.
 */
void draw_box (int rows, int cols, int bw, int bh, char vert_char, char horiz_char) {

  int bx, by;

  bx = (cols - bw) / 2;
  by = (rows - bh) / 2;

  // Top and bottom of box
  int cell_idx;
  for (cell_idx = bx; cell_idx <= bx + bw; cell_idx += 1)
  {
    mvaddch(by, cell_idx, horiz_char);
    mvaddch(by + bh, cell_idx, horiz_char);
    cell_idx += 1;
  }

}

int main()
{
  initscr();

  int bw = 50;
  int bh = 20;
  bool run = true;
  int rows, cols;
  char login_header[] = "Login";
  char box_horiz[] = "=";

  getmaxyx(stdscr, rows, cols);

  while (run) { 
    mvaddch(1, 1, 'o');
    draw_box(rows, cols, bw, bh, '|', '=');
    getch();
  }

  endwin();
  
  return 0;
}
