#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <vector>

// Function to perform 2D dilated convolution
std::vector<std::vector<int>> dilated_convolution_2d(
    const std::vector<std::vector<int>>& input, 
    const std::vector<std::vector<int>>& kernel, 
    int dilation_h, 
    int dilation_w
);

#endif // CONVOLUTION_H
