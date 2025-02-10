#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &fx);
        Intern &operator=(const Intern &fx);
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
        AForm* createPresidential(std::string const &target); 
        AForm* createRobotomy(std::string const &target);
        AForm* createShrubbery(std::string const &target); 
};


#endif