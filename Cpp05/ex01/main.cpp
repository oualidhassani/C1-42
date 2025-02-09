#include "Bureaucrat.hpp"

int main()
{
        Bureaucrat highRank("John", 1); // mzn  
        Form form;  

        std::cout << "Testing with high ranked bureaucrat:" << std::endl;
        highRank.signForm(form);
        std::cout << "Form signed status: " << (form.get_bool() ? "signed" : "unsigned") << std::endl;
        std::cout << std::endl;


    {
        Bureaucrat lowRank("Bob", 3);    //error 
        Form form; 

        std::cout << "Testing with low ranked bureaucrat:" << std::endl;
        lowRank.signForm(form);
        std::cout << "Form signed status: " << (form.get_bool() ? "signed" : "unsigned") << std::endl;

    }

    return 0;
}