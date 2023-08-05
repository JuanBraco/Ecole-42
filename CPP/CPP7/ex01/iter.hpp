#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *arr, int length, void f(T&))
{
    if (length < 0)
        return;
    for(int i = 0; i < length; i++)
        f(arr[i]);
}

template<typename T>
void print(T &value)
{
	std::cout << value << std::endl;
}

#endif