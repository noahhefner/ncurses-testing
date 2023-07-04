#include <ncurses.h>
#include <string.h>

#include "draw.h"
#include "config.h"
#include "state.h"

void draw_options()
{
  draw_rectangle(0, 0, state.columns - 1, 2);

  char txt_shutdown[] = "F1 - Shutdown";
  char txt_reboot[] = "F2 - Reboot";

  mvaddstr(1, 3, txt_shutdown);
  mvaddstr(1, 20, txt_reboot);

}

/*
 * Draw the login prompt.
 */
void draw_login()
{
  char txt_login[]   = "Login";
  char txt_user[]    = "User : ";
  char txt_pass[]    = "Password : ";
  char txt_session[] = "Session : ";

  // Draw rectangle around the login text
  draw_rectangle(config.login_y, config.login_x, config.login_width, config.login_height);

  int y_login, y_user, y_pass, y_session, x_login, x_creds_session;

  // Calculate coordinates for login text
  y_login = config.login_y + (config.login_height / 2) - 3;
  y_user = y_login + 2;
  y_pass = y_login + 4;
  y_session = y_login + 6;
  x_login = config.login_x + (config.login_width / 2) - (strlen(txt_login) / 2);
  x_creds_session = config.login_x + (config.login_width / 2) - 8;

  mvaddstr(y_login, x_login, txt_login);
  mvaddstr(y_user, x_creds_session, txt_user);
  mvaddstr(y_pass, x_creds_session, txt_pass);
  mvaddstr(y_session, x_creds_session, txt_session);
}

/*
 * Draw a rectangle.
 */
void draw_rectangle (int by, int bx, int bw, int bh)
{

  mvhline(by,      bx,      0, bw);  // top
  mvhline(by + bh, bx,      0, bw);  // bottom
  mvvline(by,      bx,      0, bh);  // left
  mvvline(by,      bx + bw, 0, bh);  // right
  
  mvaddch(by,      bx,      ACS_ULCORNER);  // top left corner
  mvaddch(by + bh, bx,      ACS_LLCORNER);  // bottom left corner
  mvaddch(by,      bx + bw, ACS_URCORNER);  // top right corner
  mvaddch(by + bh, bx + bw, ACS_LRCORNER);  // bottom right corner

}
