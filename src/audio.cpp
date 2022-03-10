
#include "audio.hpp"
#include "wasm4.h"

// Initialise audio channels
AudioChannel AudioChannel::pulse1(TONE_PULSE1 | TONE_MODE3);
AudioChannel AudioChannel::pulse2(TONE_PULSE2 | TONE_MODE3);
AudioChannel AudioChannel::triangle(TONE_TRIANGLE);
AudioChannel AudioChannel::noise(TONE_NOISE);

AudioChannel::AudioChannel(uint8_t index): index_(index)
{
    volume_= 100; // max
    sequence_= nullptr;
    sequenceIdx_= 0;
    sequenceCount_= 0;
}

void AudioChannel::play(Tone sequence[])
{
    // TODO queue up next sequence, fade in/out
    sequence_= sequence;
    sequenceIdx_= 0;
    sequenceCount_= 0;
}

void AudioChannel::tick()
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