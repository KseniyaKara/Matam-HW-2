
#include "Pirate.h"


Pirate::Pirate(const string& name): name(name) {}

Pirate::Pirate(const string& name, unsigned int bounty): name(name), bounty(bounty) {}

void Pirate::setName(const string& name){
    this->name = name;
}

std::string Pirate::getName(){
    return name;
}

void Pirate::setBounty(const unsigned int& bounty) {
    this->bounty = bounty;
}

unsigned int Pirate::getBounty() {
    return bounty;
}

std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name;
    os << pirate.bounty;
    return os;
}
