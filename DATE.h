#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string.h>
#include<sstream>
#include<iostream>

//------------------------------------------------------------------


	/**
	 * @class Date
	 * @brief  Manages the main Dates, like Day, Month and Year.
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

class Date{
public:
    /**
		 * @brief  Getter Function for the Variable Day
		 *
		 * This function returns the day for usage.
		 *
		 * @return int [The data for day]
		 */
    int getDay() const;

    /**
		 * @brief  Getter Function for the Variable Month
		 *
		 * This function returns the month for usage.
		 *
		 * @return int [The data for month]
		 */
    int getMonth() const;

    /**
		 * @brief  Getter Function for the Variable Year
		 *
		 * This function returns the year for usage.
		 *
		 * @return int [The data for year]
		 */
    int getYear() const;

    /**
		 * @brief  Setter Function for the Variable Day
		 * @param newDay = The new value that will be stored in day.
		 *
		 * This function will overwrite the value of Day with newDay
		 *
		 * @return void
		 */
    void setDay(int newDay);

    /**
		 * @brief  Setter Function for the Variable Month
		 * @param newMonth = The new value that will be stored in month.
		 *
		 * This function will overwrite the value of Month with newMonth
		 *
		 * @return void
		 */
    void setMonth(int newMonth);

    /**
		 * @brief  Setter Function for the Variable Year
		 * @param newYear = The new value that will be stored in year.
		 *
		 * This function will overwrite the value of Day with newYear
		 *
		 * @return void
		 */
    void setYear(int newYear);
    /**
		 * @brief Turns the Number of the Month into the word, and returns the word
		 * @param numInput = Numerical representation of a month
		 *
		 * This function will return the month's word corresponding to their number.
		 *Eg. [9 -> September]
		 *
		 * @return monthStr - The word for the month
		 */




private:
    int day;///The Day of the Date
    int month;///The Month of the Date
    int year;///The Year of the Date






};

#endif // DATE_H_INCLUDED
