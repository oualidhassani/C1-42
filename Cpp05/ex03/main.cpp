#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try 
    {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");

            std::cout << rrf->get_name() << std::endl;
    }
    catch(const char* errorMessage)
    {
        std::cerr << "Error , the form not existing ";
    }

}