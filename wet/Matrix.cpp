#include "Matrix.h"

#include <iostream>
#include <ostream>

Matrix::Matrix(unsigned int rowNum, unsigned int colNum, int initValue):
rowNum(rowNum),
colNum(colNum){
    int* matrix = new int[rowNum * colNum];
    if (!matrix) {
        std::cout << "Memory allocation failed!" << std::endl;
    }
    for (int i = 0; i < rowNum*colNum; i++) {
        matrix[i] = initValue;
    }
}

Matrix::Matrix(const Matrix& other):
rowNum(other.rowNum),
colNum(other.colNum) {
    int* matrix = new int[rowNum * colNum];
    for (int i = 0; i < rowNum*colNum; i++) {
        matrix[i] = other.matrix[i];
    }
}

Matrix::~Matrix() {
    delete[] matrix;
}
