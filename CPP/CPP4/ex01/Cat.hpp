#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat( const Cat &copy );
		Cat &operator=( const Cat &copy );
		Animal &operator=( const Animal &copy );
		~Cat();

		void makeSound( void ) const;
		Brain *getBrain( void ) const;

	private:
		Brain	*_brain;
};

#endif