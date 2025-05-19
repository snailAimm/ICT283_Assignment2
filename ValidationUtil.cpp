#include<iostream>
#include"ValidationUtil.h"
#include <sstream>

bool isValidFloat(const std::string &sTR)
{
    std::stringstream ss(sTR);
    float value;
    char leftover; //Checks for left over values after the digit

    return ss >> value && !(ss >> leftover); //turns ss into a float
    //ss >> value extract a float from the beginning of the strig
    //ss >> leftover pulls any remaining character.
}

bool isValidInt(const std::string &sTR)
{
    std::stringstream ss(sTR);
    int value;
    char leftover; //Checks for left over values after the digit

    return ss >> value && !(ss >> leftover); //turns ss into a float
    //ss >> value extract a float from the beginning of the strig
    //ss >> leftover pulls any remaining character.
}

