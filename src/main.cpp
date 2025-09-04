#include <iostream>
#include <vector>
#include <chrono>  // For time measurement
#include "random_generator.h"
#include "convolution.h"
#include <cstdlib>  // For std::atoi to convert string to integer

int main(int argc, char* argv[]) {
    // Check if correct number of arguments is passed
    if (argc != 3) {
        std::cerr << "Usage: ./dilated_convolution <input_size> <kernel_size>" << std::endl;
        return 1;
    }

    // Parse the input size and kernel size from the command-line arguments
    int input_size = std::atoi(argv[1]);  // Input size (e.g., 1024)
    int kernel_size = std::atoi(argv[2]);  // Kernel size (e.g., 4)

    // Check if the sizes are valid (positive integers)
    if (input_size <= 0 || kernel_size <= 0) {
        std::cerr << "Input size and kernel size must be positive integers!" << std::endl;
        return 1;
    }

    // Dilation factor is constant at 1
    int dilation_h = 1;
    int dilation_w = 1;

    // Generate random square input matrix and kernel
    std::vector<std::vector<int>> input = generate_random_input(input_size, input_size);  // Square matrix
    std::vector<std::vector<int>> kernel = generate_random_kernel(kernel_size, kernel_size);  // Square kernel

    // Commented out the printing of the generated input and kernel
    /*
    // Print the generated input and kernel (optional, might be large for large sizes)
    std::cout << "Generated Input (first 5x5 values): " << std::endl;
    for (int i = 0; i < std::min(input_size, 5); ++i) {
        for (int j = 0; j < std::min(input_size, 5); ++j) {
            std::cout << input[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Generated Kernel (first 5x5 values): " << std::endl;
    for (int i = 0; i < std::min(kernel_size, 5); ++i) {
        for (int j = 0; j < std::min(kernel_size, 5); ++j) {
            std::cout << kernel[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */

    // Start measuring time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform dilated convolution
    std::vector<std::vector<int>> output = dilated_convolution_2d(input, kernel, dilation_h, dilation_w);

    // Stop measuring time
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate elapsed time
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Output the time taken for the operation
    std::cout << "Time taken for dilated convolution: " << elapsed_time.count() << " seconds." << std::endl;

    return 0;
}

