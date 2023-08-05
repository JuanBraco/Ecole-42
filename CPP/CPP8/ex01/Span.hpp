#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <vector>
# include <list>
# include <iterator>
# include <exception>
# include <stdexcept>
# include <climits>

class Span {

public :
    Span(std::size_t N);
    ~Span();
    Span & operator=(Span const & rhs);
    Span(Span const & rhs);

    void addNumber(int nb);
    int shortestSpan() const;
    int longestSpan() const;
    void addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);

    std::size_t getSize() const;
    std::vector<int> getVector() const;

private :
    Span();
    std::size_t _size;
    std::vector<int> _v;

};


#endif