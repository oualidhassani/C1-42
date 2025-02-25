#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    std::srand(time(0));

    int value = rand() % 3;

    std::cout << value << std::endl;

    Base *ptr = NULL;
    switch(value)
    {
        case 0:
           ptr = new A();
        case 1:
            ptr = new B();
        case 2:
            ptr = new C();
        default:
            break;
    }
    return ptr;
}

void identify(Base* p)
{
    if(dynamic_cast<A*> (p))
        std::cout << "This is A " << std::endl;
    else if(dynamic_cast<B*> (p))
        std::cout << "This is B " << std::endl;
    else if(dynamic_cast<C*> (p))
        std::cout << "This is C " << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}


void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "This is A" << std::endl;
    }
    catch (const std::bad_cast&)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "This is B" << std::endl;
        }
        catch (const std::bad_cast&)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                std::cout << "This is C" << std::endl;
            }
            catch (const std::bad_cast&)
            {
                std::cerr << "Unknown type" << std::endl;
            }
        }
    }
}