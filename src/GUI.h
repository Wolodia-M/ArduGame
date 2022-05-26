// logo
#include "img/logo.h"

// Starting animation
void start()
{
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true);
  for (int i = 240; i--; i >= 0)
  {
    tft.pushImage(i, 0, logo_w, logo_h, logo);
    delay(10);
    if (i < 80)
    {
      tn.tone(i * i + 2000);
    }
    else if (i < 180)
    {
      tn.tone(i * (i / 5) + 2000);
    }
    else
    {
      tn.tone(i * (i / 7) + 2000);
    }
  }
  tft.setSwapBytes(false);
  delay(400);
  tft.setCursor(160, 120, 2);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.setTextSize(1);
  tft.println("by WolodiaM");
}
