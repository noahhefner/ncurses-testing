#include "input.h"
#include "state.h"
#include <ncurses.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * Determine if the cursor is positioned on a text field.
 */
bool cursor_on (struct text_field* tf) {

  
  int cursor_y, cursor_x;
  getyx(stdscr, cursor_y, cursor_x);
  
  return cursor_y == tf->y && 
         cursor_x >= tf->x && 
         cursor_x <= tf->x + strlen(tf->text) + 1;

}

void handle_text_field_event (struct text_field_event* tfe) {

  switch (tfe->keystroke) {

    case KEY_BACKSPACE:
    case 127:
    case '\b': 
    {
      if (strlen(tfe->tf.text) == 0) break;

      char* new_text = malloc(strlen(tfe->tf.text) - 1);
      strncpy(new_text, tfe->tf.text, strlen(tfe->tf.text) - 1);
      free(tfe->tf.text);
      tfe->tf.text = new_text;
      break;
    }
    default:
    {
      char* new_text = malloc(strlen(tfe->tf.text) + 1);
      strncpy(new_text, tfe->tf.text, strlen(tfe->tf.text));
      new_text[strlen(tfe->tf.text)] = tfe->keystroke;
      free(tfe->tf.text);
      tfe->tf.text = new_text;
      break;
    }

  }

}
