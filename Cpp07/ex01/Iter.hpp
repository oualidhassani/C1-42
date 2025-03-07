#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T>

void Iter(T *arr, int len, void (*F)(T &))
{
    if(arr == NULL || F == NULL)
        return ;
    for(int i = 0; len >  i; i++)
    {
        F(arr[i]);
    }
}

template <typename T>
void printElement(T &element)
{
    std::cout << element << std::endl;
}

#endif