#pragma once

class Matrix{
    unsigned int rowNum = 0;
    unsigned int colNum = 0;
    int* matrix = nullptr;//const?
    
    public:
        explicit Matrix(unsigned int rowNum = 0, unsigned int colNum = 0, int initValue = 0);///do we need explicit?
        Matrix(const Matrix& other);
        Matrix& Matrix::operator=(const Matrix& s);
        ~Matrix();
        int getRowNum();
        int getColNum();
        void setColNum(int col);
        void setRowNum(int row);
        int* Matrix::operator()(int row, int col);///??
        bool Matrix::operator==(const Matrix& other);
        bool Matrix::operator!=(const Matrix& other);/// can we write this line outside the class?
};
