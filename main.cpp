#include <iostream>
#include "DATE.h"
#include "TIME.h"
#include "math.h"
#include "Vector.h"
#include"fileHandler.h"
#include "menuManager.h"

//Author Ken Giron
//Main File for Assignment 2
//Date Finished 4/19/2025
//Date Updated 5/1/2025
//Date Updated 5/19/2025
//Date Updated 5/22/2025

int main()
{
    Map<int, WeatherLogType> weatherMap;
    BST<int> yearBST;
    const std::string input = "data/data_source.txt";
    mainMenu(weatherMap, yearBST, input);

    return 0;
}

