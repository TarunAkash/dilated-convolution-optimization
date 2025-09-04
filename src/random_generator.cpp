#include "random_generator.h"
#include <vector>
#include <random>

// Function to generate random input and kernel for testing
std::vector<int> generate_random_case(int input_size, int kernel_size) {
    std::vector<int> input(input_size);
    std::vector<int> kernel(kernel_size);

    // Generate random numbers for input
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255); // For random values between 0 and 255

    for (int i = 0; i < input_size; ++i) {
        input[i] = dis(gen);
    }

    // Generate random kernel
    for (int i = 0; i < kernel_size; ++i) {
        kernel[i] = dis(gen);
    }

    // Return input and kernel
    input.insert(input.end(), kernel.begin(), kernel.end());
    return input;
}

