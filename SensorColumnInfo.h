#ifndef SENSORCOLUMNINFO_H_INCLUDED
#define SENSORCOLUMNINFO_H_INCLUDED

//-----------------------------------
/**
 * @struct SensorColumnInfo
 * @brief Manages the data file's Column Orientation and Sensor Codes
 *
 *
 *
 * @author Ken Giron
 * @version 01
 * @date 18/04/2025 Ken Giron, Started
 *
 *
 * @todo NA
 *
 * @bug My program has no bugs.
 */

/**
* @enum dataMenu
* @brief Stores the Data Names for different variation of functions
*
*/
enum dataWords
{
    DATE = 0,               /**< Date Setting*/
    SPEED = 1,              /**< Wind Speed Setting*/
    SOLAR_RADIATION = 2,    /**< Solar Radiation Setting*/
    TEMPERATURE = 3,        /**< Ambient Air Temperature Setting*/
};

typedef struct
{
    std::string sensorCodes[4]; ///The Sensor Codes for each Info
    int locations[4]; ///The Index within the file, the data's column
    //ORDER FOR BOTH ARRAYS
    //DATE
    //WIND SPEED
    //SOLAR RADIATION
    //TEMPERATURE
} SensorColumnInfo;


#endif // SENSORCOLUMNINFO_H_INCLUDED
