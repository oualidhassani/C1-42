#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span() : _n(0)
{
}

Span::~Span()
{
}

Span::Span(const Span &other)
{
    this->_n = other._n;
}

Span& Span::operator=(const Span &other)
{
    if(this != &other)
        this->_n = other._n;
    
    return *this;
}

void Span::addNumber(int n)
{
    if(static_cast<int>(veco.size()) >= static_cast<int>(_n))
        throw std::runtime_error("there are already N elements ") ;
    veco.push_back(n);
}


int Span::longestSpan()
{
    int max;
    max = 0;
    if(veco.size() > 1)
    {
        sort(veco.begin(), veco.end());
         max = veco.back() - veco.front();
        return max;
        
    }
    else
        throw  std::logic_error("No span found ");

    return 0;
}


int Span::shortestSpan()
{
 
    if(veco.size() > 1)
    {
        sort(veco.begin(), veco.end());

        int min = veco[1] - veco[0];

        for(int i = 1 ; i < static_cast<int>(veco.size()) - 1 ; i++)
        {
            int minSpan = veco[i + 1] - veco[i];

            if(minSpan < min)
                min = minSpan;
        } 
        return min;
    }
    else
        throw  std::logic_error("No span found ");
    return 0;
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(veco.size() + std::distance(begin, end) > _n)
        throw std::runtime_error("there are already N elements ") ;
    
    veco.insert(veco.end(), begin, end);
}
