#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    try 
    {
        // Shrubbery test
        ShrubberyCreationForm f("home");
        Bureaucrat b("b", 1);
        b.signForm(f);          // Use bureaucrat to sign the form
        b.executeForm(f);       // Use bureaucrat to execute the form, not direct call
        
        // Robotomy test
        RobotomyRequestForm r("office");
        b.signForm(r);         // Use bureaucrat to sign, not form's method
        b.executeForm(r);

        // Presidential test
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