#include "Matrix.h"

#include <iostream>
#include <ostream>

Matrix::Matrix(unsigned int rowNum, unsigned int colNum, int initValue) {
    int* matrix = new int[rowNum * colNum];
    if (!matrix) {
        std::cout << "Memory allocation failed!" << std::endl;
    }
    for (int i = 0; i < rowNum*colNum; i++) {
        matrix[i] = initValue;
    }
}
