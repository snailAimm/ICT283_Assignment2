#include"fileParser.h"
void parseHandler(const Vector<std::string> &tokenisedLine, WeatherLogEntry &entry, const SensorColumnInfo &sCI)
{
    parseDateTime(entry.d, entry.t, tokenisedLine[sCI.locations[0]]);//This is so it follows wherever Date is.
    entry.speed = stringToFloat(tokenisedLine[sCI.locations[1]]);
    entry.solarRadiation = stringToFloat(tokenisedLine[sCI.locations[2]]);
    entry.temperature = stringToFloat(tokenisedLine[sCI.locations[3]]);
}

void parseDateTime(Date &entryDate, Time &entryTime, const std::string segment)
{
    //Format is 26/09/2005 9:30
    std::string hourStr, minStr, dayStr, monthStr, yearStr;
    std::stringstream stream(segment);

    getline(stream, dayStr, '/');
    getline(stream, monthStr, '/');
    getline(stream, yearStr, ' ');
    getline(stream, hourStr, ':');
    getline(stream, minStr);

    entryDate.setDay(stringToInt(dayStr));
    entryDate.setMonth(stringToInt(monthStr));
    entryDate.setYear(stringToInt(yearStr));
    entryTime.setHour(stringToInt(hourStr));
    entryTime.setMinute(stringToInt(minStr));
}
