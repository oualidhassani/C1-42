#include "easyfind.hpp"

int main()
{
    std::vector<int> A;
    A.push_back(3);
    A.push_back(-1);
    A.push_back(2);
    A.push_back(32);

// 3 -1 1 32
    try
    {
        easyfind(A, -1);
        easyfind(A, 32);
        easyfind(A, 100);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}