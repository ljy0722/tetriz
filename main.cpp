#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"
#include "draw.h"

using namespace std::chrono_literals;



void init(){
    tc::clear_screen();
    tc::hide_cursor();
    dw::window(1,1,9,6,"Hold");
    dw::window(1, 10, 12, 22, "Tetriz");
    dw::window(7,1,9,16,"Status");
    dw::window(19,22,8,4,"Info");
    dw::window(1,22,8,18,"Next");
}

void loop(){
    int i = 1;
    while (true)
    {
        tc::move_to(10, 4);
        std::cout << "FPS:" << ut::fps();

        tc::move_to(5, 10);
        tc::set_back_color(15);
        std::cout << "  ";
        tc::reset_color();
        std::cout << std::flush;
        std::this_thread::sleep_for(100ms);
    }
}

void exit(){
    tc::show_cursor();
    tc::reset_color();
}

int main()
{
    //std::cout << "\033[5;10H"<<"hellow world";
    // tc::move_to(5, 10);
    // tc::set_fore_color(214);
    // std::cout << "hello world";
    // tc::move_to(10, 1);

    init();
    loop();
    exit();

    return 0;
}