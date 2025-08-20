#include "BitcoinExchange.hpp"

float BitcoinExchange::find_rate(std::string &date)
{
    std::map<std::string , float>::const_iterator it = _data.lower_bound(date);

    if(it != _data.end() && it->first == date)
    {
        return it->second;
    }

    if(it == _data.begin())
    {
        std::cerr << "Error: no data available for date " << date << std::endl;
        return -1;

    }
    --it;
    return it->second;
}

void BitcoinExchange::load_data(std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);

    while(std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string ex_date, rate ;
        if(line == "date,exchange_rate")
            continue;
        
        if(std::getline(iss,ex_date, ',') && std::getline(iss, rate))
        {
            float rate_num = std::atof(rate.c_str());
            _data[ex_date] = rate_num;
        }
    }
}

int maxdays(int year, int month)
{
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29; 
        else
            return 28; 
    }

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

int BitcoinExchange::check_num()
{
    if(this->_value > 1000)
    {
        std::cerr << "Error: value is too large." << std::endl;
        return -1;
    }
    return 0;
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

        if (exchange.check_num() == -1)
            continue;

        if(exchange.get_date().size() != 11 || exchange.get_date()[4] != '-' || exchange.get_date()[7] != '-')
        {
            std::cerr << "Error: bad date format  => " << exchange.get_date() << std::endl;
            continue;
        }

        std::string stringyear = exchange.get_date().substr(0, 4);
        int year = std::atoi(stringyear.c_str());
        std::string stringmonth = exchange.get_date().substr(5, 2);
        int month = std::atoi(stringmonth.c_str());
        int day = std::atoi(exchange.get_date().substr(8, 2).c_str());
        if(year < 2009 || year >= 2023)
        {
            std::cerr << "Error: bad date => " << year << std::endl;
            continue;
        }
        if(month >= 13 ||month <= 00)
        {
            std::cerr << "Error: bad month => " << month << std::endl;
            continue;
        }
        int maxday = maxdays(year, month);

        if(day <= 0 || day > maxday)
        {
            std::cerr << "Error: bad day => " << day << std::endl;
            continue;
        }

        float result = exchange.find_rate(exchange.get_date());
        float value_f = exchange.get_float();

        if(result == -1)
            continue;
        
        std::cout << exchange.get_date() << " => " << value_f << " = " << result * value_f << std::endl;

    }
}


// 2 if the num is divisable by 4 is a leap year
// 2 if the num is divisable by 100 is not a leap year
// 2 if the num is divisable by 400 is a leap year