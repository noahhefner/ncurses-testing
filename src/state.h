#ifndef H_STATE
#define H_STATE

#include <stdbool.h>

void init_state(int rows, int columns);

struct state {
  int rows;
  int columns;
  int cursor_pos_x;
  int cursor_pos_y;
  bool add_char;
}; 

extern struct state state;

#endif
