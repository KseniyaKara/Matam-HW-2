
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    unsigned int bounty = 0;

public:
    Pirate(const string& name);

    Pirate(const string& name, unsigned int bounty);

    Pirate() = default;

    ~Pirate() = default;

    void setName(const string& name);

    string getName();

    void setBounty(const unsigned int& bounty);

    unsigned int getBounty();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);

};
