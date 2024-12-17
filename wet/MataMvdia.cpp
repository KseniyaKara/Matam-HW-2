#include "MataMvdia.h"
Film::Film(const std::string& filmName, const std::string& authorName, Matrix* filmFrames, unsigned int filmLength){}
Film::Film(const Film& other){}
Film& Film::operator=(const Film& s){}
Film::~Film() {
    delete[]filmFrames;
}