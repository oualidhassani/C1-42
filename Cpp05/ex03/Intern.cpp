#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &fx)
{
    (void)fx;
}

Intern& Intern::operator=(const Intern &fx)
{
    if (this == &fx)
        return *this;
    return *this;
}

Intern::~Intern()
{
}

AForm*  Intern::createPresidential(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::createRobotomy(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::createShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string s1[3] = {"presidential pardon", "robotomy request" , "shrubbery creation"};

    AForm* (Intern::*Formcreator[3])(std::string const &target) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};
    for(int i = 0; i < 3 ; i++)
    {
        if(s1[i] == name)
        {
            std::cout << "Intern create " << name << std::endl;
            return (this->*Formcreator[i])(target);
        }
    }
    throw "Form is not accepted ";
}

