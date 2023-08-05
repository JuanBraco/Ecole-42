#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	*this = rhs;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj)
{
	static_cast<void>(obj);
	std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	return *this;
}

bool ScalarConverter::isInt(std::string str)
{
	unsigned long	i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str.size() == i)
		return (true);
	return (false);
}

bool ScalarConverter::isChar(std::string str)
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);

}

bool ScalarConverter::isFloat(std::string str)
{
	unsigned long	i = 0;
	
	if (str == "-inff" or str == "+inff" or str == "nanf")
		return (true);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.' && std::isdigit(str[i + 1]))
		i++;
	else
		return (false);
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == 'f')
		i++;
	else
		return (false);
	if (str.size() == i)
		return (true);
	return (false);
}

bool ScalarConverter::isDouble(std::string str)
{
	unsigned long	i = 0;
	
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str[0] == '-' || str[0] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.' && std::isdigit(str[i + 1]))
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str.size() == i)
		return (true);
	return (false);
}

void ScalarConverter::convert(const std::string& str)
{
	bool (*func[5])(std::string str) = {ScalarConverter::isChar, ScalarConverter::isInt, ScalarConverter::isFloat, ScalarConverter::isDouble, NULL};
	unsigned long	i = 0;
	
	while(func[i] && func[i](str) == false)
		i++;

	char	_char = 0;
	int		_int = 0;
	float	_float = 0.0f;
	double	_double = 0.0;
	
	switch (i)
	{
		case 0 :
			_char = str[0];
			convertChar(_char);
			break;
		case 1 :
			_int = atoi(str.c_str());
			convertInt(_int);
			break;
		case 2 :
			_float = std::atof(str.c_str());
			convertFloat(_float, str);
			break;
		case 3 :
			_double = std::strtod(str.c_str(), NULL);
			convertDouble(_double, str);
			break;
		default : 
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << "impossible" << std::endl;
			std::cout << "double: " << "impossible" << std::endl;
	}
	return ;
}


void ScalarConverter::convertChar(char _char)
{
    printChar(_char);
    printInt(static_cast<int>(_char));
    printFloat(static_cast<float>(_char));
    printDouble(static_cast<double>(_char));
}

void ScalarConverter::convertInt(int _int)
{
	if(_int < 256)
    	printChar(static_cast<char>(_int));
	else
		std::cout << "Non displayable" << std::endl;
    printInt(_int);
    printFloat(static_cast<float>(_int));
    printDouble(static_cast<double>(_int));
}

void ScalarConverter::convertFloat(float _float, std::string str)
{
	if (str == "-inff" or str == "+inff" or str == "nanf") {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}
	else{
		printChar(static_cast<char>(_float));
    	printInt(static_cast<int>(_float));
	}
	int i = 2;
	while (str[str.size() - i ] != '.')
	{
		if (str[str.size() - i ] != '.' && str[str.size() - i ] != '0')
		{
			std::cout << "float: " << _float << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(_float) << std::endl;
			return ;
		}
		i++;
	}
    printFloat(_float);
    printDouble(static_cast<double>(_float));
}

void ScalarConverter::convertDouble(double _double, std::string str)
{
	if (str == "-inf" or str == "+inf" or str == "nan") {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}
	else{
		printChar(static_cast<char>(_double));
		printInt(static_cast<int>(_double));
	}
	int i = 1;
	while (str[str.size() - i ] != '.')
	{
		if (str[str.size() - i ] != '.' && str[str.size() - i ] != '0')
		{
			std::cout << "float: " << static_cast<float>(_double) << "f" << std::endl;
			std::cout << "double: " << _double << std::endl;
			return ;
		}
		i++;
	}
    printFloat(static_cast<float>(_double));
    printDouble(_double);
}
void ScalarConverter::printChar(char _char)
{
    std::cout << "char: ";
    if (!std::isgraph(_char))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << _char << "'" << std::endl;
}

void ScalarConverter::printInt(int _int)
{
    std::cout << "int: " << _int << std::endl;
}

void ScalarConverter::printFloat(float _float)
{
    std::cout << "float: " << _float << ".0f" << std::endl;
}

void ScalarConverter::printDouble(double _double)
{
    std::cout << "double: " << _double << ".0" << std::endl;
}