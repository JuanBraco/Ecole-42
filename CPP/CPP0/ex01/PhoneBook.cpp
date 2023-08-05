
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    return;
}

PhoneBook::~PhoneBook(void) {
    return;
}

void    PhoneBook::welcome(void) const {
    std::cout << std::endl;
    std::cout << "📞 Welcome to Your Awesome PhoneBook 📖" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void) {
    static int  i;
    this->_contacts[i % 8].init(i % 8);
    i++;
}

void    PhoneBook::searchContact(void) {
    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
    for(int i = 0; i < 8; i++) {
        this->_contacts[i].view(i);
    }
}

int     PhoneBook::_readIndex(void) {
    
    int     input = -1;
    bool        valid = false;
    while (!valid)
    {
        std::cout << "Please enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
        } else if (input < 0 || input > 7) {
            std::cout << "Invalid index; please re-enter." << std::endl;
        } else {
            valid = true;
        }
    }
    return (input);
}

void    PhoneBook::searchPhone(void) {
    int i = this->_readIndex();
    this->_contacts[i].display(i);
}
