#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class  RobotomyRequestForm : public Form{

    public:

         RobotomyRequestForm(void);
         RobotomyRequestForm(std::string target);
         RobotomyRequestForm( const  RobotomyRequestForm &rhs );
         RobotomyRequestForm &   operator=( RobotomyRequestForm const & rhs);
        ~ RobotomyRequestForm();

        const std::string    getTarget( void ) const;
        void    execute(Bureaucrat const & executor) const;

    private:

        std::string _target;
};

#endif