#include "draw.h"
#include "login_box.h"

#include <errno.h>
#include <stdlib.h>
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
  FIELD* fields[2];

  // Calculate coordinates for fields
  int field_creds_x, field_user_y, field_pass_y;
  field_creds_x = lb.x + (lb.width / 2) + 8;
  field_user_y = y_login + 2;
  field_pass_y = y_login + 4;

  // Username field
  fields[0] = new_field(1, 20, field_user_y, field_creds_x, 0, 0);
  // Password field
  fields[1] = new_field(1, 20, field_pass_y, field_creds_x, 0, 0);

  // Set field options
  set_field_back(fields[0], A_UNDERLINE);
  field_opts_off(fields[0], O_AUTOSKIP);
  set_field_back(fields[1], A_UNDERLINE);
  field_opts_off(fields[1], O_AUTOSKIP);

  // Set form in login box struct
  lb.form = new_form(fields);

}

void draw_login_box () {

  // Draw rectangle around perimeter of login box
  draw_rectangle(lb.y, lb.x, lb.width, lb.height);

  // Calculate coordinates for labels
  int y_login, y_user, y_pass, x_login, x_creds;
  y_login = lb.y + (lb.height / 2) - 3;
  y_user = y_login + 2;
  y_pass = y_login + 4;
  x_login = lb.x + (lb.width / 2) - (strlen(txt_login) / 2);
  x_creds = lb.x + (lb.width / 2) - 8;

  // Add labels
  mvaddstr(y_login, x_login, txt_login);
  mvaddstr(y_user, x_creds, txt_user);
  mvaddstr(y_pass, x_creds, txt_pass);

  post_form(lb.form);

}
