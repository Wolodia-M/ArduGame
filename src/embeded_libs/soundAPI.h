#pragma once
#include <Arduino.h>
#include "timersapi.hpp"
#include "music/music.h"

/**
 * @brief Sound driver
 *
 */
class soundAPI
{
public:
    /**
     * @brief Construct a new soundAPI object
     *
     */
    soundAPI()
    {
#ifdef MUS_POINTER_DEBUG
        Serial.begin(115200);
#endif
    }
    /**
     * @brief set track pointer
     *
     * @param _start starting pointer
     * @param _end end pointer
     * @param _file file number
     */
    void moveTrack(int _start, int _end, int _file)
    {
        start = _start;
        pointer = _start;
        stop = _end;
        file = _file;
    }
    /**
     * @brief start playing music
     *
     */
    void startPlay()
    {
        enable = 1;
    }
    /**
     * @brief stop playing music
     *
     */
    void stopPlay()
    {
        enable = 0;
    }
    /**
     * @brief main tick function
     *
     */
    void soundTick()
    {
        static uint32_t prev = 0;
        if (millis() - prev >= 0)
        {
            tn.tick();
            uint8_t f;
            uint8_t s;
            switch (file)
            {
            case 0:
                f = mus[pointer] >> 4;
                s = mus[pointer] & 0x0F;
                break;
            }
            // NOTE_C, NOTE_Cs, NOTE_D, NOTE_Eb, NOTE_E, NOTE_F, NOTE_Fs, NOTE_G, NOTE_Gs, NOTE_A, NOTE_Bb, NOTE_B, NOTE_MAX
            switch (f)
            {
            case 0:
                tn.tone(NOTE_C, s);
                break;
            case 1:
                tn.tone(NOTE_Cs, s);
                break;
            case 2:
                tn.tone(NOTE_D, s);
                break;
            case 3:
                tn.tone(NOTE_Eb, s);
                break;
            case 4:
                tn.tone(NOTE_E, s);
                break;
            case 5:
                tn.tone(NOTE_F, s);
                break;
            case 6:
                tn.tone(NOTE_Fs, s);
                break;
            case 7:
                tn.tone(NOTE_G, s);
                break;
            case 8:
                tn.tone(NOTE_Gs, s);
                break;
            case 9:
                tn.tone(NOTE_A, s);
                break;
            case 10:
                tn.tone(NOTE_Bb, s);
                break;
            case 11:
                tn.tone(NOTE_B, s);
                break;
            case 12:
                tn.tone(NOTE_MAX, s);
                break;
            }
            prev = millis();
            pointer += 1;
            if (pointer > stop)
                pointer = start;
#ifdef MUS_POINTER_DEBUG
            Serial.println(pointer);
#endif
        }
    }

private:
    int start = 0;
    int stop = 0;
    uint8_t enable = 0;
    int pointer = 0;
    int file;
};