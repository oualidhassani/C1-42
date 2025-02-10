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
            rrf = someRandomIntern.makeForm("robotdsadomy request", "Bender");

            std::cout << rrf->get_name() << std::endl;

            delete rrf;
    }
    catch(const char* errorMessage)
    {
        std::cerr << "Error , the form not existing ";
    }

}