#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    // ScalarConverter obj;

    if (ac != 2)
	{
		std::cerr << "One Argument required." << std::endl;
		return (1);
	}
    try
    {
        std::string input(av[1]);
        ScalarConverter::Converter(input);
        return(0);
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error " << e.what() << std::endl;
        return(1);
    }


}