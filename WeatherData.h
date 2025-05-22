#ifndef WEATHERDATA_H_INCLUDED
#define WEATHERDATA_H_INCLUDED
#include"Vector.h"

/**
 * @struct WeatherLogEntry
 * @brief Struct that contains the Weather's Data in one "Type"
 *
 *
 *
 * @author Ken Giron
 * @version 02
 * @date 15/04/2025 Ken Giron, Started
 *
 *
 * @todo NA
 *
 * @bug My program has no bugs.
 */

typedef struct
{
    Date d; ///Date of when the info was taken
    Time t; ///Time of when info was taken
    float speed; ///Wind Speed (m/s)
    float temperature; ///Ambient Air Temperature (Celsius)
    float solarRadiation; ///Solar Radiation (w/m^2)
} WeatherLogEntry;

typedef Vector<WeatherLogEntry> WeatherLogType; //WindlogType is realised Vector Type
//“Hey compiler, whenever I write WindlogType, I actually mean Vector<WindRecType>.”



#endif // WEATHERDATA_H_INCLUDED
