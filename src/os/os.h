#pragma once

#include "Arduino.h"

typedef struct{
    String progName;
    void (*mainTick)();
    uint8_t* musPointer;
} prog_stng_t;

class OS
{
    public:
        void tick();
        void init_prog(prog_stng_t* prog);
    private:
        void load_prog(prog_stng_t prog);
};