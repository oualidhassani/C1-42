#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();

    this->name = "default";
    this->grade = 150;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();

    this->name = other.name;
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();

    if(this == &other)
        return *this;

    this->name = other.name;
    this->grade = other.grade;
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Need Grade too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Need Grade too low\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    
    this->grade = grade;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::decrement_grade()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::increment_grade()
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}


void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);

        std::cout << this->getName() << " execute " << form.get_name() ;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " did not execute it well " << form.get_name();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& fx)
{
    os << "the name is " << fx.getName() << " have a grade " << fx.getGrade();

    return os;
}
