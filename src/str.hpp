
#pragma once

#include <stdint.h>

/**
 * String Interface
 */
class Str {
public:
    virtual char const * get()=0;
};

/**
 * Static C-string wrapper
 */
class StrStatic : public Str {
private:
    char const * cstr_;

public:
    StrStatic(char const * s): cstr_(s) {}

    char const * get() override {
        return cstr_;
    }
};

/**
 * String buffer class
 */
template<int LEN>
class StrBuffer : public Str {
private:
    char buf_[LEN];
    int idx_;

public:
    StrBuffer(){
        idx_=0;
        buf_[0]= 0;
    }

    char const * get() override {
        return buf_;
    }

    void append(char c){
        if( idx_ == LEN-1 ) return;
        buf_[idx_++]= c;
        buf_[idx_]= '\0';
    }

    void append(char * str){
        while( *str != '\0' ){
            if( idx_ == LEN-1 ){
                buf_[idx_]= '\0';
                return;
            }
            buf_[idx_++]= *str++;
        }
        buf_[idx_]= '\0';
    }

    void appendUint8(uint8_t n, char pad=0)
    {
        // hundreds:
        if( n >= 100 ){
            append('0' + char(n / 100));
            n = n % 100;
        }else if(pad){
            append(pad);
        }
        // tens:
        if( n >= 10 ){
            append('0' + char(n / 10));
            n = n % 10;
        }else if(pad){
            append(pad);
        }
        // units:
        append('0' + char(n));
    }
};
