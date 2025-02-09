#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        int get_exec_Shrubbery() const;
        int get_signe_Shrubbery()  const;
        std::string get_name_Shrubbery() const;
        void execute_Shrubbery() const;
        void beSigned(Bureaucrat &obj);
        void execute(const Bureaucrat& obj) const;

};







#endif