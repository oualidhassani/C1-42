#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat obj("oualid", 151);
        std::cout << obj << std::endl;
        obj.increment_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl ;
    }
    
    try 
    {
        Bureaucrat obj1("imad", 1);
        std::cout << obj1 << std::endl;
        obj1.decrement_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;   
    }
}
