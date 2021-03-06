/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/10 11:37:47 by iboeters      #+#    #+#                 */
/*   Updated: 2020/12/01 16:07:15 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->raw_bits = 0;
	return ;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	std::cout << "Int before shifting = " << std::endl << std::bitset<32>(n) << std::endl;
	this->raw_bits = n << this->frac_bits;
	std::cout << "Int after shifting= " << std::endl << std::bitset<32>(this->raw_bits) << std::endl;
	return ;
}

Fixed::Fixed(float n)
{
	std::cout << "Float constructor called" << std::endl;
	std::cout << "Float before = " << std::endl << std::bitset<32>(n) << std::endl;
	this->raw_bits = roundf(n * (1 << this->frac_bits));
	std::cout << "Float after shifting = " << std::endl << std::bitset<32>(this->raw_bits) << std::endl;

	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int					Fixed::getRawBits(void) const
{
	return (this->raw_bits);
}

void				Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
	return ;
}

int					Fixed::toInt(void) const{
	return (this->raw_bits >> this->frac_bits);
}

float				Fixed::toFloat(void) const
{
	return ((float)this->raw_bits / (1 << this->frac_bits));
}

Fixed &				Fixed::operator=(Fixed const & rsh)
{
	std::cout << "Assignation operator called" << std::endl;
	this->raw_bits = rsh.getRawBits();
	
	return (*this);
}

std::ostream &		operator<<(std::ostream & output, Fixed const &rhs)
{
	output << rhs.toFloat();
	return output;
}
