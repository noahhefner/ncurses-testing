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
  tf_username.text = malloc(max_username_length);
  memset(tf_username.text, 0, max_username_length);
  tf_username.x = 0;
  tf_username.y = 10;

  // Initialize password text field
  tf_password.text = malloc(max_password_length);
  memset(tf_password.text, 0, max_password_length);
  tf_password.x = 0;
  tf_password.y = 11;

  //draw_login();

  //if (config.draw_options == 1) draw_options();

  //input_x = config.login_x + (config.login_width / 2) + 4;
  //input_y = config.login_y + (config.login_height / 2) - 1;

  // Position cursor at user field
  //move(10, 0);

  //bool add_char = true;

  while (run) {

    refresh();

    draw_text_field(&tf_username);
    draw_text_field(&tf_password);

    move(10,0);

    input = getch();

    // This may be useful somewhere
    //char *check = unctrl(input);
    //int safe = (check != 0 && strlen(check) == 1);

    // Process keystroke based on where the cursor is
    if (cursor_on(&tf_username)) {
      fprintf(stderr, "on username");

      struct text_field_event tfe;
      tfe.tf = tf_username;
      tfe.keystroke = input;
      handle_text_field_event(tfe);

    } else if (cursor_on(&tf_password)) {
      printf("On password");
      struct text_field_event tfe;
      tfe.tf = tf_password;
      tfe.keystroke = input;
      handle_text_field_event(tfe);

    } else {
      printf("not on text field");
      continue;
    
    }

    if (input == 'q') {
      run = false;
    }

  }

  endwin();
  
  return 0;
}
