#ifndef H_CONFIG
#define H_CONFIG

#include <stdint.h>

void init_config(int rows, int columns);
void parse_config_file(const char* config_path);

struct config
{
  uint8_t columns;
  uint8_t rows;

  uint8_t login_x;
  uint8_t login_y;
  uint8_t login_width;
  uint8_t login_height;
  uint8_t login_center_x;
  uint8_t login_center_y;

  uint8_t draw_options;
};

extern struct config config;

#endif
