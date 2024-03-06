#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = other.fixedPointValue;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (float)this->fixedPointValue / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->fixedPointValue >> fractionalBits;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = other.fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

std::ostream& operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result.fixedPointValue = this->fixedPointValue + other.fixedPointValue;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result.fixedPointValue = this->fixedPointValue - other.fixedPointValue;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	result.fixedPointValue = (this->fixedPointValue * other.fixedPointValue) >> fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	result.fixedPointValue = (this->fixedPointValue << fractionalBits) / other.fixedPointValue;
	return result;
}

Fixed& Fixed::operator++(void)
{
	this->fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--(void)
{
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.fixedPointValue > b.fixedPointValue ? a : b;
}

