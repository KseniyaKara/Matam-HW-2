#include "MataMvdia.h"
Film::Film(const std::string& filmName, const std::string& authorName, Matrix* filmFramesOther, unsigned int filmLength):
filmName(filmName), authorName(authorName), filmLength(filmLength){
    filmFrames = new Matrix[filmLength];
    for (unsigned int i = 0; i < filmLength; i++) {
        filmFrames[i] = filmFramesOther[i];
    }
    delete[] filmFramesOther;////??????
}

Film::Film(const Film& other) : filmName(other.filmName),
authorName(other.authorName), filmLength(other.filmLength){
    filmFrames = new Matrix[filmLength];
    for (unsigned int i = 0; i < filmLength; i++) {
        filmFrames[i] = other.filmFrames[i];
    }
}


Film::~Film() {
    delete[]filmFrames;
}