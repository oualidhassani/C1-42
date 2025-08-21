#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
class RPN
{
    private :
        std::stack<int> _stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void process_input(std::string &input);
        bool isOperator(const std::string& token);
        bool number(const std::string& token) ;



};












#endif