#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);



        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;


        Span sp1 = Span(7);

        std::vector<int> a = {42 ,13, 75 ,1 , 6};
        sp1.addNumber(a.begin(), a.end());
        

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
     }

}

