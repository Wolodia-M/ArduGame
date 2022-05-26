// typedef enum {
//     NOTE_C, NOTE_Cs, NOTE_D, NOTE_Eb, NOTE_E, NOTE_F, NOTE_Fs,
//     NOTE_G, NOTE_Gs, NOTE_A, NOTE_Bb, NOTE_B, NOTE_MAX
// } note_t;
// double ledcWriteTone(uint8_t chan, double freq)
// double ledcWriteNote(uint8_t chan, note_t note, uint8_t octave)

// play = 0 - off
// play = 1 - play freq, no dur
// play = 2 - play note, no dur
// play = 3 - play freq, dur
// play = 4 - play note, dur

#pragma once
#include <Arduino.h>

class toneAPI
{
public:
  toneAPI(uint8_t pin = -1, uint8_t channel = -1)
  {
    _pin = pin;
    _chan = channel;
    _play = 0;
    _dur = 0;
    ledcAttachPin(_pin, _chan);
  }
  void attach(uint8_t pin = -1, uint8_t channel = -1){
    _pin = pin;
    _chan = channel;
    ledcAttachPin(_pin, _chan);
  }
  void tone(double freq)
  {
    ledcWriteTone(_chan, freq);
    _play = 1;
  }
  void tone(note_t note, uint8_t octave)
  {
    ledcWriteNote(_chan, note, octave);
    _play = 2;
  }
  void tone(double freq, unsigned long dur)
  {
    ledcWriteTone(_chan, freq);
    _play = 3;
    _dur = dur;
    _cur = millis();
  }
  void tone(note_t note, uint8_t octave, unsigned long dur)
  {
    ledcWriteNote(_chan, note, octave);
    _play = 4;
    _dur = dur;
    _cur = millis();
  }
  void tick()
  {
    if (_play > 2 && millis() - _cur > _dur)
    {
      toneAPI::noTone();
    }
  }
  void noTone()
  {
    ledcWriteTone(_chan, 0);
    _play = 0;
  }

private:
  uint8_t _pin, _chan, _play;
  unsigned long _dur, _cur;
};
