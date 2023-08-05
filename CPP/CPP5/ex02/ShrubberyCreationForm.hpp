#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form{

    public:

        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm( const ShrubberyCreationForm &rhs );
        ShrubberyCreationForm &   operator=(ShrubberyCreationForm const & rhs);
        ~ShrubberyCreationForm();

        const std::string    getTarget( void ) const;
        void    execute(Bureaucrat const & executor) const;

    private:

        std::string _target;
};

#endif