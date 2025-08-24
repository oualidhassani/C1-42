#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }

    PmergeMe pmerge;

    for(int i = 1; i < ac; i++)
    {
        int num = std::atoi(av[i]);

        if (num < 0)
        {
            std::cerr << "Error: Negative numbers are not allowed." << std::endl;
            return 1;
        }
        
    }
}