#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <class T> 
class Array
{
    private:
        T   *elements;
        int _size;
    public:
        Array() : elements(NULL) , _size(0) {};
        Array(unsigned int n) : elements(new T[n]) , _size(n) {};
        ~Array()
        { delete []elements;
            elements = NULL;
        };
        Array(const Array &other) : elements(new T[other._size]), _size(other._size)
        {
            for(int i = 0; i < _size; i++)
            {
                elements[i] = other.elements[i];
            }
        }
        Array &operator=(const Array &other)
        {
            if(this != &other)
            {
                delete [] elements;
                _size = other._size;
                elements = new T[_size];
                    for(int i = 0; _size > i; i++)
                {
                    elements[i] = other.elements[i];
                }
            }
            return *this;
        }
        T &operator [](int indx)
        {
            if(indx >= _size || indx < 0)
            {
                throw std::out_of_range("Index out of range");
            }
            return elements[indx];
        }
        int size() 
        {
            return _size;
        }
};

#endif
