#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>
# include <cstdlib>
# include <stdint.h>

struct Data
{
	std::string str;
	std::string getStr(void) { return str ;};
};

class Serializer {

    public:

        Serializer(void);
        Serializer( const Serializer &rhs );
        Serializer &   operator=(Serializer const & rhs);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
	    static Data* deserialize(uintptr_t raw);

    private:

};

#endif