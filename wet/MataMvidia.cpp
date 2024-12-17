#include "MataMvidia.h"
#include <iostream>

MataMvidia::MataMvidia(const std::string& filmName, const std::string& authorName, Matrix* filmFramesOther, unsigned int filmLength):
filmName(filmName), authorName(authorName), filmLength(filmLength){
    filmFrames = new Matrix[filmLength];
    for (unsigned int i = 0; i < filmLength; i++) {
        filmFrames[i] = filmFramesOther[i];
    }
    delete[] filmFramesOther;////??????
}

MataMvidia::MataMvidia(const MataMvidia& other) : filmName(other.filmName),
authorName(other.authorName), filmLength(other.filmLength){
    filmFrames = new Matrix[filmLength];
    for (unsigned int i = 0; i < filmLength; i++) {
        filmFrames[i] = other.filmFrames[i];
    }
}

MataMvidia& MataMvidia::operator=(const MataMvidia& s): filmName(s.filmName),
authorName(s.authorName), filmLength(s.filmLength) {
    if (this == &s){
        return *this;
    }
    delete[] filmFrames;
    filmFrames = new Matrix[filmLength];
    for (int i = 0; i < filmLength; i++) {
        filmFrames[i] = s.filmFrames[i];
    }
}


MataMvidia::~MataMvidia() {
    delete[]filmFrames;
}

// const Matrix& operator[](int index) const{}
Matrix MataMvidia::operator[](int index) {
    if (index >=filmLength() || index < 0) {
        std::cout<<("Bad index");
    }
    return filmFrames[index];
}