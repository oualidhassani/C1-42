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


    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Span sp = Span(10);

        sp.addNumber(6);
        sp.addNumber(3);

        std::vector<int> numbers;
        numbers.push_back(17);
        numbers.push_back(9);
        numbers.push_back(11);
        numbers.push_back(42);
        numbers.push_back(13);


        sp.addNumber(numbers.begin(), numbers.end());

        // Print the shortest and longest spans
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

