#include "menuView.h"
#include <iostream>
#include <string>

void outputRadiationKiloWat(float output)
{
     if(output > 0)
     {
         printf("%.1f", output);
         std::cout << " kWh/m^2";
     }
     else
     {
        std::cout << " No Data";
     }
}

void outputMeanSD(float mean, float sd)
{
    if(sd > 0)
    {
        std::cout << "Average: ";
        printf("%.1f", mean);
        std::cout << " Sample Standard Deviation: ";
        printf("%.1f", sd);
    }
    else
    {
        std::cout << "No Data";
    }
}

int validateUserInput()
{
    std::string inputStr;
    int input = 0;

    while(!isValidFloat(inputStr))
    {
        std::getline(std::cin, inputStr);
        if(!isValidFloat(inputStr))
        {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }
    input = std::stoi(inputStr);

    return input;
}

void outputFullDataFile(std::string month, float speedMean, float speedSD, float tempMean, float tempSD, float totalSolarRadiationKW, std::ofstream &os)
{
    os << month << ",";
    if(speedSD <= 0 && tempSD <= 0 && totalSolarRadiationKW <= 0)
    {
         os << "No Data";
    }
    else
    {
        if (speedSD >= 0)
        {
            os  << speedMean << "(" << speedSD << "),";
        }
        else
        {
            os  << ",";
        }
        if (tempSD >= 0)
        {
            os << tempMean << "(" << tempSD << "),";
        }
        else
        {
            os << ",";
        }
        if (totalSolarRadiationKW > 0)
        {
            os << totalSolarRadiationKW;
        }
    }
    os << '\n';

}

void printMenu()
{
    std::cout << "[1] Find wind speed average and standard deviation" << '\n';
    std::cout << "[2] Find monthly air temperature average and standard deviation in a year" << '\n';
    std::cout << "[3] Find monthly total solar radiation (kWh/m^2) in a year" << '\n';
    std::cout << "[4] Output weather data file" << '\n';
    std::cout << "[5] Exit Program" << '\n';
}
