#pragma once
#include <ostream>

class Matrix{
    int rowNum = 0;
    int colNum = 0;
    int* matrix = nullptr;
    
    public:
        explicit Matrix(int rowNum = 0, int colNum = 0, int initValue = 0);
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& s);
        ~Matrix();
        friend bool operator==(const Matrix& matrix, const Matrix& other);
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        int getRowNum() const;
        int getRowNum();
        int getColNum() const;
        int getColNum();
        int* getMatrix() const;
        int* getMatrix();
        int& operator()(int row, int col) ;
        const int& operator()(int row, int col)const;
        Matrix& operator*=(int scalar);
        Matrix operator-() const;
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);
        void sizeMatch(const Matrix& other) const;
        void isSquare() const;
        Matrix transpose() const;
        Matrix rotateClockwise() const;
        Matrix rotateCounterClockwise() const;
        static int CalcDeterminant(const Matrix& matrix);
        static int CalcDeterminantRec(const Matrix& matrix, int row, int col,\
        int* ignoredRowsMask, int* ignoredColumnsMask) ;
        static int CalcSingleElementMult(const Matrix& matrix, const Matrix& other, int row, \
            int col);
        static int CalcFrobeniousNorm(const Matrix& matrix);
        static void checkOrderBounds(int rowNum, int colNum);

};
    bool operator!=(const Matrix& matrix,const Matrix& other);
    Matrix operator*(const Matrix& matrix, int scalar);
    Matrix operator*(int scalar, const Matrix& matrix);
    Matrix operator+(const Matrix& matrix, const Matrix& other);
    Matrix operator-(const Matrix& matrix, const Matrix& other);
    Matrix operator*(const Matrix& matrix, const Matrix& other);