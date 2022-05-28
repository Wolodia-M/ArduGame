#pragma once

#include "Arduino.h"

class ARDUGAMEOS
{
public:
    void init();
    void tick();
    void init_prog();
    void go_menu();
    void go_app_exit();
private:
    void load_prog();
    void tick_buttons();
};

void ARDUGAMEOS::init()
{

}
void ARDUGAMEOS::tick()
{
    ARDUGAMEOS::tick_buttons();
    sapi.soundTick();
}
void ARDUGAMEOS::go_menu()
{
    #ifdef BUTTONS_DEBUG
    Serial.println("menu");
    #endif
}
void ARDUGAMEOS::go_app_exit()
{
    #ifdef BUTTONS_DEBUG
    Serial.println("exit");
    #endif
}
void ARDUGAMEOS::tick_buttons()
{
    start_b.tick();
    select_b.tick();
    if (select_b.isClick())
    {
        ARDUGAMEOS::go_menu();
    }
    if (start_b.isClick())
    {
        ARDUGAMEOS::go_app_exit();
    }
}