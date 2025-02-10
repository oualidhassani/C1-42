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

            delete rrf;

            std::cout << std::endl;

            Intern someRandomIntern1;
            AForm* rrf1;
            rrf1 = someRandomIntern1.makeForm("presidential pardon", "oualid");

            std::cout << rrf1->get_name() << std::endl;

            delete rrf1;

            std::cout << std::endl;
            Intern someRandomIntern2;
            AForm* rrf2;
            rrf2 = someRandomIntern2.makeForm("fffffff", "ssss");

            std::cout << rrf2->get_name() << std::endl;

            delete rrf2;

    }
    catch(const char* errorMessage)
    {
        std::cerr << "Error , the form not existing ";
    }

}