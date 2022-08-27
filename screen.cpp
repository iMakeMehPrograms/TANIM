#include "canim.hpp"

Screen::Screen(std::string nm) { // constructor
    name = nm;
}

void Screen::Display(std::string frame) { // display one frame
    std::ofstream display;
    display.open(name, std::fstream::trunc | std::fstream::out);
    if (display.is_open()) {
        display << frame << std::flush;
        display.close();
    }
}
