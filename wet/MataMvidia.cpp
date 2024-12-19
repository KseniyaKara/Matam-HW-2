#include "MataMvidia.h"
#include <iostream>

MataMvidia::MataMvidia( const std::string& filmName,\
    const std::string& authorName, const Matrix* filmInput, int filmLength):
 filmName(filmName),
authorName(authorName),
filmLength(filmLength){
    filmFrames = new Matrix[filmLength];
    for (int i = 0; i < filmLength; i++) {
        filmFrames[i] = filmInput[i];
    }
}

MataMvidia::MataMvidia(const MataMvidia& other){
    filmLength = other.filmLength;
    filmName = other.filmName;
    authorName = other.authorName;

    filmFrames = new Matrix[filmLength];
    for (int i = 0; i < filmLength; i++) {
        filmFrames[i] = other.filmFrames[i];
    }
}

MataMvidia& MataMvidia::operator=(const MataMvidia& other){
    if (this == &other){
        return *this;
    }
    filmLength = other.filmLength;
    filmName = other.filmName;
    authorName = other.authorName;
    delete[] filmFrames;
    filmFrames = new Matrix[filmLength];
    for (int i = 0; i < filmLength; i++) {
        filmFrames[i] = other.filmFrames[i];
    }
    return *this;
}

MataMvidia::~MataMvidia() {
    delete[] filmFrames;
}

const Matrix& MataMvidia::operator[](int index) const {
    if (index >= filmLength || index < 0) {
        std::cout<<("Bad index");
    }
    return filmFrames[index];
}

Matrix& MataMvidia::operator[](int index) {
    if (index >= filmLength || index < 0) {
        std::cout<<("Bad index");
    }
    return filmFrames[index];
}

MataMvidia& MataMvidia::operator+=(const MataMvidia& other) {
    int newFilmLength = filmLength + other.filmLength;
    Matrix* newFilm = new Matrix[newFilmLength];
    int i = 0;
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
    int newFilmLength = filmLength + 1;
    Matrix* newFilm = new Matrix[newFilmLength];
    int i = 0;
    for (; i < filmLength; ++i) {
        newFilm[i] = filmFrames[i];
    }
    newFilm[i] = matrix;
    delete[] filmFrames;
    filmFrames = newFilm;
    filmLength = newFilmLength;
    return *this;
}

MataMvidia MataMvidia::operator+(const MataMvidia& other) {
    Matrix* newFilm = new Matrix[filmLength + other.filmLength];
    int i = 0;
    for (; i < filmLength; ++i) {
        newFilm[i] = filmFrames[i];
    }
    for (; i < other.filmLength; ++i) {
        newFilm[i] = other.filmFrames[i];
    }
    MataMvidia resultFilm(filmName, authorName, newFilm, filmLength);
    delete[] newFilm;
    return resultFilm;
}

std::ostream& operator<<(std::ostream& os, const MataMvidia& film) {
    os << "Movie Name: " << film.filmName << std::endl;
    os << "Author: " << film.authorName << std::endl;
    int filmLength = film.filmLength;
    for(int i = 0 ; i < filmLength; ++i) {
        os << std::endl << "Frame " << i << ":" << std::endl << film.filmFrames[i];
    }
    os << std::endl << "-----End of Movie-----" << std::endl;
    return os;
}