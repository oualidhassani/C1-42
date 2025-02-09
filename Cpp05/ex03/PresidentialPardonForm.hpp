#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        void execute(const Bureaucrat& executor) const;
        // void get_name_presidential() const;
        // void get_bool_presidential();
        // void get_grade_s_presidential() const;
        // void get_grade_e_presidential() const;
};




#endif