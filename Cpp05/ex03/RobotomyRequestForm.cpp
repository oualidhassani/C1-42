#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::get_name_Robotomy() const
{
    return this->name;
}

int RobotomyRequestForm::get_signe_Robotomy() const
{
    return this->grade_sign;
}

int RobotomyRequestForm::get_exec_Robotomy() const
{
    return this->grade_execute;
}

void RobotomyRequestForm::execute_Robotomy() const
{
    
    std::cout << "* DRILLING NOISES * Bzzzzz... Whirrrr... Crack!" << std::endl;
    
    std::srand(std::time(NULL));
    if (std::rand() % 2)
    {
        std::cout << this->get_name_Robotomy() << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed for " << this->get_name_Robotomy() << "." << std::endl;
    }
}

void RobotomyRequestForm::execute(const Bureaucrat &obj) const
{
    (void)obj;
    this->execute_Robotomy();
}