#define _OPEN_SYS_ITOA_EXT

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "config.h"

void init_config(int rows, int columns)
{
  config.rows = rows;
  config.columns = columns;
}

void load_config()
{
  config.login_x = 20;
  config.login_y = 20;
  config.login_width = 80;
  config.login_height = 10;
}

/*
 * Parse config file and read in values.
 */
void parse_config_file(const char* config_path)
{
  FILE* config_file;
  char line[256];
  int line_number = 0;
  
  char key[256];
  char value[256];

  config_file = fopen(config_path, "r");

  if (config_file == NULL)
  {
    fprintf(stderr, "Error loading config file from %s\n", config_path);
    return;
  }

  while (fgets(line, 256, config_file) != NULL)
  {
    line_number += 1;

    // Skip comment lines
    if (line[0] == '#') continue;
    
    // Skip blank lines
    if (isspace(*line)) continue;

    // Check for syntax error
    if (sscanf(line, "%s %s", key, value) != 2)
    {
      fprintf(stderr, "Syntax error in config file, line %d\n", line_number);
      continue;
    }

    if (strcmp("login_x", key) == 0)
    {
      config.login_x = (int) strtol(value, (char**)NULL, 10);
      continue;
    }
    if (strcmp("login_y", key) == 0)
    {
      config.login_y = (int) strtol(value, (char**)NULL, 10);
      continue;
    }
    if (strcmp("login_width", key) == 0)
    {
      config.login_width = (int) strtol(value, (char**)NULL, 10);
      continue;
    }
    if (strcmp("login_height", key) == 0)
    {
      config.login_height = (int) strtol(value, (char**)NULL, 10);
      continue;
    }
    if (strcmp("options_box", key) == 0)
    {
      config.draw_options = (int) strtol(value, (char**)NULL, 10);
      continue;
    }

  }
}
