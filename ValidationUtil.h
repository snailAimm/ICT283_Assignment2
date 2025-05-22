#ifndef VALIDATIONUTIL_H_INCLUDED
#define VALIDATIONUTIL_H_INCLUDED
#include<string>
/**
 * @brief Checks if a string is okay to convert into a float
 * @param sTR The string where we check if its valid for float converting
 *
 *
 * @return true if it can be converted, false if it can't
 */
bool isValidFloat(const std::string &sTR);

#endif // VALIDATIONUTIL_H_INCLUDED
