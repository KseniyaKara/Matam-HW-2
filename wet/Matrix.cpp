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
    if (!matrix) {
        std::cout << "Memory allocation failed!" << std::endl;
    }
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
    if (!matrix) {
        std::cout << "Memory allocation failed!" << std::endl;
    }
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

void Matrix::sizeMatch(const Matrix& other) const {
    if(rowNum != other.rowNum || colNum != other.colNum) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
}

void Matrix::isSquare() const {
    if(rowNum != colNum) {
        exitWithError(MatamErrorType::NotSquareMatrix);
    }
}

Matrix& Matrix::operator*=(int scalar) {
    Matrix* resultMatrix = new Matrix(rowNum, colNum);
    for(int i = 0; i < rowNum; ++i) {
        for(int j = 0; j < colNum; ++j) {
            (*this)(i,j) *= scalar; 
        }
    }
    return *this;
}

Matrix operator*(const Matrix& matrix, int scalar) {
    return Matrix(matrix) *= scalar;
}

const int& Matrix::operator()(int row, int col) const{
    return matrix[row * col + col];
}

int& Matrix::operator()(int row, int col){
    return matrix[row * col + col];
}

 bool operator==(const Matrix& matrix, const Matrix& other){
    bool equal = true;
    if (matrix.rowNum != other.rowNum || matrix.colNum != other.colNum) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for (int i = 0; i < other.rowNum*other.colNum; i++) {
        if (matrix.matrix[i] != other.matrix[i]) {
            equal = false;
        }
    }
    return equal;
}

bool operator!=(const Matrix& matrix,const Matrix& other) {
    return!(matrix==other);
}
unsigned int normFrobenious(const Matrix& matrix) {
    unsigned int norm = 0;
}

Matrix& Transpose(Matrix& matrix) {
    Matrix newMatrix(matrix.getColNum(), matrix.getRowNum(), 0);
    for (int i = 0; i < matrix.getRowNum() ; ++i) {
        for (int j = 0; j < matrix.getColNum(); ++j) {
            newMatrix(j,i) = matrix(i,j);
        }
    }
    return newMatrix;
}