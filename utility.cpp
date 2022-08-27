#include "canim.hpp"

std::chrono::milliseconds fpsToTbf(int fps) {
    int nout;
    nout = fps;
    nout = 1000 / nout;
    nout = std::round(nout);
    std::chrono::milliseconds out = std::chrono::milliseconds(nout);
    return out;
}

// do read from file for frames