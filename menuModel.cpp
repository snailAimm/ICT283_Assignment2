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
            if(solarRadiationVec[i] >= 100)
            {
                currentSolarRadiation += solarRadiationVec[i];
                currentSolarRadiation /= 6000;
                sum+=currentSolarRadiation;
            }
        }
    }
    else
    {
        return -1;
    }
    return sum;

}


void filterMapByYearMonth(int year, int month, Vector<float> &floatVec, Map<int, WeatherLogType> &weatherMap, int menu)
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
                   if(weatherMap[year][i].solarRadiation > 100)
                   {
                     storeToFloatVector(floatVec, weatherMap[year][i].solarRadiation);
                   }
                   // { //Removes Night, and Also was in the Instructions.

                    //}
                    break;
                case TEMPERATURE:
                    if(weatherMap[year][i].solarRadiation > 100)
                   {
                    storeToFloatVector(floatVec, weatherMap[year][i].temperature);
                   }

                    break;
                }

            }
        }
    }

}

float processTotalSolarRadiation(int year, int month, Vector<float> &dataVec, Map<int, WeatherLogType> &weatherMap)
{
    float totalSolarRadiationKiloWat = 0;
    filterMapByYearMonth(year, month, dataVec, weatherMap, SOLAR_RADIATION);
    totalSolarRadiationKiloWat = radiationKiloWatSum(dataVec);
    return totalSolarRadiationKiloWat;
}

void sPCCDataFiltering(int year, int month, Vector<float> &floatVec, Map<int, WeatherLogType> &weatherMap, int menu)
{
    if(weatherMap.Search(year))
    {
        for(int i = 0; i < weatherMap[year].getSize(); i++)
        {
            if(month == weatherMap[year][i].d.getMonth() && weatherMap[year][i].solarRadiation > 100)
            {
                switch(menu)
                {
                    case SPEED:
                        storeToFloatVector(floatVec, weatherMap[year][i].speed);
                        break;
                    case SOLAR_RADIATION:
                        storeToFloatVector(floatVec, weatherMap[year][i].solarRadiation);
                        break;
                    case TEMPERATURE:
                        storeToFloatVector(floatVec, weatherMap[year][i].temperature);
                        break;
                }
            }
        }
    }
}




