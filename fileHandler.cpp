#include"fileHandler.h"
#include<iostream>
#include <fstream>
#include <sstream>

bool dataEngine(Map<int, WeatherLogType> &weatherMap, const BST<std::string> &dataFiles, BST<int> &yearBST)
{
    bstCollector<std::string> collector;
    dataFiles.InOrderTraversal(bstCollector<std::string>::funcPtr);
    SensorColumnInfo sCI;
    for(int i = 0; i < collector.getSize(); i++)
    {
        mainDataLoader(weatherMap, collector[i], sCI, yearBST);
    }
    //mainDataLoader(weatherVec, [Placeholder], sCI);
}

bool mainDataLoader(Map<int, WeatherLogType> &weatherMap, const std::string &dataFileLocation, SensorColumnInfo &sCI, BST<int> &yearBST) //This is for Each File.
{
    std::ifstream dataFile(dataFileLocation);

    WeatherLogEntry weatherEntry;
    std::string line;
    int currentYear = 0;

    if(!dataFile)
    {
        std::cout << ("Could not Find Data File");
        return false;
    }
    readSensorFile(sCI);
    std::getline(dataFile,line);
    assignLocations(sCI, line);

    while(std::getline(dataFile, line))
    {
        if(softValidation(line))
        {
            Vector<std::string> tokenisedLine;
            lineSegmentation(line, tokenisedLine);
            if(hardValidation(tokenisedLine))
            {
                parseHandler(tokenisedLine, weatherEntry, sCI);
                addToMap(weatherEntry, weatherMap);
                addToYearBST(yearBST, weatherEntry);
            }
        }
    }
    return true;
}

void readDataSources(const std::string &dataSourceLocation, BST<std::string> &dataFilePaths)
{
    std::string dataFileLocation = "";
    std::ifstream dataSourceFile(dataSourceLocation);
    if(!dataSourceFile)
    {
        std::cout << "Could not Find data_source.txt File" << '\n';
    }
    while(std::getline(dataSourceFile, dataFileLocation))
    {
        dataFileLocation = "data/" + dataFileLocation;
        dataFilePaths.Insert(dataFileLocation);
    }
}

void readSensorFile(SensorColumnInfo &sCI)
{
    std::ifstream sensorCodeFile("sensorNameCodes.csv");
    if(!sensorCodeFile)
    {
         std::cout << ("Could not Find SensorCode File");
    }
    std::string line, dummyStr;
    int index = 0;
    getline(sensorCodeFile, line); //Skip First Line [Info]
    while(getline(sensorCodeFile, line))
    {
        std::stringstream stream(line);
        getline(stream, dummyStr, ',');
        getline(stream, sCI.sensorCodes[index]);
        index++;
    }
}

void assignLocations(SensorColumnInfo &sCI, const std::string &line)
{
    const int arrayLength = sizeof(sCI.locations) / sizeof(sCI.locations[0]);
    std::string sensorStr;
    int columnIndex = 0;

    std::stringstream stream(line);
    while(getline(stream, sensorStr, ',' ))
    {
        for(int i = 0; i < arrayLength; i++)
        {
            if(sensorStr == sCI.sensorCodes[i])
            {
                sCI.locations[i] = columnIndex;
            }
        }
        columnIndex++;
    }
}

void lineSegmentation(const std::string &line, Vector<std::string> &stringVec)
{
    std::stringstream rawData(line);
    std::string segment;

    while(getline(rawData, segment, ','))
    {
        placeholderLocator(segment);
        stringVec.append(segment);
    }

}

void placeholderLocator(std::string &segment)
{
    std::string invalidStr[6] = {"NA", "invalid", "Invalid", "Unknown", " ", "offline"};
    for(int i = 0; i < sizeof(invalidStr)/sizeof(invalidStr[0]); i++)
    {
        if(segment == invalidStr[i])
        {
            segment = "-1";
            std::cout << "PlaceHolder Located." <<'\n';
        }
    }
}


int stringToInt(std::string sTR)
{
    int output = 0;
    output = std::stoi(sTR);
    return output;
}


float stringToFloat(std::string sTR)
{
    float output = 0;
    output = std::stof(sTR);
    return output;
}

void addToMap(WeatherLogEntry &entry, Map<int, WeatherLogType> &weatherMap)
{
    //GENIUDISDI GENIUS! If its empty it would just create it.
    int currentYear = entry.d.getYear();
    weatherMap[currentYear].append(entry);
}
void addToYearBST(BST<int> &yearBST, WeatherLogEntry &entry)
{
    int currentYear = entry.d.getYear();
    yearBST.Insert(currentYear);
}




