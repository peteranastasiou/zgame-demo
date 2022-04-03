#include "audio.system.hpp"
#include "audio.channel.hpp"

namespace audio {

static Tone const hello[] = {
    {Note::C4, 5, 10},
    {Note::NONE, 5, 10},
    {Note::E4, 10, 10},
    {Note::F4, 5, 10},
    {Note::NONE, 10, 10},
    {Note::A5, 10, 10},
    {Note::D5, 10, 10},
    {Note::C5, 10, 10},
    {Note::NONE, 10, 10},
    {Note::END, 0, 0},
};

static Tone const bass[] = {
    {Note::C2, 10, 10},
    {Note::D2, 10, 10},
    {Note::E2, 10, 10},
    {Note::F2, 10, 10},
    {Note::C2, 10, 10},
    {Note::A3, 10, 10},
    {Note::D3, 10, 10},
    {Note::C3, 10, 10},
    {Note::END, 0, 0},
};

static Tone const beat[] = {
    {Note::C6, 1, 10},
    {Note::C4, 2, 10},
    {Note::NONE, 1, 10},
    {Note::C4, 2, 10},
    {Note::C6, 1, 10},
    {Note::C4, 2, 10},
    {Note::NONE, 1, 10},
    {Note::C4, 2, 10},
    {Note::LOOP, 0, 0},
};

void demo()
{
    audio::Channel::pulse1.play(hello);
    audio::Channel::triangle.setVolume(75);
    audio::Channel::triangle.play(bass);
    audio::Channel::noise.play(beat);
}

}