#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED
#include"fileHandler.h"
#include"Vector.h"

/**
 *@file math.h
 *@brief Container for Math Related Functions
 *
 * @author Ken Giron
 * @version 02
 * @date 19/04/2025 Ken Giron, Finished
 *
 *
 * @todo Perhaps Add Negative Versions
 *
 * @bug None
 */
 //----------------------------------------------------------------------

/**
 * @brief  Calculates the Mean With Only Positive Numbers
 * @param dataArray The Array that the function will get all the numbers from
 *
 * This function will only consider numbers [>0] it will
 * ignore any negative numbers in the calculations.
 *
 * @return A float representing the Mean.
 */
float findPositiveMean(const Vector<float> &dataArray);
/**
 * @brief  Calculates the Standard Deviation With Only Positive Numbers
 * @param dataArray The Array that the function will get all the numbers from
 * @param mean The calculated mean used for the calculations.
 *
 * This function will only consider numbers [>0] it will
 * ignore any negative numbers in the calculations.
 *
 * @return A float representing the Standard Deviation.
 */
float findPositiveStandardDeviation(const Vector<float> &dataArray, float mean);
float calculateSPCC(Vector<float> &vecOne, Vector<float> &vecTwo);


#endif // MATH_H_INCLUDED
