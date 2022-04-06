
#pragma once

#include "wasm4.h"

/**
 * Queue of objects of type `Type`
 */
template<typename Type, int BUFFER_SIZE>
class Queue {
private:
    int head_ = 0;
    int tail_ = 0;
    int size_ = 0;
    Type buffer_[BUFFER_SIZE];

public:
    int getSize(){
        return size_;
    }

    bool isEmpty(){
        return size_ == 0;
    }

    bool isFull(){
        return size_ == BUFFER_SIZE;
    }

    bool push(Type elm){
        if( size_ == BUFFER_SIZE ) return false;

        buffer_[tail_]= elm;
        tail_ = (tail_ + 1) % BUFFER_SIZE;
        size_++;

        return true;
    }

    Type pop() {
        // Invalid use, but still need to return something :P
        if( size_ == 0 ) return buffer_[0];

        Type elm = buffer_[head_];
        head_ = (head_ + 1) % BUFFER_SIZE;
        size_--;

        return elm;
    }

};
