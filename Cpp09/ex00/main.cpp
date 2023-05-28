#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>  
#include <iostream>
#include <string>


void check_arguments_count(int argc)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        exit(1);
    }
}


void calculateExchange(BitcoinExchange *bitcoinExchange, int argc, char * argv[])
{
    std::fstream input_fs;
    std::string line;

    check_arguments_count(argc);
    input_fs.open(argv[1], std::fstream::in);

    if (!input_fs.is_open()) 
    {
        std::cout << "Couldn't read input file" << std::endl;
        exit(0);
    }
    std::cout << "opened file " << argv[1] << " successful" << std::endl << std::endl;


    std::getline(input_fs, line);
    if (line != "date | value")
    {
        std::cout << "Wrong Header" << std::endl;
        exit(0);
    }
    while(std::getline(input_fs, line))
    {
        std::cout << line << std::endl;
        std::string date = line.substr(0, line.find("|") - 1);
        std::string amount = line.substr(line.find("|") + 1);

        bitcoinExchange->transform(date, amount);
        std::cout << std::endl;
        
        // float rate = atof(line.substr(line.find("|")).c_str());
    }
}


int main(int argc, char * argv[])
{
    BitcoinExchange bitcoinExchange;
    calculateExchange(&bitcoinExchange, argc, argv);
    return 0;
}