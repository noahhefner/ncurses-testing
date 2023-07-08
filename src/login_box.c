#include "draw.h"
#include "login_box.h"

#include <string.h>
#include <ncurses.h>
#include <form.h>

// Labels
char txt_login[]   = "Login";
char txt_user[]    = "User : ";
char txt_pass[]    = "Password : ";
char txt_session[] = "Session : ";

struct login_box lb;

/*
 * Setup the login box struct.
 */
void init_login_box (int x, int y, int width, int height) {

  // Set login box dimensions and location
  lb.x = x;
  lb.y = y;
  lb.width = width;
  lb.height = height;

  // Calculate coordinates for labels
  int y_login, y_user, y_pass, x_login, x_creds;
  y_login = lb.y + (lb.height / 2) - 3;
  y_user  = y_login + 2;
  y_pass  = y_login + 4;
  x_login = lb.x + (lb.width / 2) - (strlen(txt_login) / 2);
  x_creds = lb.x + (lb.width / 2) - 8;

  struct xy coords_label_login = { x_login, y_login };
  struct xy coords_label_user  = { x_creds, y_user };
  struct xy coords_label_pass  = { x_creds, y_pass };

  // Set coordinates for labels
  lb.coords_label_login    = &coords_label_login;
  lb.coords_label_username = &coords_label_user;
  lb.coords_label_password = &coords_label_pass;

  // Field
  FIELD* field[3];

  // Calculate coordinates for fields
  int field_creds_x, field_user_y, field_pass_y;
  field_creds_x = lb.x + (lb.width / 2) + 8;
  field_user_y = y_login + 2;
  field_pass_y = y_login + 4;

  // Username field
  field[0] = new_field(1, 20, field_user_y, field_creds_x, 0, 0);
  // Password field
  field[1] = new_field(1, 20, field_pass_y, field_creds_x, 0, 0);

  field[3] = NULL;

  // Set field options
  set_field_back(field[0], A_UNDERLINE);
  field_opts_off(field[0], O_AUTOSKIP);
  set_field_back(field[1], A_UNDERLINE);
  field_opts_off(field[1], O_AUTOSKIP);

  // Set form in login box struct
  FORM* form = new_form(field);
  lb.form = form;

}

void draw_login_box () {

  // Draw rectangle around perimeter of login box
  draw_rectangle(lb.y, lb.x, lb.width, lb.height);

  // Calculate coordinates for labels
  int y_login, y_user, y_pass, y_session, x_login, x_creds_session;
  y_login = lb.y + (lb.height / 2) - 3;
  y_user = y_login + 2;
  y_pass = y_login + 4;
  y_session = y_login + 6;
  x_login = lb.x + (lb.width / 2) - (strlen(txt_login) / 2);
  x_creds_session = lb.x + (lb.width / 2) - 8;

  // Add labels
  mvaddstr(y_login, x_login, txt_login);
  mvaddstr(y_user, x_creds_session, txt_user);
  mvaddstr(y_pass, x_creds_session, txt_pass);
  mvaddstr(y_session, x_creds_session, txt_session);

  post_form(lb.form);

}
