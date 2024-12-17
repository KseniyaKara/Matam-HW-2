#pragma once
#include <ostream>

class Matrix{
    unsigned int rowNum = 0;
    unsigned int colNum = 0;
    int* matrix = nullptr;//const?
    
    public:
        explicit Matrix(unsigned int rowNum = 0, unsigned int colNum = 0, int initValue = 0);///do we need explicit?
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& s);
        ~Matrix();
        unsigned int getRowNum() const;
        unsigned int getRowNum();
        unsigned int getColNum() const;
        unsigned int getColNum();
        int* getMatrix() const;
        int* getMatrix();
        // void setColNum(int col);
        // void setRowNum(int row);
        int& Matrix::operator()(int row, int col) ;
        const int& Matrix::operator()(int row, int col)const;
        friend bool operator==(const Matrix& matrix, const Matrix& other);
        Matrix& operator*=(int scalar);
        Matrix operator-() const;
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);
        void sizeMatch(const Matrix& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        void isSquare() const;
        static int CalcDeterminant(const Matrix matrix);
        static int CalcDeterminantRec(const Matrix& matrix, int row, int col, int* ignoredRowsMask, \
        int* ignoredColumnsMask) ;
        static int CalcSingleElementMult(const Matrix& matrix, const Matrix& other, int row, int col);
        static unsigned int CalcProbeniousNorm(const Matrix& matrix);
        Matrix transpose() const;
        Matrix rotateClockwise() const;
        Matrix rotateCounterClockwise() const;
};
    bool operator!=(const Matrix& matrix,const Matrix& other);
    Matrix operator*(const Matrix& matrix, int scalar);
    Matrix operator+(const Matrix& matrix, const Matrix& other);
    Matrix operator-(const Matrix& matrix, const Matrix& other);
    Matrix operator*(const Matrix& matrix, const Matrix& other);

