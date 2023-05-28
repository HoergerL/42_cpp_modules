#include "RPN.hpp"
#include <iostream>
#include <cstring>

void execute_RPN(int argc, char *argv[])
{
    std::string allowed_chars = "123456789+-*/ ";
    std::string allowed_operators = "+-*/";
    RPN rpn;
    if (argc != 2)
    {
        std::cout << "Error: RPN requires one input string" << std::endl;
        exit(1);
    }
    for (int i = 0; i < (int) strlen(argv[1]); i++)
    {
        // std::cout << "el: " << argv[1][i] << std::endl;
        // besser als else und jetzt die einzelnen chars abfragen
        if (argv[1][i] == ' ')
            continue;
        else if (allowed_operators.find(argv[1][i]) != std::string::npos)
        {
            // std::cout << "added to operations: "<< argv[1][i] << std::endl;
            // rpn.add_operation(argv[1][i]);
            // std::cout << "operator" << std::endl;
            rpn.execute_calculation(argv[1][i]);
        }
        else
        {
            // std::cout << "else" << std::endl;
            if (argv[1][i] >= '0' && argv[1][i] <='9')
            {
                // std::cout << "number" << std::endl;
                int number = argv[1][i] - '0';
                rpn.add_number(number);
                // std::cout << "nach add number" << std::endl;
                // std::cout << "added to numbers: "<< argv[1][i] << std::endl;
                i++;
                if (argv[1][i] != ' ')
                    {
                        std::cout << "Error: every number needs to be followed by a space" << std::endl;
                        exit(1);
                    }
            }
            else
            {
                std::cout  << "Error: invalid character at index " << i << std::endl;
                exit(1);
            }
        }
    }
    int result = rpn.get_result();
    std::cout << result << std::endl;
}

int main(int argc, char * argv[])
{
   execute_RPN(argc, argv);
    // rpn.execute_calculation();
    return 0;
}