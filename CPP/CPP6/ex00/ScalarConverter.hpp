#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>
#include <cstdlib>
#include <algorithm>

class ScalarConverter {

    public:



        static void     convert(const std::string& str);
        static bool     isChar(std::string str);
        static bool     isInt(std::string str);
        static bool     isFloat(std::string str);
        static bool     isDouble(std::string str);
        static void    convertChar(char _char);
        static void    convertInt(int _int);
        static void    convertFloat(float _float, std::string str);
        static void    convertDouble(double _double, std::string str);
        static void    printInt(int _int);
        static void    printFloat(float _float);
        static void    printDouble(double _double);
        static void    printChar(char _char);

    private:

        ScalarConverter(void);
        ScalarConverter( const ScalarConverter &rhs );
        ScalarConverter &   operator=(ScalarConverter const & rhs);
        ~ScalarConverter();

};

#endif