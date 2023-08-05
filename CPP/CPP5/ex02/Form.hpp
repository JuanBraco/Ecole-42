#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public:

        Form(void);
        Form(std::string name, unsigned int gradeToExec, unsigned int gradeToSign);
        Form( const Form &rhs );
        Form &   operator=(Form const & rhs);
        virtual ~Form();

        const std::string    getName( void ) const;
        unsigned int    getGradeToSign( void ) const;
        unsigned int    getGradeToExec( void ) const;
        unsigned int    getStatus() const;
        void            beSigned(Bureaucrat const &obj);
        virtual void    execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
            const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char * what(void) const throw();
        };
        class FormNotSignedException : public std::exception
        {
            public:
            const char * what(void) const throw();
        };

    private:

        const std::string _name;
        const unsigned int _gradeToSign;
        const unsigned int _gradeToExec;
        bool    status;
};

std::ostream& operator <<(std::ostream &out, const Form &Form);

#endif