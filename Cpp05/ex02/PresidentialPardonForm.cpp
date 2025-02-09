#include "PresidentialPardonForm.hpp"
 
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    AForm::operator=(copy);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->get_grade_e())
        throw AForm::GradeTooLowException();
    if (!this->get_bool())
        throw AForm::GradeTooLowException();
    std::cout << this->get_name() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
