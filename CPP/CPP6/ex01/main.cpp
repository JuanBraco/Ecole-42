#include "Serializer.hpp"

int main(void) {
    Data *Book = new Data;
	Book->str = "Dictionnary";
	std::cout << Book->getStr() << std::endl;
	uintptr_t ser = Serializer::serialize(Book);
	Data *Livre = Serializer::deserialize(ser);
	std::cout << Livre->getStr() << std::endl;
    std::cout << "Book : " << Book << std::endl;
    std::cout << "serialized : " << ser << std::endl;
    std::cout << "derialized : " << Livre << std::endl;
	delete Book;

    return 0;
}