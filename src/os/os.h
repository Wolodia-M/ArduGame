#pragma once

#include "Arduino.h"

class OS
{
public:
    void tick();
    void init_prog();
    void init_buttons();
    void go_menu();
    void go_app_exit();

private:
    void load_prog();
};

extern OS OS;

class interupts
{
public:
    interupts();
    void int_tick()
    {
        interupts::open_menu();
        interupts::app_exit();
    };
    void open_menu()
    {
        if ((*exit).isClick())
        {
            OS.go_app_exit();
        }
    };
    void app_exit()
    {
        if ((*menu).isClick())
        {
            OS.go_menu();
        }
    };
    void init_menu_btn(btnapi *_menu)
    {
        menu = _menu;
    };
    void init_exit_btn(btnapi *_exit)
    {
        exit = _exit;
    };

private:
    btnapi *menu;
    btnapi *exit;
};
extern interupts inter;