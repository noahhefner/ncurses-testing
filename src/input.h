#ifndef H_INPUT
#define H_INPUT

#include <stdbool.h>

struct text_field {

  char* text;
  int text_length;
  int x;
  int y;

};

struct text_field_event {

  struct text_field* tf;
  int keystroke;

};

void handle_text_field_event(struct text_field_event* tfe);
bool cursor_on(struct text_field* tf);

#endif
