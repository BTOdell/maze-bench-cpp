#include "solver.h"

#include <iostream>
#include <stack>

bool is_reachable(const Array2D<bool>& maze, const Point& start,
                  const Point& end) noexcept {
    unsigned int width = maze.width;
    unsigned int widthM1 = width - 1;
    unsigned int height = maze.height;
    unsigned int heightM1 = height - 1;

    Array2D<bool> visited(width, height);
    visited.set(start.x, start.y, true);

    std::stack<Point> stack;
    Point p = start;

    while (true) {
        unsigned int x = p.x;
        unsigned int y = p.y;
        // Check if we've reached the end
        if (x == end.x && y == end.y) {
            return true;
        }
        // Check left
        if (x > 0) {
            unsigned int left = x - 1;
            if (!visited.get(left, y) && maze.get(left, y)) {
                // Go left
                stack.emplace(left, y);
                visited.set(left, y, true);
            }
        }
        // Check right
        if (x < widthM1) {
            unsigned int right = x + 1;
            if (!visited.get(right, y) && maze.get(right, y)) {
                // Go right
                stack.emplace(right, y);
                visited.set(right, y, true);
            }
        }
        // Check up
        if (y > 0) {
            unsigned int up = y - 1;
            if (!visited.get(x, up) && maze.get(x, up)) {
                // Go up
                stack.emplace(x, up);
                visited.set(x, up, true);
            }
        }
        // Check down
        if (y < heightM1) {
            unsigned int down = y + 1;
            if (!visited.get(x, down) && maze.get(x, down)) {
                // Go down
                stack.emplace(x, down);
                visited.set(x, down, true);
            }
        }
        if (stack.empty()) {
            break;
        }
        p = stack.top();
        stack.pop();
    }

    return false;
}
