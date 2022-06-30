
#pragma once

// Cardinal directions

enum class Dir {
    NONE, N, E, S, W
};

int dirGetX(Dir d);

int dirGetY(Dir d);
