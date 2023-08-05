#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    /*const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j;//should not create a leak
    delete i;*/

    /*const AAnimal* Aanimals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        Aanimals[i]->makeSound();
        delete Aanimals[i];
    }*/

    Dog dog;
    dog.getBrain()->printAllIdeas();

    Dog basic;

    Dog tmp = basic;

  	AAnimal* j = new Dog();
	std::cout << std::endl;
	AAnimal* i = new Dog();
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