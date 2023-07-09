#ifndef H_LOGIN_BOX
#define H_LOGIN_BOX

#include <form.h>
#include "util.h"

struct login_box {

  // Box dimensions and location
  int x;
  int y;
  int width;
  int height;

  // Form for username and password
  FORM* form;
  FIELD* field[2];

  // Coordinates for labels and form fields
  struct xy* coords_label_login;
  struct xy* coords_label_username;
  struct xy* coords_label_password;
  struct xy* coords_field_username;
  struct xy* coords_field_password;

};

void init_login_box (int x, int y, int width, int height);
void draw_login_box ();
void free_login_box ();

extern struct login_box lb;

#endif
