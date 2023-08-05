#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>
# include "ICharacter.hpp"
# include "Character.hpp"

class Character;
class ICharacter;
class MateriaSource;
class IMateriaSource;

class AMateria
{
    protected:
        std::string type;
    public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &rhs);
    virtual ~AMateria( void );
    AMateria &operator=(const AMateria &other);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};
#endif