#ifndef BSTCOLLECTOR_H_INCLUDED
#define BSTCOLLECTOR_H_INCLUDED
#include <iostream>
#include "Vector.h"

/**
 * @class bstCollection
 * @brief  A class that uses function pointer to grab BST's value privately
 *
 *
 *
 * @author Ken Giron
 * @version 01
 * @date 5/20/2025 Ken Giron, Started
 *
 * @todo [NA]
 *
 * @bug My program has no bugs.
 */

template <class T>
class bstCollector
{
public:
    /**
     * @brief A static function that grabs the parameter data and keeps it
     * @param data, a variable that contains data.
     *
     *
     * @return void
     */
    static void funcPtr(T &data);
    /**
     * @brief A getter for the Size
     *
     *
     * @return an int representing the size of the vector
     */
    int getSize();
    /**
     * @brief An operator overload where it returns data to its corresponding index
     * @param index The index in the vector
     *
     *
     * @return The data/value the index holds
     */
    T &operator[](int index);
private:
    static int i; ///Size
    static Vector<T> vectorVar; ///Vector that holds the values

};

template<class T>
void bstCollector<T>::funcPtr(T &data)
{
    vectorVar.append(data);
    i++;
}
template<class T>
int bstCollector<T>::getSize()
{
    return i;
}
template<class T>
T& bstCollector<T>::operator[](int index)
{
    return vectorVar[index];
}

template<class T>
int bstCollector<T>::i = 0;
template<class T>
Vector<T> bstCollector<T>::vectorVar;
#endif // BSTCOLLECTOR_H_INCLUDED
