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

  // Calculate coordinates for fields
  int field_creds_x, field_user_y, field_pass_y;
  field_creds_x = lb.x + (lb.width / 2) + 8;
  field_user_y = y_login + 2;
  field_pass_y = y_login + 4;

  // Username field
  lb.field[0] = new_field(1, 20, field_user_y, field_creds_x, 0, 0);
  // Password field
  lb.field[1] = new_field(1, 20, field_pass_y, field_creds_x, 0, 0);

  // Set field options
  set_field_back(lb.field[0], A_UNDERLINE);
  field_opts_off(lb.field[0], O_AUTOSKIP);
  set_field_back(lb.field[1], A_UNDERLINE);
  field_opts_off(lb.field[1], O_AUTOSKIP);

  // Set form in login box struct
  lb.form = new_form(lb.field);

}

void draw_login_box () {

  // Draw rectangle around perimeter of login box
  draw_rectangle(lb.y, lb.x, lb.width, lb.height);

  // Add labels
  mvaddstr(lb.coords_label_login->y, lb.coords_label_login->x, txt_login);
  mvaddstr(lb.coords_label_username->y, lb.coords_label_username->x, txt_user);
  mvaddstr(lb.coords_label_password->y, lb.coords_label_password->x, txt_pass);

  post_form(lb.form);

}

void free_login_box () {

  unpost_form(lb.form);
  free_form(lb.form);
  free_field(lb.field[0]);
  free_field(lb.field[1]);

}
