#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Need a grader too high to sign form";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Need a grader too low to sign form";
}

Form::Form() : name("default"), grade_sign(2) , grade_execute(5)
{
    this->boolean = false;
}

Form::~Form()
{   
}

Form::Form(const Form &fx) : name(fx.name), boolean(fx.boolean), grade_sign(fx.grade_sign) , grade_execute(fx.grade_execute)
{
}

Form& Form::operator=(const Form &fx)
{
      if (this == &fx)
        return *this;
    this->boolean = fx.boolean;
    return *this;
}

std::string Form::get_name() const
{
    return this->name;
}

bool Form::get_bool()
{
    return this->boolean;
}

int Form::get_grade_s() const
{
    return this->grade_sign;
}

int Form::get_grade_e() const
{
    return this->grade_execute;
}

std::ostream& operator<<(std::ostream& os, const Form& fx)
{
    os << "the name is " << fx.get_name() << "grade sign is " << fx.get_grade_s() << "with a execute grade " << fx.get_grade_e();

    return os;
}


void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <=  this->grade_sign && obj.getGrade() <= this->grade_execute)
        this->boolean = true;
    else
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
        try
        {
           form.beSigned(*this);
            std::cout << this->getName() << " signed " << form.get_name() << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << this->getName() << " couldn't sign " << form.get_name() << " because grade too low" << std::endl;
        }
        
}