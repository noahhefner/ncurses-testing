#include <stdint.h>

void load_config();

struct config
{
  uint8_t login_x;
  uint8_t login_y;
  uint8_t login_width;
  uint8_t login_height;
};

extern struct config config;
