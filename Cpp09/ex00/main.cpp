#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }


    std::string  filename = av[1];
   
    std::ifstream file(filename.c_str());

    if(!file.is_open())
    {
        std::cerr << "could not open the file " << std::endl;
        return 1 ;
    }


    BitcoinExchange exchange;

    read_line(file, exchange);
    
    file.close();
}