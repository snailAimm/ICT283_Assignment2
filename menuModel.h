#ifndef MENUMODEL_H_INCLUDED
#define MENUMODEL_H_INCLUDED
//Logic
#include "math.h"
#include "DATE.h"
#include "TIME.h"
#include "vectorUtility.h"
#include "dateUtility.h"
#include "SensorColumnInfo.h"

/**
 *@file menuModel.h
 *@brief Manages the Logic of the Menus
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
 * @brief Converts the solar radiation vector (w/m^2) to (kWh/m^2)
 * @param solarRadiationVec Vector that contains the solarRadiation
 *
 * Converts the solar radiation (w/m^2) to (kWh/m^2) by dividing the original by 6000.
 *
 *
 * @return a float that represents the solar radiation in (kWh/m^2)
 */
float radiationKiloWatSum(const Vector<float> &solarRadiationVec);
/**
 * @brief Filters weatherVec a month within a year of it's data and stores it to floatVec
 * @param year The specific year
 * @param month The specific month
 * @param floatVec The Vector where the data will be transfered to
 * @param weatherVec Vector where the data will be from
 * @param menu Selection of which "Data" to process.
 *
 * Filters the data[See Enum] and stores it within floatVec. The Filter is
 * one month within a year.
 *
 * @return void
 */
void filterVecByYearMonth(int year, int month, Vector<float> &floatVec, Map<int, WeatherLogType> &weatherMap, int menu);
/**
 * @brief Adds up all the solarRadiation after conversion and returns the total
 * @param year The specific year
 * @param month The specific month
 * @param dataVec The Vector where the data will be transfered to
 * @param weatherVec Vector where the data will be from
 *
 * First Filters the Solar Radiation, then converts it then adds it to the total.
 *
 *
 * @return a float representing the total solar radiation within a month in (kWh/m^2)
 */
float processTotalSolarRadiation(int year, int month, Vector<float> &dataVec, Map<int, WeatherLogType> &weatherMap);
#endif // MENUMODEL_H_INCLUDED
