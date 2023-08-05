#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog( const Dog &copy );
		Dog &operator=( const Dog &copy );
		Animal &operator=( const Animal &copy );
		~Dog();

		void makeSound( void ) const;
		Brain *getBrain( void ) const;

	private:
		Brain	*_brain;
};

#endif