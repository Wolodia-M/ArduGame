#pragma once

#include "Arduino.h"

class ARDUGAMEOS
{
public:
    void init();
    void tick();
    void init_prog(prog_init_t app);
    void go_menu();
    void main_menu();
    void go_app_exit();
    class err
    {
        void error_app_doesnt_exist();
    };
    err error;
private:
    void load_prog(int progNumber);
    void tick_buttons();
    bool isApp[APP_COUNT];
    prog_init_t* apps[APP_COUNT];
    int pos = 1;
    bool menuUpdate = 1;
};

/**
 * @brief Init os
 * 
 */
void ARDUGAMEOS::init()
{

}
/**
 * @brief os main tick
 * 
 */
void ARDUGAMEOS::tick()
{
    ARDUGAMEOS::tick_buttons();
    sapi.soundTick(); // !work
    switch(pos)
    {
        case 0:
            
            ARDUGAMEOS::main_menu();
            break;
    }
}
/**
 * @brief go to app menu on select
 * 
 */
void ARDUGAMEOS::go_menu()
{
    #ifdef BUTTONS_DEBUG
    Serial.println("menu");
    #endif
}
/**
 * @brief exit app on start
 * 
 */
void ARDUGAMEOS::go_app_exit()
{
    #ifdef BUTTONS_DEBUG
    Serial.println("exit");
    #endif
}
/**
 * @brief os button tick
 * 
 */
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
/**
 * @brief draw main menu
 * 
 */
void ARDUGAMEOS::main_menu()
{
    if(menuUpdate)
    {
        tft.fillScreen(TFT_BLACK);
        mini_logo_print();
        menuUpdate = 0;
    }
}
/**
 * @brief init program in os
 * 
 * @param app app structure
 */
void ARDUGAMEOS::init_prog(prog_init_t app)
{
    isApp[app.progID] = true;
}
/**
 * @brief go to error if app does not exist 
 * 
 */
void ARDUGAMEOS::err::error_app_doesnt_exist()
{
    #ifdef DEBUG
    Serial.println("error");
    #endif
    while(true){}
}