#ifndef H_STATE
#define H_STATE

#include <stdbool.h>

#include "input.h"

void init_state(int rows, int columns);

struct state {

  int rows;
  int columns;
  int cursor_x;
  int cursor_y;

};

extern struct state state;

#endif
