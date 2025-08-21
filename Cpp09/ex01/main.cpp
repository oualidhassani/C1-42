#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "enter the right number of arguments" << std::endl;
        return -1;
    }
    RPN rpn;


    std::string input(av[1]);
    // std::cout << "Input: " << input << std::endl;
   rpn.process_input(input);
}