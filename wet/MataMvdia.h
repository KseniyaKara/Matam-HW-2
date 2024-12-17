#pragma once
#include <string>
#include "Matrix.h"


class Film {
    private:
        unsigned int filmLength = 0;
        std::string filmName;
        std::string authorName;
        Matrix* filmFrames = nullptr;
    public:
        Film(const std::string& filmName, const std::string& authorName, Matrix* filmFramesOther, unsigned int filmLength);
        Film(const Film& other);
        Film& Film::operator=(const Film& s);
        ~Film();
        const Matrix& Matrix::operator[](int index) const;
        Matrix& Matrix::operator[](int index);

};
