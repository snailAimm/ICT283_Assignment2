#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <vector>
#include <cassert>
//-------------------------------------
//------------------------------------------------------------------


/**
 * @class Vector
 * @brief  A Temu-version of std::vector
 *
 *
 *
 * @author Ken Giron
 * @version 02
 * @date 5/4/2025 Ken Giron, Started
 * @date 5/18/2025 Ken Giron, Removed Clear.
 *
 * @todo Documentation
 *
 * @bug My program has no bugs.
 */

template <class T>
class Vector   // This is NOT the std::vector.
{
public:
    Vector();
    ~Vector();
    /**
     * @brief Add Data At the end of the Array
     * @param data = Data being added at the end
     *
     *
     *
     * @return void
     */
    void append(const T& data);
    /**
     * @brief Turns [] into like a Raw Array's []
     * @param index = index of an array
     *
     *
     *
     * @return returns a Template Object.
     */
    T& operator[](int index);
    /**
     * @brief Turns [] into like a Raw Array's []
     * @param index = index of an array
     *
     *
     *
     * @return returns a Template Object.
     */
    const  T& operator[](int index) const;
    /**
     * @brief  Getter for the Current Space in the Vector
     *
     * @return an integer representing the currentSpace
     */
    int getSize() const;
    /**
     * @brief  Copy Constructor
     * @param other A constant Vector where we copy the data from
     *
     * @return A Vector Constructor
     */
    Vector(const Vector& other);
    /**
    * @brief  Copy Assignment Operator
    	 * @param other A constant Vector where we copy the data from
    	 *
    	 * @return A new Vector with a copied data from the other Vector
    	 */
    Vector<T>& operator=(const Vector<T>& other);



private:
    std::vector<T> arrayVar;

    // fill in ..
};  // end of interface/declaration of the template class

//IMPLEMENTATION-------------------------------------------------
template <class T>
Vector<T>::Vector()
{
    arrayVar = std::vector<T>();
}

template <class T>
Vector<T>::~Vector()
{
    //Empty because std::vector will handle it
}

template <class T>
Vector<T>::Vector(const Vector& other)
{
    arrayVar = other.arrayVar;
}

template <class T>
void Vector<T>::append(const T&  data)
{
    arrayVar.push_back(data);
}


template<class T> //Allows Writing in Element
T& Vector<T>::operator[](int index)
{
    assert(index >= 0 && index < arrayVar.size() && "Index out of bounds");
    return arrayVar[index];

}

template <class T> //Allows Reading Only
const T& Vector<T>::operator[](int index) const
{
    assert(index >= 0 && index < arrayVar.size() && "Index out of bounds");
    return arrayVar[index];
}

template <class T>
int Vector<T>::getSize() const
{
    arrayVar.size();
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if(this != other) //if it's not equal then run.
    {
        arrayVar = other.arrayVar;
    }
    return *this;
}
#endif
