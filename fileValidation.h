#ifndef FILEVALIDATION_H_INCLUDED
#define FILEVALIDATION_H_INCLUDED
#include"fileHandler.h"
/**
 * @brief Checks if the String/Line contains the essential char to proceed
 * @param line The line that will go through validation
 *
 * Checks the Line by locating 2[/] 1[:] 1 [ ] and at least 1 [,].
 *
 * @return bool representing if that line is valid or not.
 */
bool softValidation(const std::string &line);
/**
 * @brief Scans a string vector for any invalid strings
 * @param stringVec String Vector that contains the segmented row
 *
 * Checks by converting each segment to a float, if an error occurs
 * Then the row is invalid
 *
 * @return bool representing if the stringVec does not have any Invalid Segments
 */
bool hardValidation(const Vector<std::string> &stringVec);


#endif // FILEVALIDATION_H_INCLUDED
