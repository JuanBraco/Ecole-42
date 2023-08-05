#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Brain {

    public:

        Brain(void);
        Brain( const Brain &rhs );
        Brain &   operator=(Brain const & rhs);
        ~Brain();

        void    setIdea(unsigned int index, std::string str);
        std::string    getIdea(unsigned int index) const;
        void    printAllIdeas(void) const;
        std::string _ideas[100];

    private:

        
};

#endif