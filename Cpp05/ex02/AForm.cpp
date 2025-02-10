#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Need a grader too high to sign form";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Need a grader too low to sign form";
}

AForm::AForm() : name("default"), boolean(false), grade_sign(2) , grade_execute(1)
{
}

AForm::~AForm()
{   
}

AForm::AForm(const AForm &fx) : name(fx.name), boolean(fx.boolean), grade_sign(fx.grade_sign) , grade_execute(fx.grade_execute)
{
}

AForm::AForm(std::string name, const int grade_sign, const int grade_execute) : name(name), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if(this->grade_execute < 1)
        throw GradeTooHighException();
    if(this->grade_sign > 150)
        throw GradeTooLowException();
    if(this->grade_execute > 150)
        throw GradeTooLowException();
    if(this->grade_sign < 1)
        throw GradeTooHighException();
}

AForm& AForm::operator=(const AForm &fx)
{
      if (this == &fx)
        return *this;
    this->boolean = fx.boolean;
    return *this;
}

std::string AForm::get_name() const
{
    return this->name;
}

bool AForm::get_bool() const
{
    return this->boolean;
}

int AForm::get_grade_s() const
{
    return this->grade_sign;
}

int AForm::get_grade_e() const
{
    return this->grade_execute;
}

std::ostream& operator<<(std::ostream& os, const AForm& fx)
{
    os << "the name is " << fx.get_name() << "grade sign is " << fx.get_grade_s() << "with a execute grade " << fx.get_grade_e();

    return os;
}


void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <=  this->grade_sign)
        this->boolean = true;
    else
        throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &AForm)
{
        try
        {
           AForm.beSigned(*this);
            std::cout << this->getName() << " signed " << AForm.get_name() << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << this->getName() << " couldn't sign " << AForm.get_name() << " because grade too low" << std::endl;
        }
        
}

//  void AForm::execute() const
//  {
//         if(this->grade_execute < 1)
//             throw GradeTooHighException();
//         if(this->grade_sign > 150)
//             throw GradeTooLowException();
//         if(this->grade_execute > 150)
//             throw GradeTooLowException();
//         if(this->grade_sign < 1)
//             throw GradeTooHighException();
//  }

