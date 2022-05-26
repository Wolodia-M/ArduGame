// mini logo
#include "img/logo_mini.h"

// function for printing mini logo
void mini_logo_print(int x = 0, int y = 0)
{ // print mini logo. Default - left up corner.
  tft.setSwapBytes(true);
  tft.pushImage(x, y, logo_mini_w, logo_mini_h, logo_mini);
  tft.setSwapBytes(false);
}