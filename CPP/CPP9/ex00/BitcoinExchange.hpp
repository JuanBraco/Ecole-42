#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> btc;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& btc);
        BitcoinExchange& operator=(const BitcoinExchange& btc);
        ~BitcoinExchange();
        std::map<std::string, double> getBtc() const;
        double	matchDate(std::string date);
};

#endif