#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try 
    {
        ShrubberyCreationForm f("home");
        Bureaucrat b("b", 5);
        b.signForm(f);         
        b.executeForm(f);   

        std::cout << std::endl;

        RobotomyRequestForm r("office");
        b.signForm(r);   
        b.executeForm(r);

        std::cout << std::endl;

        PresidentialPardonForm p("jail");
        b.signForm(p);
        b.executeForm(p);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}