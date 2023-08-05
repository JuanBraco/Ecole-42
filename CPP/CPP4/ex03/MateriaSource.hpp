#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP


# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource &copy );
		MateriaSource &operator=( const MateriaSource &copy );
		~MateriaSource( void );

		virtual void learnMateria( AMateria *to_learn );
		virtual AMateria *createMateria( std::string const &type );
		void printMaterias( void ) const;

	private:
		const static int	_MateriaSize = 4;
		AMateria			*_Materias[MateriaSource::_MateriaSize];
		int				_NbMaterias;
};

#endif