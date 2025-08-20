#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <cstdlib> // for atof
#include "map"

class BitcoinExchange
{
    private:
        std::string _date;
        float _value;
        std::map<std::string, float> _data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        BitcoinExchange(std::string &_date, float _value);
        std::string &get_date();
        float get_float();
        void set_value(float value) ;
        void set_date(std::string &date);
        int check_num();
        // void load_data(const std::string &filename);
        void load_data(std::string &filename);
        float find_rate(std::string &date);


};
void read_line(std::ifstream &file, BitcoinExchange &exchange);





#endif