#include "dir.hpp"


int dirGetX(Dir d){
    switch(d){
        case Dir::E:
            return 1;
        case Dir::W:
            return -1;
        case Dir::N:
        case Dir::S:
        default:
            return 0;
    }
}

int dirGetY(Dir d){
    switch(d){
        case Dir::S:
            return 1;
        case Dir::N:
            return -1;
        case Dir::E:
        case Dir::W:
        default:
            return 0;
    }
}
