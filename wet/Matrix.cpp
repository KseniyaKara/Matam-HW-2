#include "Matrix.h"
#include <iostream>
#include <cmath>
#include "Utilities.h"

Matrix::Matrix(int rowNum, int colNum, int initValue):
rowNum(rowNum),
colNum(colNum){
    matrix = new int[rowNum * colNum];
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

int* Matrix::getMatrix() const{
    return matrix;
}

int* Matrix::getMatrix() {
    return matrix;
}

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

Matrix operator*(int scalar, const Matrix& matrix) {
    return Matrix(matrix) *= scalar;
}

Matrix Matrix::operator-() const{
    return Matrix(*this) *= -1;
}

Matrix& Matrix::operator+=(const Matrix& other){
    sizeMatch(other);
    int matrixElementNum = rowNum * colNum;
    for(int i = 0; i < matrixElementNum; ++i) {
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

int CalcSingleElementMult(const Matrix& matrix, const Matrix& other, int row, int col) {
    int n = matrix.getColNum();
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
    int m = matrix.getRowNum();
    int q = other.getColNum();

    Matrix result(m, q, 0);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < q; ++i) {
            int value = CalcSingleElementMult(matrix, other, i, j);
            result(i, j) =  value;
        }   
    }
    return result;
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

int CalcFrobeniousNorm(const Matrix& matrix) {
    int norm = 0;
    for(int i = 0; i < matrix.getRowNum() ; ++i) {
        for (int j = 0; j < matrix.getColNum(); ++j) {
            norm += matrix(i,j) * matrix(j,j);
        }
    }
    norm = sqrt(norm);
    return norm;

}
    
Matrix Matrix::transpose() const{
    Matrix newMatrix((*this).getColNum(), (*this).getRowNum(), 0);
    for (int i = 0; i < (*this).getRowNum() ; ++i) {
        for (int j = 0; j < (*this).getColNum(); ++j) {
            newMatrix(j,i) = (*this)(i,j);
        }
    }
    return newMatrix;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

Matrix Matrix::rotateClockwise() const{
    Matrix rotated = (*this).transpose();
    for (int j = 0; j < colNum; ++j) {
        for (int i = 0; i < rowNum / 2; ++i) {
            swap((rotated)(i, j), (rotated)(rowNum -1 - i, j));
        }
    }
    return rotated;
}

Matrix Matrix::rotateCounterClockwise() const{
    Matrix rotated = (*this).transpose();
    for (int i = 0; i < rotated.rowNum; ++i) {
        for (int j = 0; j < rotated.colNum / 2; ++j) {
            swap(rotated(i, j), rotated(i, rotated.colNum - j - 1));
        }
    }
    return rotated;

}

int CalcDeterminantRec(const Matrix& matrix, int row, int col, int* ignoredRowsMask, \
int* ignoredColumnsMask) {
    int det = 0;
    int rowNum = matrix.getRowNum();
    int colNum = matrix.getColNum();
    int pivot = 0;
    int pivotSign = 0;
    if(rowNum == 2) {
        int* matrixArray = matrix.getMatrix();
        int detElements[4]; 
        int count = 0;
        for(int i = 0; i < rowNum; ++i) {
            for(int j = 0; j < colNum; ++j) {
                if(!ignoredRowsMask[i] && !ignoredColumnsMask[j]) {
                    detElements[count] = matrixArray[i * colNum + j];
                    ++count;
                }
            }
        }
        return detElements[0] * detElements[3] - detElements[2] * detElements[1];
    }
    pivotSign = ((row + col) %2 == 0) * 1 +  ((row + col) %2 != 0) * -1;
    pivot = pivotSign * matrix.getMatrix()[row * colNum + col];
    ignoredRowsMask[row] = 1;
    ignoredColumnsMask[col] = 1;
    det += pivot * CalcDeterminantRec(matrix, (row + 1) % rowNum, (col + 1) * colNum, \
    ignoredRowsMask, ignoredColumnsMask);
    ignoredColumnsMask[col] = 0;
    ignoredRowsMask[row] = 0;
    return det;
}

int CalcDeterminant(const Matrix& matrix) {
    int* ignoredColumnsMask = new int[matrix.getRowNum()]();
    int* ignoredRowsMask = new int[matrix.getColNum()]();
    matrix.isSquare();
    return CalcDeterminantRec(matrix, 0, 0, ignoredRowsMask, ignoredColumnsMask);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << "|";
    for(int i = 0 ; i < matrix.rowNum; ++i) {
        for(int j = 0 ; j < matrix.colNum; ++j) {
            os << matrix(i, j) << "|";
        }
        os << std::endl;
    }
    return os;
}
