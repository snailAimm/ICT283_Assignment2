#include <iostream>
#include "DATE.h"
#include "TIME.h"
#include "math.h"
#include "Vector.h"
#include"fileHandler.h"
#include "menuManager.h"

//Author Ken Giron
//Main File for Lab 8 Ex4
//Date Finished 4/19/2025
//Date Updated 5/1/2025

int main()
{
    Map<int, WeatherLogType> weatherMap;
    Vector<int> yearVec;
    const std::string input = "data/data_source.txt";
    mainMenu(weatherMap, yearVec, input);

    return 0;
}

