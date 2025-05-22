#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED
#include"DATE.h"
#include"TIME.h"
#include"WeatherData.h"
#include"SensorColumnInfo.h"
#include"ValidationUtil.h"
#include"Map.h"
#include"fileParser.h"
#include"fileValidation.h"
#include"bstCollector.h"
#include"BST.h"

/**
 *@file fileHandler.h
 *@brief File that Contains Functions that supports Reading the data file
 *
 *
 * @author Ken Giron
 * @version 03
 *
 *
 * @todo [NA]
 *
 * @bug None
 */
//----------------------------------------------------------------------
bool dataEngine(Map<int, WeatherLogType> &weatherMap, const BST<std::string> &dataFiles, BST<int> &yearBST);
/**
 * @brief Handles the Orchestration of appending into a weatherVector and reading the dataFile
 * @param weatherVec The Weather Data's Vector
 * @param dataFileLocation The Location of the Data File
 *
 * This Function Uses the other functions in order to Append Entries into
 * weatherVec.
 *
 * @return void
 */
bool mainDataLoader(Map<int, WeatherLogType> &weatherMap, const std::string &dataFileLocation, SensorColumnInfo &sCI, BST<int> &yearBST);
/**
 * @brief Reads the dataSource File and Returns the Data File
 * @param dataSourceLocation The location of the dataSource File
 *
 *
 * @return A string that represents the location of the actual Data File
 */
void readDataSources(const std::string &dataSourceLocation, BST<std::string> &dataFilePaths);
/**
 * @brief Reads the SensorName File and stores it
 * @param sCI The struct where the SensorNames will be stored
 *
 * Locates "SensorNameCodes.csv" and Stores the SensorCodes
 *
 *
 * @return void
 */
void readSensorFile(SensorColumnInfo &sCI); //Updates SensorNames in SensorColumn Info
/**
 * @brief Locates where the needed data is located, and assigns the columns
 * @param sCI The struct where the index of columns will be stored
 * @param line The string that will be scanned
 *
 * Locates any of the Sensor Codes in line, and saves the column's index.
 *
 *
 * @return void
 */
void assignLocations(SensorColumnInfo &sCI, const std::string &line);
/**
 * @brief Segments a Line with Commas and Returns a String Vector
 * @param line The line that will be segmented
 * @param stringVec The stringVector that represents the Segmented Line
 *
 * Segments the line, and appends that into the stringVec.
 *
 *
 * @return void
 */
void lineSegmentation(const std::string &line, Vector<std::string> &stringVec);
/**
 * @brief Locates any placeholder data and replaces them
 * @param segment A segment of a line
 *
 * Checks if the segment is any of the placeholder values
 * Converting those to -1 for the System to ignore in calculations later on.
 *
 * @return void
 */
void placeholderLocator(std::string &segment);
/**
 * @brief Handler that parses values that are on their own
 * @param tokenisedLine A constant String Vector
 * @param entry The Weather Data Entry where the Parsed values will be stored
 * @param sCI A struct that contains information on the datafile's column and sensor codes.
 *
 *  The Function goes through the tokenisedLine and if any of the tokenised Line are within the location
 * Of any of the columns where WindSpeed, SolarRadiation and Temperature are located then Convert and Store.
 *
 * @return void
 */
int stringToInt(std::string sTR);
/**
 * @brief Converts a String into a Float
 * @param sTR String that will be converted into a float
 *
 *
 *
 * @return a float that represents the string's number
 */
float stringToFloat(std::string sTR);
/**
 * @brief Adds a Weather Log Entry, to its Map
 * @param entry The WeatherLogEntry (A Struct that contains all weather information)
 * @param weatherMap the Map that takes in an int key, and WeatherLogType (Vector of WeatherLogEntry) Values
 *
 *
 * @return void
 */
void addToMap(WeatherLogEntry &entry, Map<int, WeatherLogType> &weatherMap);
/**
 * @brief Adds a year into the BST
 * @param entry The WeatherLogEntry (A Struct that contains all weather information)
 * @param yearBST the Binary Search Tree that contains all the data's years.
 *
 *
 * @return void
 */
void addToYearBST(BST<int> &yearBST, WeatherLogEntry &entry);


#endif // FILEHANDLER_H_INCLUDED
