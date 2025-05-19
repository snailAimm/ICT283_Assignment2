#include "dateUtility.h"
#include <string>
#include <iostream>

const std::string turnMonthIntToWord(int numInput)
{
    const std::string months[12] ={"January","February", "March", "April", "May", "June", "July","August","September"
    ,"October", "November", "December"};

    return(months[numInput-1]); //-1 becuse indexes start at 0
}
