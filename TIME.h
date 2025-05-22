#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

/**
 * @class Time
 * @brief  Manages the main Time like Hour and Minutes
 *
 *
 *
 * @author Ken Giron
 * @version 01
 * @date 18/03/2025 Ken Giron, Started
 *
 *
 * @todo Documentation
 *
 * @bug My program has no bugs.
 */

class Time
{
public:

    /**
    	 * @brief  Getter Function for the Variable hour
    	 *
    	 * This function returns the hour for usage.
    	 *
    	 * @return int [The data for hour]
    	 */
    int getHour() const;
    /**
    	 * @brief  Getter Function for the Variable minute
    	 *
    	 * This function returns the minute for usage.
    	 *
    	 * @return int [The data for minute]
    	 */
    int getMinute() const;
    /**
     * @brief  Setter Function for the Variable hour
     * @param newHour = The new value that will be stored in hour.
     *
     * This function will overwrite the value of Day with newHour
     *
     * @return void
     */
    void setHour(int newHour);
    /**
    * @brief  Setter Function for the Variable minute
    * @param newMinute = The new value that will be stored in minute.
    *
    * This function will overwrite the value of Day with newMinute
    *
    * @return void
    */
    void setMinute(int newMinute);

private:
    int hour; ///Hour Variable
    int minute; ///Minute Variable

};

#endif // TIME_H_INCLUDED
