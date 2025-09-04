#include "convolution.h"
#include <iostream>
#include <vector>

// Function to perform 2D dilated convolution
std::vector<std::vector<int>> dilated_convolution_2d(
    const std::vector<std::vector<int>>& input, 
    const std::vector<std::vector<int>>& kernel, 
    int dilation_h, 
    int dilation_w
) {
    int input_height = input.size();
    int input_width = input[0].size();
    int kernel_height = kernel.size();
    int kernel_width = kernel[0].size();

    // Calculate output dimensions
    int output_height = (input_height - kernel_height + dilation_h) / dilation_h + 1;
    int output_width = (input_width - kernel_width + dilation_w) / dilation_w + 1;

    // Initialize output matrix
    std::vector<std::vector<int>> output(output_height, std::vector<int>(output_width, 0));

    // Perform the 2D dilated convolution
    for (int i = 0; i < output_height; ++i) {  // Loop 1: Iterate over output height
        for (int j = 0; j < output_width; ++j) {  // Loop 2: Iterate over output width
            for (int m = 0; m < kernel_height; ++m) {  // Loop 3: Iterate over kernel rows
                for (int n = 0; n < kernel_width; ++n) {  // Loop 4: Iterate over kernel columns
                    int input_x = i * dilation_h + m;  // Apply dilation in height
                    int input_y = j * dilation_w + n;  // Apply dilation in width
                    if (input_x < input_height && input_y < input_width) {
                        output[i][j] += input[input_x][input_y] * kernel[m][n];
                    }
                }
            }
        }
    }

    return output;
}
