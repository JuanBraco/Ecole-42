#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>

# include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern {

    public:

        Intern(void);
        Intern( const Intern &rhs );
        Intern &   operator=(Intern const & rhs);
        ~Intern();

        Form*            makeForm(const std::string formName, std::string target);

        class FormInexistantException : public std::exception
        {
            public:
            const char * what(void) const throw();
        };

    private:

};

#endif