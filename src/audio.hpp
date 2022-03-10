/**
 * wasm 4 audio player
 */

#pragma once

#include "notes.hpp"


struct Tone
{
    // musical note or frequency to play:
    Note note;
    uint8_t duration; // number of frames to play note
    uint8_t cadence; // number of frames until next note

    // TODO sweep frequency
    // TODO attack, decay, release, sustain
};

/**
 * @brief A WASM4 Audio Channel
 */
class AudioChannel
{
public:
    // available channels:
    static AudioChannel pulse1;
    static AudioChannel pulse2;
    static AudioChannel triangle;
    static AudioChannel noise;

    AudioChannel(uint8_t index);

    // sequence is an array of Tones which must end with an END or LOOP note
    void play(Tone sequence[]);

    void setVolume(uint8_t volume);

    void tick();

private:
    uint8_t const index_;  // channel and mode as per wasm interface
    uint8_t volume_; // 0 - 100
    uint8_t duty_;  // TODO duty cycle bits for pulse channels

    // latest sequence
    Tone * sequence_;
    uint16_t sequenceIdx_;
    int16_t sequenceCount_;
};
