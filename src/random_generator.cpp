#include "random_generator.h"
#include <vector>
#include <random>

// Function to generate random 2D input matrix
std::vector<std::vector<int>> generate_random_input(int height, int width) {
    std::vector<std::vector<int>> input(height, std::vector<int>(width));

    // Random number generation (0 to 255)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            input[i][j] = dis(gen);
        }
    }

    return input;
}

// Function to generate random 2D kernel matrix
std::vector<std::vector<int>> generate_random_kernel(int height, int width) {
    std::vector<std::vector<int>> kernel(height, std::vector<int>(width));

    // Random number generation (0 to 255)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            kernel[i][j] = dis(gen);
        }
    }

    return kernel;
}
