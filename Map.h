#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include<map>

template<class T, class V>
class Map{
public:
    Map();
    ~Map();
    Map(const Map &other);
    Map<T, V>& operator=(const Map<T, V>& other);
    V& operator[](const T& key);
    const V& operator[](const T& key) const;
    void Insert(const T &key, const V &value);
    bool Search(const T &key);
    int getSize();



private:
    std::map<T, V> start;
};

template<class T, class V>
Map<T, V>::Map()
{
    start = std::map<T, V>();
}
template<class T, class V>
Map<T, V>::~Map()
{

}
template<class T, class V>
Map<T, V>::Map(const Map &other)
{
    start = other.start;
}
template<class T, class V>
Map<T, V>& Map<T, V>::operator=(const Map &other)
{
    if(this != &other)
    {
        start = other.start;
    }
    return *this;
}
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
const V& Map<T, V>::operator[](const T &key) const
{
    return start[key];
}
template<class T, class V>
int Map<T, V>::getSize()
{
    return start.size();
}
template<class T, class V>
bool Map<T, V>::Search(const T &key)
{
    return start.find(key) != start.end();
}



#endif // MAP_H_INCLUDED
