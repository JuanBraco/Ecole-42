#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _NbMaterias(0)
{
	for (int i = 0; i < MateriaSource::_MateriaSize; i++)
		_Materias[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &copy )
{
	*this = copy;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &copy )
{
	for (int i = 0; i < MateriaSource::_MateriaSize; i++)
	{
		if (_Materias[i])
			delete _Materias[i];
		if (copy._Materias[i])
			_Materias[i] = copy._Materias[i]->clone();
		else
			_Materias[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MateriaSource::_MateriaSize; i++)
	{
		if (_Materias[i])
			delete	_Materias[i];
	}
}

void MateriaSource::learnMateria( AMateria *to_learn )
{
	if (_NbMaterias >= MateriaSource::_MateriaSize)
		/*std::cout << "MateriaSource is full" << std::endl;*/
		return;
	else
	{
		_Materias[_NbMaterias] = to_learn;
		_NbMaterias++;
		/*std::cout << "Learned " << to_learn->getType() << std::endl;*/
	}
}

AMateria *MateriaSource::createMateria( std::string const &type )
{
	for (int i = 0; i < MateriaSource::_MateriaSize && _Materias[i]; i++)
	{
		if (type == _Materias[i]->getType())
			return _Materias[i]->clone();
	}
	return NULL;
}

void MateriaSource::printMaterias( void ) const
{
	for (int i = 0; i < MateriaSource::_MateriaSize; i++)
	{
		if (_Materias[i])
			std::cout << i << ": " << _Materias[i]->getType() << std::endl;
		else
			std::cout << i << ": empty" << std::endl;
	}
}