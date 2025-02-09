#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        void execute() const;
        std::string get_name_Robotomy() const;
        int get_signe_Robotomy() const;
        int get_exec_Robotomy() const;
        void    execute_Robotomy() const;
        void execute(const Bureaucrat& executor) const;
};







#endif