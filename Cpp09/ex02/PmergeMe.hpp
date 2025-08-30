#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <sys/time.h>
#include <deque>
#include <algorithm>

class PmergeMe 
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();    
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
        void addnum(int num);
        void sort(std::vector<int> &vec);
        std::vector<int> &getvec();
        std::deque<int> &getdeq();

        void Step2(std::vector<int> &vec);
        void sort_deq(std::deque<int> &deq);


        
};










#endif