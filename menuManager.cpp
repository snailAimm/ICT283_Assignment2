#include "menuManager.h"
#include <iomanip>
void mainMenu(Map<int, WeatherLogType> &weatherMap, BST<int> &yearBST, const std::string inputFileLocation)
{
    BST<std::string> dataFilesBST;
    std::string fileName = "";
    int userInput, userYear, userMonth;
    bool isLooping = true;
    SensorColumnInfo sCI;
    bstCollector<int> yearCollector;
    //------------------------------------------------------
    readDataSources(inputFileLocation, dataFilesBST);
    if(dataEngine(weatherMap, dataFilesBST, yearBST))
    {
        yearBST.InOrderTraversal(bstCollector<int>::funcPtr);
        while(isLooping)
        {
        printMenu();
        std::cout << "[Please Select an Option]" << '\n';
        userInput = validateUserInput();
        switch(userInput)
            {
        case 1:
            std::cout << "Enter a Year: ";
            userYear = validateUserInput();
            std::cout << "Enter a Month(number): ";
            userMonth = validateUserInput();
            printYearMonthWindSpeed(weatherMap, userYear, userMonth);
            break;
        case 2:
            std::cout << "Enter a Year: ";
            userYear = validateUserInput();
            printMonthlyAirTemperature(weatherMap, userYear);
            break;
        case 3:
            std::cout << "Enter a Month: ";
            userMonth = validateUserInput();
            printMonthSPCC(weatherMap, userMonth, yearCollector);
            break;
        case 4:
            std::cout << "Enter a Year: ";
            userYear = validateUserInput();
            fileFullWeatherDataOutput(weatherMap, userYear);
            break;
        case 5:
            std::cout << "Exiting";
            isLooping = false;
            break;
            }
        }
    }
}
void printYearMonthWindSpeed(Map<int, WeatherLogType> &weatherMap, int userYear, int userMonth)
{ //Average wind speed, and sample Standard Deviation, given in a month and year. print Screen
    Vector<float> speedVec;
    float mean = 0, sd = 0;
    filterMapByYearMonth(userYear, userMonth, speedVec, weatherMap, SPEED);
    mean = findPositiveMean(speedVec);
    sd = findPositiveStandardDeviation(speedVec, mean);
    std::cout << "Wind Speed Data For " << '\n' << turnMonthIntToWord(userMonth) << " " << userYear << ":" << '\n';
    outputMeanSD(mean*3.6f, sd*3.6f);
    std::cout << '\n' << '\n';
}

void printMonthlyAirTemperature(Map<int, WeatherLogType> &weatherMap, int userYear)
{
    Vector<float> airTempVec;
    const int totalMonths = 12;
    float mean = 0, sd = 0;

    std::cout << "Ambient Air Temperature (Celsius) For " << userYear << '\n';
    for(int month  = 1; month <= totalMonths; month++)
    {
        filterMapByYearMonth(userYear, month, airTempVec, weatherMap, TEMPERATURE);
        mean = findPositiveMean(airTempVec);
        sd = findPositiveStandardDeviation(airTempVec, mean);
        std::cout << std::left << std::setw(10) << turnMonthIntToWord(month);
        outputMeanSD(mean, sd);
        std::cout << '\n';
    }
}

void  printMonthSPCC(Map<int, WeatherLogType> &weatherMap, int userMonth, bstCollector<int> &yearCollector)
{ //yearVec is here so I can grab each month lol
    if(userMonth > 12 || userMonth < 1)
    {
        std::cout << "Invalid Month" << '\n';
        return;
    }
    Vector<float> ambientTempVec, solarRadiationVec, windSpeedVec;
    float rWindSpeed_AmbientTemp, rWindSpeed_SolarRadiation, rAmbientTemp_SolarRadiation;
    for(int i = 0; i < yearCollector.getSize(); i++)
    {
        sPCCDataFiltering(yearCollector[i], userMonth, windSpeedVec, weatherMap, SPEED);
        sPCCDataFiltering(yearCollector[i], userMonth, ambientTempVec, weatherMap, TEMPERATURE);
        sPCCDataFiltering(yearCollector[i], userMonth, solarRadiationVec, weatherMap, SOLAR_RADIATION);
    }
    rWindSpeed_AmbientTemp = calculateSPCC(windSpeedVec, ambientTempVec);
    rWindSpeed_SolarRadiation = calculateSPCC(windSpeedVec, solarRadiationVec);
    rAmbientTemp_SolarRadiation = calculateSPCC(ambientTempVec, solarRadiationVec);

    std::cout << "Sample Pearson Correlation Coefficient: " << turnMonthIntToWord(userMonth)<<'\n';
    std::cout <<"S_T  "<< rWindSpeed_AmbientTemp <<'\n';
    std::cout <<"S_SR "<< rWindSpeed_SolarRadiation <<'\n';
    std::cout <<"T_SR "<< rAmbientTemp_SolarRadiation<<'\n';

}

void fileFullWeatherDataOutput(Map<int, WeatherLogType> &weatherMap, int userYear)
{
    std::ofstream outFile("WindTempSolar.csv");
    const int totalMonths = 12;

    float totalSolarRadiationKiloWat = 0;
    float speedMean = 0, speedSD = 0, speedMAD = 0,temperatureMean = 0, temperatureSD = 0, temperatureMAD = 0;
    outFile << userYear << '\n';
    for(int month  = 1; month <= totalMonths; month++)
    {
        Vector<float> solarRadiationVec, windSpeedVec, airTempVec;;
        filterMapByYearMonth(userYear, month, windSpeedVec, weatherMap, SPEED);
        filterMapByYearMonth(userYear, month, airTempVec, weatherMap, TEMPERATURE);

        speedMean = findPositiveMean(windSpeedVec);
        speedSD = findPositiveStandardDeviation(windSpeedVec, speedMean);
        speedMAD = calculateMAD(windSpeedVec, speedMean);

        temperatureMean = findPositiveMean(airTempVec);
        temperatureSD = findPositiveStandardDeviation(airTempVec, temperatureMean);
        temperatureMAD = calculateMAD(airTempVec, temperatureMean);

        totalSolarRadiationKiloWat = processTotalSolarRadiation(userYear, month, solarRadiationVec, weatherMap);
        outputFullDataFile(turnMonthIntToWord(month), speedSD*3.6f, speedMAD*3.6f, temperatureSD, temperatureMAD , totalSolarRadiationKiloWat, outFile);
    }
    outFile.close();
    std::cout << "Output File Created " << '\n';
}


