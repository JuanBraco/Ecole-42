#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
    return;
}

Contact::~Contact(void) {
    return;
}

std::string Contact::_getInput(std::string str) const {
    std::string input = "";
    bool        valid = true;
    while (valid)
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = false;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    }
    return (input);
}

std::string Contact::_printLen(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::init(int i) {
    std::cin.ignore();
    this->_firstName = this->_getInput("Please enter you first name: ");
    this->_lastName = this->_getInput("Please enter your last name: ");
    this->_nickname = this->_getInput("Please enter your nickname: ");
    this->_phoneNumber = this->_getInput("Please enter your phone number: ");
    this->_darkestSecret = this->_getInput("Please enter your darkest secret: ");
    this->_index = i;
}

void    Contact::view(int index) const {
    
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const {

    std::cout << std::endl;
    std::cout << "CONTACT #" << index << std::endl;
    std::cout << "First Name:\t" << this->_firstName << std::endl;
    std::cout << "Last Name:\t" << this->_lastName << std::endl;
    std::cout << "Nickname:\t" << this->_nickname << std::endl;
    std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret:\t" << this->_darkestSecret << std::endl;
    std::cout << std::endl;
}

void    Contact::setIndex(int i) {
    this->_index = i;
}
