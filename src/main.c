#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#include "state.h"
#include "draw.h"
#include "input.h"
#include "config.h"

struct config config;
struct state state;

// Term
int main()
{
  initscr();
  noecho();
  keypad(stdscr, TRUE);

  bool run = true;
  int input;

  int max_username_length = 20;
  int max_password_length = 20;

  //getmaxyx(stdscr, rows, cols);
  //init_state(rows, cols);

  // Configuration settings
  //init_config();
  //parse_config_file("config");
  //validate_config();

  struct text_field tf_username;
  struct text_field tf_password;

  // Initialize username text field
  tf_username.text = (char*) calloc(max_username_length, sizeof(char));
  tf_username.x = 0;
  tf_username.y = 10;
  tf_username.text_length = 0;

  // Initialize password text field
  tf_password.text = calloc(max_password_length, sizeof(char));
  tf_password.x = 0;
  tf_password.y = 11;
  tf_password.text_length = 0;
  
  int cursor_y, cursor_x;

  // Position cursor at user field
  move(10, 0);

  while (run) {

    refresh();

    bool update_text_field = false;

    getyx(stdscr, cursor_y, cursor_x);

    input = getch();

    switch (input) {

      case KEY_LEFT:
      {
        move(cursor_y, cursor_x - 1);
        break;
      }
      case KEY_RIGHT:
      {
        move(cursor_y, cursor_x + 1);
        break;
      }
      default:
      {
        update_text_field = true;
        break;
      }
    }

    if (update_text_field) {

      // Process keystroke based on where the cursor is
      if (cursor_on(&tf_username)) {

        struct text_field_event tfe;
        tfe.tf = &tf_username;
        tfe.keystroke = input;
        handle_text_field_event(&tfe);

        draw_text_field(&tf_username);

      } else if (cursor_on(&tf_password)) {

        struct text_field_event tfe;
        tfe.tf = &tf_password;
        tfe.keystroke = input;
        handle_text_field_event(&tfe);

        draw_text_field(&tf_password);

      } else {

        continue;

      }

    }

    if (input == 'q') {

      run = false;

    }

  }

  endwin();

  return 0;
}
