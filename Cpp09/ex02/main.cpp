#include "PmergeMe.hpp"


void PmergeMe::addnum(int num)
{
    vec.push_back(num);
}

bool isValidNumber(const std::string& str)
{
    if (str.empty())
        return false;

    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool Duplic(std::vector<int> vec)
{
    std::sort(vec.begin(), vec.end());
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[i - 1])
            return true;
    }

    return false;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }

    PmergeMe pmerge;

    std::vector<int> vec_t;
    for(int i = 1; i < ac; i++)
    {

        if (!isValidNumber(av[i]))
        {
            std::cerr << "Error: Invalid argument '" << av[i] << "'. Only positive integers are allowed." << std::endl;
            return 1;
        }

        long num_arg = std::atol(av[i]);

        if(num_arg < 0 || num_arg > 2147483647)
        {
            std::cerr << "Error: Argument '" << av[i] << "' is out of range. Only positive integers within the range of a 32-bit signed integer are allowed." << std::endl;
            return 1;
        }

        int num = static_cast<int>(num_arg);

        vec_t.push_back(num);

        pmerge.addnum(num);
        
    }
        
        if(Duplic(vec_t))
        {
            std::cerr << "Error: Duplicate number '" <<  std::endl;
            return 1;
        }

    
}