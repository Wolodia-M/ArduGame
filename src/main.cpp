// Maybe that file (included next) is main?
#include "arduGame.h"
// setup and loop
void setup()
{
#ifdef DEBUG
  Serial.begin(115200);
#endif
  tft.init();
  tft.setRotation(1);
  start();
  tn.noTone();
  sapi.moveTrack(0, 29);
}

void loop()
{
  sapi.soundTick();
}
