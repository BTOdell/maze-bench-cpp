#include <iostream>

#include "png++/png.hpp"

#include "solver.h"

int main() {
    png::image<png::rgba_pixel> img("maze1000.png");
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
