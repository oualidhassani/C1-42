#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe 
{
    private:
        std::vector<int> vec;
    public:
        PmergeMe();    
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
        void addnum(int num);
        void sort(std::vector<int> &vec);
        std::vector<int> &getvec();
        void Step2(std::vector<int> &vec);


};










#endif