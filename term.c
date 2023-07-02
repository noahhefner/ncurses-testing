#include <ncurses.h>
#include <string.h>

void draw_box (int rows, int cols, int bw, int bh);
void draw_prompt (int rows, int cols);

/*
 * Draw the box around the login area.
 */
void draw_box (int rows, int cols, int bw, int bh)
{

  int x1, y1, x2, y2;

  x1 = (cols - bw) / 2;
  y1 = (rows - bh) / 2;
  x2 = x1 + bw;
  y2 = y1 + bh;

  mvhline(y1, x1, 0, x2-x1);
  mvhline(y2, x1, 0, x2-x1);
  mvvline(y1, x1, 0, y2-y1);
  mvvline(y1, x2, 0, y2-y1);
  mvaddch(y1, x1, ACS_ULCORNER);
  mvaddch(y2, x1, ACS_LLCORNER);
  mvaddch(y1, x2, ACS_URCORNER);
  mvaddch(y2, x2, ACS_LRCORNER);

}

/*
 * Draw the login text.
 */
void draw_prompt (int rows, int cols)
{

  char txt_login[] = "Login";
  char txt_user[] = "User";
  char txt_pass[] = "Password";
  char txt_session[] = "Session";
 
  int y_login, y_user, y_pass, y_session;
  
  y_login = (rows / 2) - 3;
  y_user = y_login + 2;
  y_pass = y_login + 4;
  y_session = y_login + 6;

  int x_login, x_creds_session;

  x_login = (cols - strlen(txt_login)) / 2;
  x_creds_session = (cols - 30) / 2;

  mvaddstr(y_login, x_login, txt_login);
  mvaddstr(y_user, x_creds_session, txt_user);
  mvaddstr(y_pass, x_creds_session, txt_pass);
  mvaddstr(y_session, x_creds_session, txt_session);

}

// Term
int main()
{
  initscr();

  int bw = 50;
  int bh = 10;
  bool run = true;
  int rows, cols;
  char login_header[] = "Login";

  getmaxyx(stdscr, rows, cols);

  while (run) { 
    draw_box(rows, cols, bw, bh);
    draw_prompt(rows, cols);
    getch();
  }

  endwin();
  
  return 0;
}
