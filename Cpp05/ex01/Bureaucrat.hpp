#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    std::string name;
    int grade;
    public:
        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw();

        };
        
        class GradeTooLowException : public std::exception 
        {
            public:
                const char* what() const throw();

        };

        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        std::string getName() const;
        int     getGrade() const;
        void    increment_grade();
        void    decrement_grade();
        void    signForm(Form &form);
};
 
std::ostream& operator<<(std::ostream& os, const Bureaucrat& fx);


#endif