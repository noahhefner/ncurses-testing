#include "input.h"
#include "config.h"
#include "draw.h"
#include "string.h"
#include <ncurses.h>

void draw_login_box (struct text_field* username, struct text_field* password) {

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
