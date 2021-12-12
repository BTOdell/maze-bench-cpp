#pragma once

#include "Array2D.hpp"

struct Point {
    int x;
    int y;

    Point(int x, int y) noexcept: x(x), y(y) {}
};

bool is_reachable(const Array2D<bool>& maze, const Point& start, const Point& end) noexcept;
