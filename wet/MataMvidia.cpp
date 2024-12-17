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

MataMvidia::MataMvidia(const MataMvidia& other){
    filmLength = other.filmLength;
    filmName = other.filmName;
    authorName = other.authorName;
    filmFrames = new Matrix[filmLength];
    for (unsigned int i = 0; i < filmLength; i++) {
        filmFrames[i] = other.filmFrames[i];
    }
}

MataMvidia& MataMvidia::operator=(const MataMvidia& s){
    filmLength = s.filmLength;
    filmName = s.filmName;
    authorName = s.authorName;
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
    delete[] filmFrames;
}

// const Matrix& operator[](int index) const{}
Matrix MataMvidia::operator[](int index) {
    if (index >=filmLength || index < 0) {
        std::cout<<("Bad index");
    }
    return filmFrames[index];
}

MataMvidia& MataMvidia::operator+=(const MataMvidia& other) {
    unsigned int newFilmLength = filmLength + other.filmLength;
    Matrix* newFilm = new Matrix[filmLength + other.filmLength];
    unsigned int i = 0;
    for (; i < filmLength; ++i) {
        newFilm[i] = filmFrames[i];
    }
    for (; i < other.filmLength; ++i) {
        newFilm[i] = other.filmFrames[i];
    }
    delete[] filmFrames;
    filmFrames = newFilm;
    filmLength = newFilmLength;

    return *this;
}

MataMvidia& MataMvidia::operator+=(const Matrix& matrix) {
    unsigned int newFilmLength = filmLength + 1;
    Matrix* newFilm = new Matrix[filmLength + 1];
    unsigned int i = 0;
    for (; i < filmLength; ++i) {
        newFilm[i] = filmFrames[i];
    }
    newFilm[i] = matrix;
    delete[] filmFrames;
    filmFrames = newFilm;
    filmLength = newFilmLength;

    return *this;
}