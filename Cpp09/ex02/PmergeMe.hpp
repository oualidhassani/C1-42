#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>

class PmergeMe 
{
    private:
        std::vector<int> vec;
    public:
        PmergeMe();    
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
};










#endif