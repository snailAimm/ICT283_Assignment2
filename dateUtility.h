#ifndef DATEUTILITY_H_INCLUDED
#define DATEUTILITY_H_INCLUDED
#include "DATE.h"

/**
 *@file dateUtility.h
 *@brief Utility Functions for Class Date
 *
 * @author Ken Giron
 * @version 01
 * @date 18/04/2025 Ken Giron, Finished
 *
 *
 * @todo Make It Work for Other Formats
 *
 * @bug None
 */
//----------------------------------------------------------------------
/**
    * @brief  Turns Numbers 1-12 to their restrospective Months
    * @param numInput The number that will turn into a word
    *
    * Turns the corresponding Month's Number and
    * Returns the Month's String
    *
    * @return a constant string that represents the Month
    */
const std::string turnMonthIntToWord(int numInput);


#endif // DATEUTILITY_H_INCLUDED
