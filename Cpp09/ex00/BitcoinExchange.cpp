#include "BitcoinExchange.hpp"

BitcoinExchange::check_num()
{
    if(this->_value > 1000)
    {
        std::cerr << "Error: value is too large." << std::endl;
        return;
    }
}

BitcoinExchange::BitcoinExchange() : _date(""), _value(0)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->_date = other._date;
    this->_value = other._value;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
    {
          this->_date = other._date;
        this->_value = other._value;
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string &date, float value) : _date(date) , _value(value)
{
}

std::string &BitcoinExchange::get_date()
{
    return this->_date;
}

float BitcoinExchange::get_float()
{
    return this->_value;
}

void BitcoinExchange::set_date(std::string &date)
{
    this->_date = date;
}

void BitcoinExchange::set_value(float value)
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    this->_value = value;
}


void read_line(std::ifstream &file, BitcoinExchange &exchange)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::string value;

        if (line == "date | value")
            continue ;

        std::getline(iss, date, '|');
        std::getline(iss, value);

        if(line.size() < 13 ||  line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double num = std::atof(value.c_str());
        exchange.set_date(date);
        exchange.set_value(num);
        exchange.check_num();

        std::cout << "Date: " << exchange.get_date() << std::endl;
        std::cout << "Value: " << exchange.get_float() << std::endl;
    }
}