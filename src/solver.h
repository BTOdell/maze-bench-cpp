#pragma once

#include "Array2D.hpp"

struct Point {
    unsigned int x;
    unsigned int y;

    Point(unsigned int x, unsigned int y) noexcept: x(x), y(y) {}
};

bool is_reachable(const Array2D<bool>& maze, const Point& start, const Point& end) noexcept;
