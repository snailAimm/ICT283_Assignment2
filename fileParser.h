#ifndef FILEPARSER_H_INCLUDED
#define FILEPARSER_H_INCLUDED
#include"fileHandler.h"
/**
 *@file fileParser.h
 *@brief File that holds functions that helps parsing
 *
 *
 * @author Ken Giron
 * @date 5/16/2025
 * @version 01
 *
 *
 * @todo [NA]
 *
 * @bug None
 */
//-----------------------------------------------------------------
/**
 * @brief Handles changing the data from string type to their required types (int, float)
 * @param tokenisedLine the segregated line in a Vector so SCI can access the indexes
 * @param entry the WeatherLogEntry entry it will be saved to.
 * @param sCI the SensorColumnInfo that identifies which column S,T,SR are.
 *
 * Converts the tokenisedLine into a weatherLogEntry
 *
 * @return void
 */
void parseHandler(const Vector<std::string> &tokenisedLine, WeatherLogEntry &entry, const SensorColumnInfo &sCI);
/**
 * @brief Parses a Date Segment into integers
 * @param entryDate The weather entry's Date Variable
 * @param entryTime The weather entry's Time Variable
 * @param segment A segment of a line
 *
 * Converts the segment into Integer Values that are then stored within
 * entryDate and entryTime
 *
 * @return void
 */
void parseDateTime(Date &entryDate, Time &entryTime, const std::string segment);

#endif // FILEPARSER_H_INCLUDED
