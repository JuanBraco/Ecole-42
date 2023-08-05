#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    /*const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;*/

    /*const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        animals[i]->makeSound();
        delete animals[i];
    }*/

    Dog dog;
    dog.getBrain()->printAllIdeas();

    Dog basic;

    Dog tmp = basic;

  	Animal* j = new Dog();
	std::cout << std::endl;
	Animal* i = new Dog();
	std::cout << std::endl;

	i->getBrain()->_ideas[0] = "miao";

	std::cout << i->getBrain()->_ideas[0] << std::endl;

	std::cout << j->getBrain()->_ideas[0] << std::endl;

	*j = *i;

	std::cout << i->getBrain()->_ideas[0] << std::endl;

	std::cout << j->getBrain()->_ideas[0] << std::endl;

	delete j;//should not create a leak
	delete i;


}