#pragma once
#include <string>
#include "Matrix.h"

class MataMvidia {
        int filmLength;
        std::string filmName;
        std::string authorName;
        Matrix* filmFrames = nullptr;
    public:
        MataMvidia(int filmLength = 0, const std::string& filmName = "", const std::string& authorName = "",Matrix* filmFramesOther = nullptr);
        MataMvidia(const MataMvidia& other);
        MataMvidia& operator=(const MataMvidia& s);
        ~MataMvidia();
        // const Matrix& Matrix::operator[](int index) const;
        Matrix operator[](unsigned index);
        MataMvidia& operator+=(const MataMvidia& other);
        MataMvidia& operator+=(const Matrix& other);
        MataMvidia operator+(const MataMvidia& other);
        friend std::ostream& operator<<(std::ostream& os, const MataMvidia& film);
};
