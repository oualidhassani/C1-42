#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
    public:
        class ConversionException : public std::exception 
        {
            public:
                const char* what() const throw(); 
        };
        static  void Converter(std::string &string);

};






#endif
