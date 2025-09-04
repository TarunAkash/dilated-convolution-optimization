#include <iostream>
#include "random_generator.h"
#include "convolution.h"

int main() {
    // Define input size and kernel size for random test case
    int input_size = 10;   // Example input size
    int kernel_size = 3;   // Example kernel size
    int dilation = 2;      // Example dilation

    // Generate random input and kernel
    std::vector<int> random_data = generate_random_case(input_size, kernel_size);

    // Split the random data into input and kernel
    std::vector<int> input(random_data.begin(), random_data.begin() + input_size);
    std::vector<int> kernel(random_data.begin() + input_size, random_data.end());

    // Print the input and kernel (optional)
    std::cout << "Input: ";
    for (int val : input) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Kernel: ";
    for (int val : kernel) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Perform the dilated convolution
    dilated_convolution(input, kernel, dilation);

    return 0;
}

