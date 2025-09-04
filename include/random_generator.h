#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <vector>

// Function to generate random 2D input matrix
std::vector<std::vector<int>> generate_random_input(int height, int width);

// Function to generate random 2D kernel matrix
std::vector<std::vector<int>> generate_random_kernel(int height, int width);

#endif // RANDOM_GENERATOR_H
