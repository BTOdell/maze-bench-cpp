#include "solver.h"

#include <iostream>
#include <vector>

bool is_reachable(const Array2D<bool>& maze, const Point& start,
                  const Point& end) noexcept {
    int width = maze.width;
    int widthM1 = width - 1;
    int height = maze.height;
    int heightM1 = height - 1;

    Array2D<bool> visited(width, height);
    visited.set(start.x, start.y, true);

    std::vector<Point> stack;
    stack.reserve(width);
    Point p = start;

    while (true) {
        int x = p.x;
        int y = p.y;
        // Check if we've reached the end
        if (x == end.x && y == end.y) {
            return true;
        }
        // Check left
        if (x > 0) {
            int left = x - 1;
            if (!visited.get(left, y) && maze.get(left, y)) {
                // Go left
                stack.emplace_back(left, y);
                visited.set(left, y, true);
            }
        }
        // Check right
        if (x < widthM1) {
            int right = x + 1;
            if (!visited.get(right, y) && maze.get(right, y)) {
                // Go right
                stack.emplace_back(right, y);
                visited.set(right, y, true);
            }
        }
        // Check up
        if (y > 0) {
            int up = y - 1;
            if (!visited.get(x, up) && maze.get(x, up)) {
                // Go up
                stack.emplace_back(x, up);
                visited.set(x, up, true);
            }
        }
        // Check down
        if (y < heightM1) {
            int down = y + 1;
            if (!visited.get(x, down) && maze.get(x, down)) {
                // Go down
                stack.emplace_back(x, down);
                visited.set(x, down, true);
            }
        }
        if (stack.empty()) {
            break;
        }
        p = stack.back();
        stack.pop_back();
    }

    return false;
}
