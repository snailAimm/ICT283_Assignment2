#include "menuModel.h"
#include <iostream>
#include <string>
float radiationKiloWatSum(const Vector<float> &solarRadiationVec)
{
    float sum = 0, currentSolarRadiation = 0;
    if(solarRadiationVec.getSize() > 0)
    {
        for(int i = 0; i < solarRadiationVec.getSize(); i++)
        {
            currentSolarRadiation += solarRadiationVec[i];
            currentSolarRadiation /= 6000;
            sum+=currentSolarRadiation;
        }
    }
    else
    {
        return -1;
    }

    return sum;

}


void filterVecByYearMonth(int year, int month, Vector<float> &floatVec, Map<int, WeatherLogType> &weatherMap, int menu)
{
    if(weatherMap.Search(year))
    {
        for(int i = 0; i < weatherMap[year].getSize(); i++)
        {
            if(month == weatherMap[year][i].d.getMonth())
            {
                switch(menu)
                {
                case SPEED:
                    storeToFloatVector(floatVec, weatherMap[year][i].speed);
                    break;
                case SOLAR_RADIATION:
                   // if(weatherMap[year][i].solarRadiation > 100)
                   // { //Removes Night, and Also was in the Instructions.
                    storeToFloatVector(floatVec, weatherMap[year][i].solarRadiation);
                    //}
                    break;
                case TEMPERATURE:
                    storeToFloatVector(floatVec, weatherMap[year][i].temperature);
                    break;
                }

            }
        }
    }

}

float processTotalSolarRadiation(int year, int month, Vector<float> &dataVec, Map<int, WeatherLogType> &weatherMap)
{
    float totalSolarRadiationKiloWat = 0;
    filterVecByYearMonth(year, month, dataVec, weatherMap, SOLAR_RADIATION);
    totalSolarRadiationKiloWat = radiationKiloWatSum(dataVec);
    return totalSolarRadiationKiloWat;
}



