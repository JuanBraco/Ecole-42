#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class Character;
class ICharacter;
class MateriaSource;
class IMateriaSource;
class Materia;

class Character : public ICharacter
{
	public:
		Character( void );
		Character( std::string const &name );
		Character( Character const &copy );
		Character &operator=( const Character &copy );
		~Character( void );

		std::string const &getName() const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter &target );
		void inventory( void );

	private:
		std::string			_name;
		int				_NbItems;
		const static int	_inventorySize = 4;
		AMateria			*_inventory[4];
};

#endif