#include "MataMvdia.h"
Film::Film(const std::string& filmName, const std::string& authorName, Matrix* filmFramesOther, unsigned int filmLength):
filmName(filmName), authorName(authorName), filmLength(filmLength){
    filmFrames = new Matrix[filmLength];
    for (unsigned int i = 0; i < filmLength; i++) {
        filmFrames[i] = filmFramesOther[i];
    }
}

Film::Film(const Film& other){}
Film& Film::operator=(const Film& s){}
Film::~Film() {
    delete[]filmFrames;
}