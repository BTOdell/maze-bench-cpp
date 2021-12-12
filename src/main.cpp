#include <chrono>
#include <iostream>

#include "Array2D.hpp"
#include "lodepng.h"
#include "solver.h"

long long delta_nanos(const std::chrono::steady_clock::time_point& tp) {
    auto dur = std::chrono::steady_clock::now() - tp;
    return std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();
}

int main() {
    std::vector<unsigned char> pixels;
    unsigned int uwidth;
    unsigned int uheight;
    unsigned int error = lodepng::decode(pixels, uwidth, uheight, "maze1000.png");
    if (error) {
        std::cerr << "Image decode error " << error << ": "
                  << lodepng_error_text(error) << std::endl;
        return 1;
    }
    int width = uwidth;
    int height = uheight;
    std::cout << "Loaded image: " << width << " x " << height << std::endl;
    if (width <= 2 || height <= 2) {
        std::cerr << "Image size must be at least 3x3" << std::endl;
        return 1;
    }
    // Process image into maze boolean array
    std::cout << "Transforming image into maze..." << std::endl;
    auto time = std::chrono::steady_clock::now();
    Array2D<bool> maze(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int p = (y * width + x) << 2;
            maze.set(x, y, (pixels[p] + pixels[p + 1] + pixels[p + 2]) > 0);
        }
    }
    std::cout << "Transformed image into maze in " << delta_nanos(time) << "ns"
              << std::endl;
    Point start(0, 1);
    Point end(2000, 1999);
    std::cout << "Solving maze from (" << start.x << "," << start.y << ") to ("
              << end.x << "," << end.y << ") ..." << std::endl;
    // Test "cold"
    time = std::chrono::steady_clock::now();
    bool success = is_reachable(maze, start, end);
    auto cold_time = delta_nanos(time);
    // Warm up
    int i = 1000;
    while (i-- > 0) {
        success = is_reachable(maze, start, end);
    }
    // Test "warm"
    time = std::chrono::steady_clock::now();
    success = is_reachable(maze, start, end);
    auto warm_time = delta_nanos(time);
    if (success) {
        std::cout << "Solved maze in: cold=" << cold_time
                  << "ns, warm=" << warm_time << "ns" << std::endl;
    } else {
        std::cerr << "Failed to solve maze." << std::endl;
    }
    return 0;
}
