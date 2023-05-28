#pragma once
#include <stack>
#include <iostream>

class RPN
{
private:
    std::stack<int> _numbers;
    // std::stack<char> _operations;
public:
    RPN();
    RPN (const RPN &rpn);
    ~RPN ();
    RPN& operator = (const RPN &rpn);
    // void add_operation(char operation);
    void add_number(int number);
    void execute_calculation(char operation);
    int get_top_number();
    int execute_operation(int number1, int number2, char operation);
    int get_result();
};