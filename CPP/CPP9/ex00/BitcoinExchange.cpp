#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream	data;
    std::string		date;
    std::string		exchange_rate;

	data.open("data.csv");
	if (!data.is_open())
	{
		std::cerr << "Could not open The csv file" << std::endl;
		exit(1);
	}
	else
	{
		getline(data, date);
		while (!getline(data, date, ',').eof())
		{
            // std::cout << "TEST1" << date << std::endl;
			getline(data, exchange_rate);
            // std::cout << "TEST2" << exchange_rate << std::endl;
			this->btc.insert(std::make_pair(date, strtod(exchange_rate.c_str(), NULL)));
		}
		data.close();
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& btc)
{
    *this = btc;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& btc)
{
    if (this != &btc)
        this->btc = btc.btc;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double	BitcoinExchange::matchDate(std::string date)
{
	double	rate = 0;

	if (this->btc.find(date) != this->btc.end())
		rate = this->btc[date];
	else if (this->btc.begin()->first > date)
		rate = this->btc.begin()->second;
	else
	{
		std::map<std::string, double>::iterator it = this->btc.lower_bound(date);
		it--;
		rate = it->second;
	}
	return rate;
}

// GETTER

std::map<std::string, double> BitcoinExchange::getBtc() const
{
    return this->btc;
}