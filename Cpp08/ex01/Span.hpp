#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> veco;
    public:
        Span(unsigned int n);
        Span();
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
        void addNumber(int n);
        int longestSpan();
        int shortestSpan();
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};





#endif