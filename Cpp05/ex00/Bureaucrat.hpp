#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
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
};
 
std::ostream& operator<<(std::ostream& os, const Bureaucrat& fx);


#endif