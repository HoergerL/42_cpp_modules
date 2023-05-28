#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadDatabase();
}

BitcoinExchange::BitcoinExchange (const BitcoinExchange& bitcoinExchange)
{
    * this = bitcoinExchange;
}

BitcoinExchange::~BitcoinExchange ()
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bitcoinExchange)
{
    this->_exchangeRates = bitcoinExchange._exchangeRates;
    return (*this);

}

void BitcoinExchange::loadDatabase()
{
    std::fstream db_fs;
    std::string line;
    db_fs.open("data.csv", std::fstream::in);

    if (!db_fs.is_open()) 
    {
        std::cout << "Couldn't read database" << std::endl;
        exit(1);
    }

    // skip header
    std::getline(db_fs, line);
    while(std::getline(db_fs, line))
    {
        // std::cout << line << std::endl;
        int date = check_date(line.substr(0, line.find(",")), false);
        double rate = check_amount(line.substr(line.find(",") + 1), false);
        _exchangeRates.insert(std::pair<int, double>(date, rate));
    }

    // std::cout << line << std::endl;

    db_fs.close();
}

double BitcoinExchange::get_nearest_factor(int nbr_date)
{
    std::map<int, double>::iterator it = _exchangeRates.lower_bound(nbr_date);
        
    if (it == _exchangeRates.begin()) {
        // Lower bound is first element in map
        // std::cout << "most lower value" << std::endl;
        return (it->second);
    }
    else if (it == _exchangeRates.end()) {
        // Lower bound is last element in map
        it --;
        std::cout << it->first << std::endl;
        // std::cout << "most upper value" << std::endl;
        return(it->second);
    }
    else 
    {
        // Lower bound is closer than upper bound
        it--;
        int lowerKey = it->first;
        // std::cout << "nbr_date, lowerKey: " << nbr_date << ", " <<  lowerKey << std::endl;
            std::cout << "not found, taking nearest value of " <<  lowerKey << std::endl;
            return it->second;
       
    }
        
    
    // std::cout << "not found, taking nearest value of " <<  it->first << std::endl;
}

void BitcoinExchange::transform(std::string date, std::string amount)
{
    std::map<int,double>::iterator it;
    double factor;

    int nbr_date = check_date(date, true);
    if (nbr_date == 0)
        return;

    double nbr_amount = check_amount(amount, true);
    if (nbr_amount == -1)
        return;
    
    it = _exchangeRates.find(nbr_date);
    if (it != _exchangeRates.end())
        factor = it->second;
    else
    {
        factor = get_nearest_factor(nbr_date);
       
        // std::cout << "closest date value in db => " << it2->first << ", "<< it2->second << std::endl;
        // factor = it2->second;
    }
    std::cout << "= " << factor * nbr_amount << std::endl;
}

int BitcoinExchange::check_date(std::string date, bool needs_checks)
{
    if (needs_checks && (date.length() < 8 || date[4] != '-' || date[7] != '-'))
    {
        std::cout << "Error: wrong date format" << std::endl;
        return 0;
    }
    else
    {
        int year = atoi(date.substr(0, 4).c_str());
        int month = atoi(date.substr(5, 2).c_str());
        int day = atoi(date.substr(8).c_str());

        if (needs_checks && (year > 3000 || year < 1 || month > 12 || month < 1  || day > 31 || day < 1))
        {
            std::cout << "Error: wrong date format" << std::endl;
            return 0;
        }
        return year * 10000 + month * 100 + day;
    }
}

double BitcoinExchange::check_amount(std::string amount, bool needs_checks)
{
    char* endptr = NULL;
    double d = strtod(amount.c_str(), &endptr);

    // Check for errors
    if (endptr == amount.c_str() || *endptr != '\0') 
    {
        std::cout << "Error: Invalid amount" << std::endl;
        d = -1;
    }
    else 
    {
        if (needs_checks && (d < 0 || d > 1000))
        {
            std::cout << "Error: amount is invalid (not in the range of 0 - 1000)" << std::endl;
            d = -1;   
        }

    }    
    return d;
}