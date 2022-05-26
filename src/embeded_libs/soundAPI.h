#pragma once
#include <Arduino.h>
#include "music.h"

class soundAPI
{
public:
    soundAPI()
    {
        Serial.begin(115200);
    }
    void moveTrack(int _start, int _end)
    {
        start  = _start;
        pointer = _start;
        stop = _end;
    }
    void startPlay()
    {
        enable = 1;
    }
    void stopPlay()
    {
        enable = 0;
    }
    void soundTick()
    {
        static uint32_t prev = 0;
        {
            if(millis() - prev >= 0)
            {
                //ledcWriteTone(chan, freq)
                prev = millis();
                pointer += 1;
                Serial.println(pointer);
            }
        }
    }

private:
    int start = 0;
    int stop = 0;
    uint8_t enable = 0;
    int pointer = 0;
};