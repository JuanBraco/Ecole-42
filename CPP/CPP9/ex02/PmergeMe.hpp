#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>
#include <climits>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<long> _vect;
        std::deque<long> _deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& res);
        PmergeMe& operator=(const PmergeMe& res);
        ~PmergeMe();

        std::vector<long>	getVect() const;
        std::deque<long>		getDeque() const;
        void				fillContainers(char **argv, int argc);
        void				printSequence();
        bool				CheckErrors();
		void				merge_insert_sort_vector(int left, int right);
		void				merge_sort_vector(int left, int middle, int right);
        void                insertion_sort_vector(int left, int right);
		
		void				merge_insert_sort_deque(int left, int right);
		void                insertion_sort_deque(int left, int right);
		void				merge_sort_deque(int left, int middle, int right);
		bool				numbersOnly(std::string str);
		void				startProgram(int argc, char *argv[]);
};


#endif