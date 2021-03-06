/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AssaultTerminator.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 19:03:00 by iboeters      #+#    #+#                 */
/*   Updated: 2020/12/11 16:42:09 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &)
{
	return ;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I’ll be back..." << std::endl;
	return ;
}

AssaultTerminator &	AssaultTerminator::operator=(AssaultTerminator const &)
{
	return (*this);
}

ISpaceMarine*		AssaultTerminator::clone(void) const
{
	return (new AssaultTerminator(*this));
}

void				AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
	return ;
}

void				AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void				AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
