#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
            const std::string name;
            bool  boolean;
            const int grade_sign;
            const int grade_execute;
    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm &fx);
        AForm &operator=(const AForm &fx);
        AForm(std::string name, const int grade_sign, const int grade_execute);
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
        bool    get_bool()  const;
        int   get_grade_s() const;
        int   get_grade_e() const;
        void  beSigned(Bureaucrat &obj);
        virtual void execute(const Bureaucrat &executor) const = 0;
        
};

std::ostream& operator<<(std::ostream& os, const AForm& fx);









#endif