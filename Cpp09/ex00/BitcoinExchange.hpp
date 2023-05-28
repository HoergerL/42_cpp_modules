#pragma once

#include <fstream>  
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<int, double> _exchangeRates;

    public:
      BitcoinExchange();
      BitcoinExchange (const BitcoinExchange &bitcoinExchange);
      ~BitcoinExchange ();
      BitcoinExchange& operator = (const BitcoinExchange &bitcoinExchange);
      void loadDatabase();
      void transform(std::string date, std::string amount);
      double check_amount(std::string amount, bool needs_checks);
      int check_date(std::string date, bool needs_checks);
      double get_nearest_factor(int nbr_date);
};