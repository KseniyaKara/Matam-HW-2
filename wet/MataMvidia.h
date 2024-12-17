#pragma once
#include <string>
#include "Matrix.h"

class MataMvidia {
    private:
        unsigned int filmLength = 0;
        std::string filmName;
        std::string authorName;
        Matrix* filmFrames = nullptr;
    public:
        MataMvidia(const std::string& filmName, const std::string& authorName, Matrix* filmFramesOther, unsigned int filmLength);
        MataMvidia(const MataMvidia& other);
        MataMvidia& MataMvidia::operator=(const MataMvidia& s);
        ~MataMvidia();
        // const Matrix& Matrix::operator[](int index) const;
        Matrix MataMvidia::operator[](int index);
        MataMvidia& MataMvidia::operator+=(const MataMvidia& other);
        MataMvidia& MataMvidia::operator+=(const Matrix& other);
};
