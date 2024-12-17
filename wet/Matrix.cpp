#include "Matrix.h"

#include <iostream>
#include <ostream>

#include "Utilities.h"

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
colNum(other.colNum){
    int* matrix = new int[rowNum * colNum];
    for (int i = 0; i < rowNum*colNum; i++) {
        matrix[i] = other.matrix[i];
    }
}

Matrix::~Matrix() {
    delete[] matrix;
}

Matrix& Matrix::operator=(const Matrix& s){
    if (this == &s){
        return *this;
    }
    rowNum(s.rowNum);
    colNum(s.colNum);
    delete[] matrix;
    int* matrix = new int[rowNum * colNum];
    for (int i = 0; i < rowNum*colNum; i++) {
        matrix[i] = s.matrix[i];
    }
}
int Matrix::getRowNum() const{
    return rowNum;
}
int Matrix::getRowNum() {
    return rowNum;
}

int Matrix::getColNum() const {
    return colNum;
}
int Matrix::getColNum() {
    return colNum;
}
// void setColNum(int col) {
//
// }
// void setRowNum(int row) {
//
// }

const int& Matrix::operator()(int row, int col) const{
    return matrix[row * col + col];
}
bool Matrix::operator==(const Matrix& other) {
    bool equal = true;
    if (rowNum != other.rowNum || colNum != other.colNum) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for (int i = 0; i < rowNum*colNum; i++) {
        if (matrix[i] != other.matrix[i]) {
            equal = false;
        }
    }
    return equal;
}

