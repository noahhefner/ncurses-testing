#ifndef H_CONFIG
#define H_CONFIG

#include <stdint.h>

void load_config();
void parse_config_file(const char* config_path);

struct config
{
  uint8_t login_x;
  uint8_t login_y;
  uint8_t login_width;
  uint8_t login_height;
};

extern struct config config;

#endif
