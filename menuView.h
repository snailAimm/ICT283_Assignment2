#ifndef MENUVIEW_H_INCLUDED
#define MENUVIEW_H_INCLUDED
#include"ValidationUtil.h"
#include <fstream>

/**
 *@file menuView.h
 *@brief Manages the IO of the Menus
 *
 *
 * @author Ken Giron
 * @version 02
 * @date 19/04/2025 Ken Giron, Finished
 *
 *
 * @todo [NA]
 *
 * @bug None
 */
//----------------------------------------------------------------------
/**
 * @brief Asks the user for an input and until it is a valid input it will keep asking
 *
 * @return an int that represents a valid user input
 */
int validateUserInput();
/**
 * @brief Prints the Mean and Standard Deviation, Handles if there is no data
 * @param mean
 * @param sd
 *
 * Checks if both the mean and standard deviation are valid outputs
 * If not, then print No Data
 *
 *
 * @return void
 */
void outputMeanSD(float mean, float sd);
/**
 * @brief Prints Radiation in KiloWat, Handles if there is no data
 * @param output a float that represents the solar radiation in (kWh/m^2)
 *
 * Checks if both the output is a valid output
 * If not, then print No Data
 *
 *
 * @return void
 */
void outputRadiationKiloWat(float output);
/**
 * @brief Outputs all the Parametres into a File
 * @param month The month the data is stored in
 * @param speedMean the wind speed's mean
 * @param speedSD The wind speed's standard deviation
 * @param tempMean The ambient air temperature's mean
 * @param tempSD The ambient air temperature's standard deviation
 * @param totalSolarRadiationKW The total solar radiation in (kWh/m^2)
 * @param os The Output File
 *
 * Checks if any of the values are valid, if there are any invalid values
 * it would be handled. Printing an Empty Space
 *
 *
 * @return void
 */
void outputFullDataFile(std::string month, float speedMean, float speedSD, float tempMean, float tempSD, float totalSolarRadiationKW, std::ofstream &os);
/**
 * @brief Prints the program's Menu
 *
 * @return void
 */
void printMenu();
#endif // MENUVIEW_H_INCLUDED
