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
    matrix = new int[rowNum * colNum];
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
    rowNum = s.rowNum;
    colNum = s.colNum;
    delete[] matrix;
    matrix = new int[rowNum * colNum];
    if (!matrix) {
        std::cout << "Memory allocation failed!" << std::endl;
    }
    for (int i = 0; i < rowNum*colNum; i++) {
        matrix[i] = s.matrix[i];
    }

    return *this;
}
unsigned int Matrix::getRowNum() const{
    return rowNum;
}
unsigned int Matrix::getRowNum() {
    return rowNum;
}

unsigned int Matrix::getColNum() const {
    return colNum;
}
unsigned int Matrix::getColNum() {
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

Matrix Matrix::operator-() const{
    return Matrix(*this) *= -1;
}

Matrix& Matrix::operator+=(const Matrix& other){
    sizeMatch(other);
    unsigned int matrixElementNum = rowNum * colNum;
    for(unsigned int i = 0; i < matrixElementNum; ++i) {
        matrix[i] += other.matrix[i]; 
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other){
    return *this += -other;
}

Matrix operator+(const Matrix& matrix, const Matrix& other){
    return Matrix(matrix) += other;
}

Matrix operator-(const Matrix& matrix, const Matrix& other) {
    return Matrix(matrix) -= other;
}

static int CalcSingleElementMult(const Matrix& matrix, const Matrix& other, int row, int col) {
    unsigned int n = matrix.getColNum();
    unsigned int m = other.getColNum();
    int result = 0;
    for(int k = 0; k < n; ++k) {
        result += matrix(row, k) * other(k, col);
    }
    return result;
}

Matrix operator*(const Matrix& matrix, const Matrix& other) {
    if(matrix.getColNum() != other.getRowNum()) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    unsigned int n = matrix.getColNum();
    unsigned int m = matrix.getRowNum();
    unsigned int q = other.getColNum();

    Matrix result(m, q, 0);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < q; ++i) {
            int value = CalcSingleElementMult(matrix, other, i, j);
            result(i, j) =  value;
        }   
    }
}

Matrix& Matrix::operator*=(const Matrix& other) {
    return *this = *this * other;
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

static unsigned int CalcProbeniousNorm(const Matrix& matrix);
    unsigned int norm = 0;
    for (int i = 0; i < matrix.getRowNum() ; ++i) {
        for (int j = 0; j < matrix.getColNum(); ++j) {
            norm += matrix(i,j) * matrix(j,j);
        }
    }
    norm = sqrt(norm);
    return norm;
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