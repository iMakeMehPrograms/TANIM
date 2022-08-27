#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
using namespace std::chrono_literals; 

class Screen {
public:
    /// Constructor
    Screen(std::string nm);
    /// Display a frame into the Screen
    void Display(std::string frame);
    /// the name of the file to use
    std::string name;
/*
protected:
    
    /// the name of the file to use
    std::string name;*/
};

class Animation {
    public:
        std::vector<std::string> frames;
        std::chrono::milliseconds timeBeetweenFrames;
        Screen defaultScreen;

        Animation(std::vector<std::string> anim, std::chrono::milliseconds timeBeetweenFrames, Screen dscreen);

        void Play();
        void Play(int repeatTimes);
        void Play(Screen scr);
        void Play(int repeatTimes, Screen scr);

    private:
        /// Iteratively calls screen.display
        void dlay(int repeatTimes, std::vector<std::string> frames, std::chrono::milliseconds tbf, Screen ahh); // the last arg shows the pain i experienced making this
};

std::chrono::milliseconds fpsToTbf(int fps);