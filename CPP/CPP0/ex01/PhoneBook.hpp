#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

    public:

        PhoneBook( void);
        ~PhoneBook( void);

        void    welcome(void) const;
        void    addContact(void);
        void    searchContact(void);
        void    searchPhone(void);

    private:

        Contact _contacts[8];
        int     _readIndex(void);
};

#endif