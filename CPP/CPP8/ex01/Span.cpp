# include "Span.hpp"

Span::Span() {}

Span::Span(std::size_t N) : _size(N) {
    _v.reserve(_size);
}

Span::Span(Span const & rhs) {
    *this =rhs;
}

Span & Span::operator=(Span const & rhs) {
    _size = rhs.getSize();
    _v = rhs.getVector();
    return(*this);
}

Span::~Span() {}


std::size_t Span::getSize() const {
    return(_size);
}

std::vector<int> Span::getVector() const {
    return(_v);
}

void Span::addNumber(int nb) {
    if (_v.size() == _size)
        throw std::length_error("Span object is full");
    _v.push_back(nb);
}

int Span::shortestSpan() const {
    if (_v.size() < 2)
	{
		throw std::logic_error("Vector need to contain more than one element for this function to be called");
	}
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());

	int shortest = INT_MAX;
	for (size_t i = 1; i < tmp.size(); i++) 
	{
		int span = tmp[i] - tmp[i-1];
		shortest = std::min(shortest, span);
	}

    return shortest;
}

int Span::longestSpan() const
{
	if (_v.size() < 2)
	{
		throw std::logic_error("vector need to contain more than one element");
	}
	return (*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()) );
}

void Span::addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	if (this->getSize() < _v.size() + (std::distance(begin, end)))
	{
		throw std::length_error("Span object would be full");
	}
	_v.insert(_v.end(), begin, end);
}
