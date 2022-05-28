// Maybe that file (included next) is main?
#include "arduGame.h"
// setup and loop
void setup()
{
#ifdef DEBUG
  Serial.begin(115200);
#endif
  uint8_t* musP = &mus[0];
  start();
  tn.noTone();
  sapi.moveTrack(0, 32, musP);
}

void loop()
{
  sapi.soundTick();
}
