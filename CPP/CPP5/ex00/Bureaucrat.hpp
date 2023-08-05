#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>

class Bureaucrat {

    public:

        Bureaucrat(void);
        Bureaucrat( std::string name, unsigned int garde );
        Bureaucrat( const Bureaucrat &rhs );
        Bureaucrat &   operator=(Bureaucrat const & rhs);
        ~Bureaucrat();

        const std::string    getName( void ) const;
        unsigned int    getGrade( void ) const;
        void            incrementGrade(void);
        void            decrementGrade(void);

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

    private:

        const std::string _name;
        unsigned int _grade;
};

std::ostream& operator <<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif