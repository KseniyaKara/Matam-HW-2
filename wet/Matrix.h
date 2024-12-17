#pragma once
#include <ostream>

class Matrix{
    unsigned int rowNum = 0;
    unsigned int colNum = 0;
    int* matrix = nullptr;//const?
    
    public:
        explicit Matrix(unsigned int rowNum = 0, unsigned int colNum = 0, int initValue = 0);///do we need explicit?
        Matrix(const Matrix& other);
        Matrix& Matrix::operator=(const Matrix& s);
        ~Matrix();
        int getRowNum() const;
        int getRowNum();
        int getColNum() const;
        int getColNum();
        // void setColNum(int col);
        // void setRowNum(int row);
        const int& Matrix::operator()(int row, int col) const;
        friend bool operator==(const Matrix& matrix, const Matrix& other);
        Matrix& operator*=(int scalar);
        Matrix operator-() const;
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);
        void sizeMatch(const Matrix& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        void Matrix::isSquare() const;
        static int CalcDeterminant(const Matrix matrix);
        static int CalcDeterminantRec(const Matrix& matrix, int row, int col, int* ignoredRowsMask, \
        int* ignoredColumnsMask) ;
        static int CalcSingleElementMult(const Matrix& matrix, const Matrix& other);
};
    bool operator!=(const Matrix& matrix,const Matrix& other);
    Matrix operator*(const Matrix& matrix, int scalar);
    Matrix operator+(const Matrix& matrix, const Matrix& other);
    Matrix operator-(const Matrix& matrix, const Matrix& other);
    Matrix operator*(const Matrix& matrix, const Matrix& other);