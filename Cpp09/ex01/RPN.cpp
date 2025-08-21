#include "RPN.hpp"

RPN::RPN() :_stack()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

 int Operation(const std::string& op, int op1, int op2) 
 {
        if (op == "+") return op1 + op2;
        if (op == "-") return op1 - op2;
        if (op == "*") return op1 * op2;
        if (op == "/") 
        {
            if (op2 == 0) 
            {
               std::cerr << "non divisible by 0 ";
               return -1;
            }
            return op1 / op2;
        }
        std::cerr << "uknown operator " << std::endl;
        return -1;
}


bool RPN::isOperator(const std::string& token) 
{
    return token == "+" || token == "-" || token == "*" || token == "/";

}
    

bool RPN::number(const std::string& token) 
{
    if (token.empty()) return false;
    
    size_t start = 0;

    
    for (size_t i = start; i < token.length(); i++) 
    {
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;

}
void RPN::process_input(std::string &input)
{

     while(!input.empty())
    {
        size_t pos = input.find_first_of(' ', 0);
        std::string push_me ;
        if(pos == std::string::npos)
        {
            push_me = input;
            input.clear();
        }
        else
        {
            push_me = input.substr(0, pos);
            input.erase(0, pos + 1);
        }

        if(push_me.empty()) continue;

        if(number(push_me))
        {
            int s = std::atoi(push_me.c_str());
            _stack.push(s);
        }
        else if (isOperator(push_me))
        {
            if(_stack.size() < 2)
            {
                std::cerr << "error need more than 2 arguments ";
                return ;
            }

            int op2 = _stack.top() ; 
            _stack.pop();
            int op1 = _stack.top();
            _stack.pop();
            int result = Operation(push_me, op1, op2);
            if(result == -1)
                return;
            _stack.push(result);

            
        }
        else
        {
            std::cerr << "Error invalid token " << std::endl;
            return ; 
        }
        
    }
    if(_stack.empty())
    {
        std::cerr << "Error: empty expression!" << std::endl;
        return;
    }
    
    if(_stack.size() != 1)
    {
        std::cerr << "Error: invalid expression - stack holds " << _stack.size() << " values" << std::endl;
        return;
    }


        std::cout << _stack.top() << std::endl;
}