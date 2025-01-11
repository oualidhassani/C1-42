#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat obj("oualid", 150);
    Bureaucrat obj1("imad", 1);

    try
    {
        std::cout << obj << std::endl;
        obj.increment_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl ;
    }
    
    try 
    {
        std::cout << obj1 << std::endl;
        obj1.decrement_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;   
    }
}
