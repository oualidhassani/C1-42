#include "Iter.hpp"

int main()
{
   int Intarr[] = {34, 231, 134};
   std::string Strarr[] = {"oualidd", "os", "arm "};
    float Flaoatarray[] = {42.1, 1337.1, 13.1};

  std::cout << "Integer array:" << std::endl;
    Iter(Intarr, 3, printElement);

    std::cout << "String array:" << std::endl;
    Iter(Strarr, 3, printElement);

    std::cout << "float array:" << std::endl;
    Iter(Flaoatarray, 3, printElement);
}
