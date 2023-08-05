#include "BitcoinExchange.hpp"

std::string strtrim(const std::string& str)
{
    std::string trimmed = str;
    size_t	i = 0;
    size_t	j = trimmed.size() - 1;

    while (i < j && std::isspace(trimmed[i]))
	{
        i++;
    }
    trimmed.erase(0, i);
    while (j > i && std::isspace(trimmed[j]))
	{
        j--;
    }
	if (trimmed[j + 1])
    	trimmed.erase(j + 1);
    return trimmed;
}

bool check_date_error(std::string date)
{
	int year, month, day;
	if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if ((month <= 0 || month >= 13) || (day <= 0 || day >= 32) || (month == 2 && day > 29))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 0 || day >= 31))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if(month == 2)
    {
        if(day == 29)
        {
            if(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				return false;
			}
        }
    }
	return true;
}

bool check_value_error(std::string value)
{
	char *endptr = NULL;
	std::string value_trim = strtrim(value);
	double	val = strtod(value_trim.c_str(), &endptr);
	if (endptr[0] != 0)
	{
		std::cerr << "Error: Bad input: " << value << std::endl;
		return false;
	}
	if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (val > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
    BitcoinExchange		exchange;
	std::ifstream		input;
	std::string			date;
	std::string			line;
	std::string			value;
    std::map<std::string, double> btc;
    btc = exchange.getBtc();
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (EXIT_FAILURE);
    }
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
        return (EXIT_FAILURE);
	}
	getline(input, line);
	while (getline(input, line))
	{
		std::stringstream str(line);
		getline(str, date, '|');
		getline(str, value);
		for (size_t i = 0; i < value.length(); i++)
		{
			if (value[i] == ',')
				value[i] = '.';
   		}
		if (strtrim(date).size() != 10 || value.empty())
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (check_date_error(date) && check_value_error(value))
		{
			double rate = exchange.matchDate(strtrim(date));
			std::cout << strtrim(date) << " => " << strtrim(value) << " = " << strtod(value.c_str(), NULL) * rate << std::endl;
		}
	}
    input.close();
    return (0);
}