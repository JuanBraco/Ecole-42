#include <iostream>
#include <limits>
#include "PhoneBook.hpp"



int main() {

    PhoneBook book;
    std::string input = "";
    book.welcome();
    while(input.compare("EXIT")) {
        if (input.compare("ADD") == 0)
            book.addContact();
        else if (input.compare("SEARCH") == 0) {
            book.searchContact();
            book.searchPhone();
        }
            
        std::cout << "> " << std::flush;
        std::cin >> input;
    }

    return 0;
}