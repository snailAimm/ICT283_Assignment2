#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include<map>

/**
 * @class Map
 * @brief  A Wrapped Class of std::map
 *
 *
 *
 * @author Ken Giron
 * @version 01
 * @date 5/24/2025 Ken Giron, Started
 *
 * @todo [NA]
 *
 * @bug My program has no bugs.
 */


template<class T, class V>
class Map{
public:
/**
 * @brief Returns the value to its corresponding key
 * @param key, the key that will be searched for the value
 *
 *
 * @return the value will be returned
 */
    V& operator[](const T& key);
/**
 * @brief Inserts a key and a value to the map
 * @param key, the key that will be searched for the value
 * @param value, the value of the key.
 *
 * @return void
 */
    void Insert(const T &key, const V &value);
/**
 * @brief Searches the map if the key already exists
 * @param key, the key that will be searched if it exists
 *
 *
 * @return true if its found, false if it isnt
 */
    bool Search(const T &key);



private:
    std::map<T, V> start;
};

template<class T, class V>
void Map<T, V>::Insert(const T &key, const V &value)
{
    start.insert({key, value});
}
template<class T, class V>
V& Map<T, V>::operator[](const T &key)
{
    return start[key];
}
template<class T, class V>
bool Map<T, V>::Search(const T &key)
{
    return start.find(key) != start.end();
}



#endif // MAP_H_INCLUDED
