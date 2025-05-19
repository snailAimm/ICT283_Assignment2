#ifndef FILEPARSER_H_INCLUDED
#define FILEPARSER_H_INCLUDED
#include"fileHandler.h"


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
/**
 * @brief Converts a String into an Int
 * @param sTR String that will be converted into an int
 *
 *
 *
 * @return an int that represents the string's number
 */


#endif // FILEPARSER_H_INCLUDED
