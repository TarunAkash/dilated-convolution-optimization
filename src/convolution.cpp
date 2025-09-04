#include "convolution.h"
#include <iostream>
#include <vector>

void dilated_convolution(const std::vector<int>& input, const std::vector<int>& kernel, int dilation) {
    int input_size = input.size();
    int kernel_size = kernel.size();
    int output_size = (input_size - kernel_size + dilation) / dilation + 1;
    
    std::vector<int> output(output_size, 0); // Initialize output with zeros

    // Perform dilated convolution
    for (int i = 0; i < output_size; ++i) {
        for (int j = 0; j < kernel_size; ++j) {
            int idx = i * dilation + j;
            if (idx < input_size) {
                output[i] += input[idx] * kernel[j];
            }
        }
    }

    // Print output (optional for testing purposes)
    std::cout << "Dilated Convolution Output: ";
    for (int val : output) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

