#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }

const char *ScalarConverter::ConversionException::what() const throw()
{
    return "Error , check the conversion ";
}

void ScalarConverter::Converter(std::string &input)
{
    double result;

    if(input.length() == 1 && !std::isdigit(input[0]))
        result = static_cast<double> (input[0]);
    else
        result = stod(input);

    char charvalue = static_cast<char> (result);

    if(!std::isprint(charvalue)||  std::isnan(result) || std::isinf(result) )
        std::cerr << "char: Non Displayable" << std::endl;
    else
        std::cout << "char: " << charvalue << std::endl;

    if (std::isnan(result) || std::isinf(result) || result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
            std::cerr << "int: Non displayable" << std::endl;
    else 
    {
        int intValue = static_cast<int>(result);
        std::cout << "int: " << intValue << std::endl;
    }

    float floatValue = static_cast<float> (result);

        std::cout << "float: " <<std::fixed << std::setprecision(1) <<  floatValue << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) << result << std::endl;



    
}