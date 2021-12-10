#pragma once

#include "Array2D.h"

struct Point {
    int x;
    int y;
};

bool is_reachable(Array2D& maze, Point& start, Point& end);
