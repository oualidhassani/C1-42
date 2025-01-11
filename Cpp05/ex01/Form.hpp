#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    const std::string name;
    bool  boolean;
    const int grade_sign;
    const int grade_execute;
    public:
        Form();
        ~Form();
        Form(const Form &fx);
        Form &operator=(const Form &fx);

        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw()
                {
                    return "Need a grader too high to sign form";
                }
        };
        
        class GradeTooLowException : public std::exception 
        {
            public:
                const char* what() const throw()
                {
                    return "Need a grader too low to sign form";
                }
        };

        std::string get_name() const;
        bool    get_bool();
        int   get_grade_s() const;
        int   get_grade_e() const;
        void  beSigned(Bureaucrat &obj);
};

std::ostream& operator<<(std::ostream& os, const Form& fx);









#endif