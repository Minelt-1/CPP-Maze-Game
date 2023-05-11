#ifndef VALIDMOVES_H
#define VALIDMOVES_H

#include "map.h"

inline bool won{false};

enum directions
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

bool Move(int& indexX, int& indexY, const directions &direction, Map &map);

#endif
