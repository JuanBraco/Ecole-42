#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Contact {

    public:

        Contact( void);
        ~Contact( void);

        void    init(int i);
        void    view(int index) const;
        void    display(int index) const;
        void    setIndex(int i);

    private:

        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        int         _index;
        std::string _printLen(std::string str) const;
        std::string _getInput(std::string str) const;
};

#endif