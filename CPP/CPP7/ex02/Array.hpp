#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array
{
    private:
        T*				_array;
        unsigned int	_len;

    public:
        Array(void) : _array(NULL), _len(0)
        {
            std::cout << "Array Default constructor called." << std::endl;
        }

        Array(unsigned int n) : _len( n )
        {
            if(_len < 0)
                throw Array<T>::IndexOutOfRange();
            _array = new T[n];
        }


        Array<T>(const Array<T> &rhs)
        {
            _len = rhs.size();
            _array = new T[_len];
            for(unsigned int i = 0; i < _len; i++)
                _array[i] = rhs[i];
        }

        ~Array()
        {
            std::cout << "Array Default destructor called." << std::endl;
            if (_len >= 0)
                delete [] _array;
            this->_array = NULL;
        }

        Array<T>& operator=(const Array<T>& obj)
        {
            std::cout << "Array operator= called" << std::endl;
            if(this == &obj)
                return *this;
            if(this->_len > 0)
                delete [] this->_array;
            this->_array = NULL;
            this->_len = obj._len;
            this->_array = new T[this->_len];
            for(unsigned int i = 0; i < this->_len; i++)
                _array[i] = obj[i];
            return (*this);
        }

        unsigned int size(void) const
        {
            return (this->_len);
        }

        T& operator[] (unsigned int i) const
        {
            if (i >= this->_len || i < 0)
            {
                throw Array<T>::IndexOutOfRange();
            }
            return (this->_array[i]);
        }

        class IndexOutOfRange: public std::exception
        {
            public:
                virtual const char* what() const throw() {return "array: index out of range";};
        };
};

#endif