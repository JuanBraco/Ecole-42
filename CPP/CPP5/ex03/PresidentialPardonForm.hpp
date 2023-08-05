#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class  PresidentialPardonForm : public Form{

    public:

         PresidentialPardonForm(void);
         PresidentialPardonForm(std::string target);
         PresidentialPardonForm( const  PresidentialPardonForm &rhs );
         PresidentialPardonForm &   operator=( PresidentialPardonForm const & rhs);
        ~ PresidentialPardonForm();

        const std::string    getTarget( void ) const;
        void    execute(Bureaucrat const & executor) const;

    private:

        std::string _target;
};

#endif