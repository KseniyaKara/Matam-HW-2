#pragma once

class Matrix{
    unsigned int rowNum = 0;
    unsigned int colNum = 0;
    int* matrix = nullptr;
    
    public:
        Matrix(unsigned rowNum = 0, unsigned colNum = 0, int initValue = 0);
        Matrix(const Matrix& other);
        Matrix& Matrix::operator=(const Matrix& s);
        ~Matrix();
};
