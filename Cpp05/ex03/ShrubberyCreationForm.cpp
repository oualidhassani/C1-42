#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() 
{
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target + "_shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    return *this;
}


int ShrubberyCreationForm::get_exec_Shrubbery() const
{
    return this->grade_execute;
}


int ShrubberyCreationForm::get_signe_Shrubbery() const
{
    return this->grade_sign;
}

std::string ShrubberyCreationForm::get_name_Shrubbery() const
{
    return this->name;
}

void ShrubberyCreationForm::execute_Shrubbery() const
{
    if(this->grade_execute < 1)
        throw GradeTooHighException();
    if(this->grade_sign > 150)
        throw GradeTooLowException();
    if(this->grade_execute > 150)
        throw GradeTooLowException();
    if(this->grade_sign < 1)
        throw GradeTooHighException();

    std::ofstream obj(this->get_name_Shrubbery().c_str(), std::ios::out);

    if(!obj.is_open())
        std::cerr << "fail to open the file" << std::endl;
    
    obj << "      /\\      " << std::endl;
    obj << "     /\\*\\     " << std::endl;
    obj << "    /\\O\\*\\    " << std::endl;
    obj << "   /*/\\/\\/\\   " << std::endl;
    obj << "  /\\O\\/\\*\\/\\  " << std::endl;
    obj << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    obj << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    obj << "      ||      " << std::endl;
    obj << "      ||      " << std::endl;
    obj << "      ||      " << std::endl;
    obj << std::endl;
    obj << "      /\\      " << std::endl;
    obj << "     /\\*\\     " << std::endl;
    obj << "    /\\O\\*\\    " << std::endl;
    obj << "   /*/\\/\\/\\   " << std::endl;
    obj << "  /\\O\\/\\*\\/\\  " << std::endl;
    obj << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    obj << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    obj << "      ||      " << std::endl;
    obj << "      ||      " << std::endl;
    obj << "      ||      " << std::endl;
    
    obj.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &obj) const
{
    (void)obj;
    this->execute_Shrubbery();
}


void ShrubberyCreationForm::beSigned(Bureaucrat &obj)
{
    AForm::beSigned(obj);
}