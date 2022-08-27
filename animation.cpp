#include "canim.hpp"

Animation::Animation(std::vector<std::string> anim, std::chrono::milliseconds tbf, Screen dscreen) // constructor
    : frames{anim}
    , timeBeetweenFrames{tbf}
    , defaultScreen{dscreen.name}
{}

    void Animation::Play() // play no args
    {
        dlay(1, frames, timeBeetweenFrames, defaultScreen);
    }
    void Animation::Play(int repeatTimes) // play con repeat
    {
        dlay(repeatTimes, frames, timeBeetweenFrames, defaultScreen);
    }
    void Animation::Play(Screen scr) // play different screen
    {
        dlay(1, frames, timeBeetweenFrames, scr);
    }

    void Animation::Play(int repeatTimes, Screen scr) //play con repeat y different screen
    {
        dlay(repeatTimes, frames, timeBeetweenFrames, scr);
    }

    void Animation::dlay(int repeatTimes, std::vector<std::string> frames, std::chrono::milliseconds tbf, Screen ahh)
    {
        int frameIndex = 0;
        int repeat = 0;
        while (repeat < repeatTimes)
        {
            while (frameIndex != frames.size())
            {
                ahh.Display(frames[frameIndex++]);
                std::this_thread::sleep_for(tbf);
            }
            frameIndex = 0;
            repeat++;
        }
    }

int main() {
    // refresh speeds:
    // notepad: not at all
    // vsc: (old) can do 24 and 30 fps but 60 be damned
    // vsc: (new) can do 10 fps but even 12 is bad now? What?
    // vsc: (again) 24 and 30 again
    //std::vector<std::string> an = {"  <|()|>  ", " }<[||]>{ ", "|=={[]}==|"};
    std::vector<std::string> an = {
        "()      ",
        " ()     ",
        "  ()    ",
        "   ()   ",
        "    ()  ",
        "     () ",
        "      ()",
        "     () ",
        "    ()  ",
        "   ()   ",
        "  ()    ",
        " ()     "};
    Screen out("output.txt");
    Animation anim(an, fpsToTbf(24), out);
    anim.Play();
    out.Display("Haha!");
}