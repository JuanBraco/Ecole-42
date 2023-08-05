#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <list>
# include <vector>
# include <iterator>

template < typename T >
typename T::iterator	easyfind(T& container, int value)
{
	return (std::find(container.begin(), container.end(), value));
}

#endif