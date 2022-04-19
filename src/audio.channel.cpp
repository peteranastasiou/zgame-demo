
#include "audio.channel.hpp"
#include "wasm4.h"

namespace audio {

// Initialise audio channels
Channel Channel::pulse1(TONE_PULSE1 | TONE_MODE3);
Channel Channel::pulse2(TONE_PULSE2 | TONE_MODE3);
Channel Channel::triangle(TONE_TRIANGLE);
Channel Channel::noise(TONE_NOISE);

Channel::Channel(uint8_t index): index_(index)
{
    volume_= 100; // max
    sequence_= nullptr;
    sequenceIdx_= 0;
    sequenceCount_= 0;
}

void Channel::play(Tone const sequence[])
{
    // TODO queue up next sequence, fade in/out
    sequence_= sequence;
    sequenceIdx_= 0;
    sequenceCount_= 0;
}

void Channel::setVolume(uint8_t volume)
{
    volume_= volume;
}

void Channel::tick()
{
    if( sequence_ == nullptr ){
        // nothing to play
        return;
    }
    if( sequenceCount_-- <= 0 ){
        // time to play next tone
        Tone t= sequence_[sequenceIdx_++];
        sequenceCount_= t.cadence;
        switch( t.note )
        {
            case Note::END: 
                sequence_= nullptr;
                break;

            case Note::NONE:
                // rest for set time
                break;

            case Note::LOOP:
                // replay from start
                sequenceIdx_= 0;
                t= sequence_[sequenceIdx_++];
                sequenceCount_= t.cadence;
                // fall-through
            default:
                tone((uint32_t)t.note, t.duration, volume_, index_);
        }
    }
}

}
