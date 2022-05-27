// Maybe that file (included next) is main?
#include "arduGame.h"
// setup and loop
void setup()
{
#ifdef DEBUG
  Serial.begin(115200);
#endif
  start();
  tn.noTone();
  sapi.moveTrack(0, 32, 0);
}

void loop()
{
  sapi.soundTick();
}
