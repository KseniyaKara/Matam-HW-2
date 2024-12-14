
#include "Pirate.h"


Pirate::Pirate(const string& name, DEVIL_FRUIT devilFruit): name(name), devilFruit(devilFruit) {}

Pirate::Pirate(const string& name, unsigned int bounty): name(name), bounty(bounty) {}

void Pirate::setName(const string& name){
    this->name = name;
}

std::string Pirate::getName(){
    return name;
}

void Pirate::setDevilFruit(DEVIL_FRUIT devilFruit){
    this->devilFruit = devilFruit;
}

void Pirate::setBounty(const unsigned int& bounty) {
    this->bounty = bounty;
}

unsigned int Pirate::getBounty() {
    return bounty;
}

DEVIL_FRUIT Pirate::getDevilFruit(){
    return devilFruit;
}


const char* const devilFruitNames[] = {
    "Gum Gum",
    "Smoke Smoke",
    "Flame Flame",
    "Rumble Rumble",
    "String String",
    "Ice Ice",
    "None"
};

std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")" << " " << pirate.bounty;
    return os;
}
