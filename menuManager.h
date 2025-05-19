#ifndef MENUMANAGER_H_INCLUDED
#define MENUMANAGER_H_INCLUDED

#include "menuView.h"
#include "menuModel.h"

/**
 *@file menuManager.h
 *@brief Manages the "Menus" of the Program.
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
 void mainMenu(Map<int, WeatherLogType> &weatherMap, Vector<int> yearVec, const std::string inputFileLocation);
/**
 * @brief Prints the Wind Speed Average and Standard Deviation within a selected year and month
 * @param weatherVec Vector where the data will be from
 * @param userYear The specific year user wants
 * @param userMonth The specific month user wants
 *
 * This Function will Calculate and Print the Wind Speed, Mean and Standard Deviation
 * Within the User's Year and Month
 *
 * @return void
 */
void printYearMonthWindSpeed(Map<int, WeatherLogType> &weatherMap, int userYear, int userMonth);
/**
 * @brief Prints the Air Temperature Average and Standard Deviation within a selected year for each month
 * @param weatherVec Vector where the data will be from
 * @param userYear The specific year user wants
 *
 * This Function will Calculate and Print the Wind Speed, Mean and Standard Deviation
 * Within the User's Year for each month of that year
 *
 * @return void
 */
void printMonthlyAirTemperature(Map<int, WeatherLogType> &weatherMap, int userYear);
/**
 * @brief Prints the total solar radiation in (kWh/m^2) within a selected year for each month
 * @param weatherVec Vector where the data will be from
 * @param userYear The specific year user wants
 *
 * This Function will Calculate and Print the total solar radiation in (kWh/m^2)
 * Within the User's Year for each month of that year
 *
 * @return void
 */
void printMonthSPCC(Map<int, WeatherLogType> &weatherMap, int userMonth, Vector<int> &yearVec);
/**
 * @brief Prints Mean and Standard Deviation of Wind Speed (km/h) and Air Temperature (Celsius) and the total solar radiation in (kWh/m^2) for the User's year for each month
 * @param weatherVec Vector where the data will be from
 * @param userYear The specific year user wants
 *
 * This Function will Calculate and Print Mean and Standard Deviation of Wind Speed (km/h), Air
 * Temperature(Celcius) and the total Solar Radiation (kWh/m^2)
 * Within the User's Year for each month of that year
 *
 * @return void
 */
void fileFullWeatherDataOutput(Map<int, WeatherLogType> &weatherMap, int userYear);





#endif // MENUMANAGER_H_INCLUDED
