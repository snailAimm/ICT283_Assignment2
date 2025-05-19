#include"math.h"
#include<cmath>

float findPositiveMean(const Vector<float> &dataArray){
    float mean = 0;
    int denominator = 0;

    if(dataArray.getSize() > 0)
    {
        for(int i = 0; i < dataArray.getSize(); i++)
        {
            if(dataArray[i] >= 0)
            {
                mean += dataArray[i];
                denominator++;
            }

        }
        mean/=denominator;
        return mean;
    }
    return -1;
}

float findPositiveStandardDeviation(const Vector<float> &dataArray, float mean){
    float variance = 0;
    float standardDeviation = 0;
    float sum = 0;
    int denominator = 0;

    if(dataArray.getSize() > 0)
    {
        for(int i = 0; i < dataArray.getSize(); i++)
        {
            if(dataArray[i] >= 0)
            {
                sum += (dataArray[i] - mean) * (dataArray[i] - mean);
                denominator++;
            }
        }
        variance = (1.0f/(denominator-1)) * sum;
        standardDeviation = sqrt(variance);
        return standardDeviation;
    }
    return -1;
}

float calculateSPCC(Vector<float> &vecOne, Vector<float> &vecTwo)
{
    float meanOne, meanTwo,numerator = 0, denominator = 0, x = 0, y = 0, sdOne, sdTwo;
    meanOne = findPositiveMean(vecOne);
    meanTwo = findPositiveMean(vecTwo);
    sdOne = findPositiveStandardDeviation(vecOne, meanOne);
    sdTwo = findPositiveStandardDeviation(vecTwo, meanTwo);
    //Assuming they have the same amount.. [WHICH THEY SHOULD.]
    for(int i = 0; i < vecOne.getSize(); i++)
    {
        x = (vecOne[i] - meanOne);
        y = (vecTwo[i] - meanTwo);
        numerator += (x*y);
    }
    denominator = ((vecOne.getSize() - 1) * sdOne * sdTwo);
    return numerator/denominator;
}
