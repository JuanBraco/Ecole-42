#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <vector>
# include <list>
# include <iterator>
# include <exception>
# include <stdexcept>
# include <climits>

class RPN {

    private:
    	std::list<int> _numbers;
    public:
        RPN();
        RPN(const RPN& rpn);
        RPN& operator=(const RPN& rpn);
        ~RPN();

        std::list<int> getNUmbers() const;
        void    processInput(std::string expression);
       int      calculate(int operand1, int operand2, char c);
        bool    isOperator(char c);

};


#endif