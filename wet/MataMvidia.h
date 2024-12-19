#pragma once
#include <string>
#include "Matrix.h"

class MataMvidia {
        std::string filmName;
        std::string authorName;
        Matrix* filmFrames = nullptr;
        int filmLength;
    public:
        MataMvidia(const std::string& filmName = "", const std::string& authorName = "",\
            /*const */Matrix* filmFramesOther = nullptr, int filmLength = 0);
        MataMvidia(const MataMvidia& other);
        MataMvidia& operator=(const MataMvidia& s);
        ~MataMvidia();
        const Matrix operator[](int index) const;
        Matrix operator[](int index);
        MataMvidia& operator+=(const MataMvidia& other);
        MataMvidia& operator+=(const Matrix& other);
        MataMvidia operator+(const MataMvidia& other);
        friend std::ostream& operator<<(std::ostream& os, const MataMvidia& film);
};
