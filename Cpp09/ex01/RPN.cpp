#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN (const RPN &rpn)
{
    *this = rpn;
}

RPN::~RPN ()
{

}

RPN& RPN::operator = (const RPN &rpn)
{
    this->_numbers = rpn._numbers;
    // this->_operations = rpn._operations;
    return (*this);
}

// void RPN::add_operation(char operation)
// {
//     this->_operations.push(operation);
// }

void RPN::add_number(int number)
{
    this->_numbers.push(number);
}

int RPN::get_top_number()
{
    if (_numbers.empty())
    {
        std::cout << "Error: not enough numbers" << std::endl;
        exit(1);
    }
    // std::cout << "number top: " << _numbers.top() << std::endl;
    int number = _numbers.top();
    _numbers.pop();
    return number;
}

int RPN::execute_operation(int number1, int number2, char operation)
{
    if (operation == '+')
        return number1 + number2;
    else if (operation == '-')
        return number1 - number2;
    else if (operation == '*')
        return number1 * number2;
    else if (operation == '/')
        return number1 / number2;
    else
    {
        std::cout << "Error: wrong operation: " << operation << std::endl;
        exit(1);
    }
}

void RPN::execute_calculation(char operation)
{
    int number1 = get_top_number();
    int number2 = get_top_number();
    // std::cout << number1 << operation << number2  << std::endl;
    int result = execute_operation(number2, number1, operation);
    // std::cout << "result: " << result << std::endl;
    _numbers.push(result);
}

int RPN::get_result()
{
    int result = this->_numbers.top();
    this->_numbers.pop();
    if (!(this->_numbers.empty()))
    {
        std::cout << "Error: too many numbers" << std::endl;
        exit(1);
    }
    return result;
}


// void RPN::execute_calculation()
// {
//     while(!_operations.empty())
//     {
//         char operation = _operations.top();
//         _operations.pop();
//         int number1 = get_top_number();
//         int number2 = get_top_number();
//         std::cout << "number1: " << number1 << ", number 2: " << number2 << " , operation: " << operation << std::endl;
//         int result = execute_operation(number1, number2, operation);
//         if (!_numbers.empty() || !_operations.empty())
//             _numbers.push(result);
//         else
//         {
//             std::cout << result << std::endl;
//             return;
//         }


//     }
//     if (!_numbers.empty())
//     {
//         std::cout << "Error: not enough operations" << std::endl;
//         exit(1);
//     }
// }