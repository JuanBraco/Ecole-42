#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& rpn)
{
    *this = rpn;
}

RPN& RPN::operator=(const RPN& rpn)
{
    this->_numbers = rpn._numbers;
	return *this;
}

std::list<int> RPN::getNUmbers() const
{
    return this->_numbers;
}

void	RPN::processInput(std::string expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		if (isdigit(expression[i]))
			this->_numbers.push_front(expression[i] - '0');
		else if (isOperator(expression[i]))
		{
			if (this->_numbers.size() < 2)
			{
				while (!this->_numbers.empty())
					this->_numbers.pop_front();
				break;
			}
			int operand2 = this->_numbers.front();
			this->_numbers.pop_front();
			this->_numbers.front() = calculate(this->_numbers.front(), operand2, expression[i]);
		}
		else if (isspace(expression[i]))
			continue;
		else
			throw std::invalid_argument("Invalid Expression");
	}
}

int	RPN::calculate(int operand1, int operand2, char c)
{
	switch (c)
	{
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
		{
			if (!operand2)
				throw std::runtime_error("Division By Zero");
			return operand1 / operand2;
		}
	}
	return (0);
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}