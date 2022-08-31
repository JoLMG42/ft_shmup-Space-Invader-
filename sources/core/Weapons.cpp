/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapons.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:22:07 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/31 15:41:14 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include "Weapon.hpp"

Weapon::Weapon(void): _pm(0),_pm_cost(ALLY_PM)
{
	this->_ammos--;
	this->_shape = '-';
	return ;
}

Weapon::Weapon(int x, int y, int dir, char shape): _pm(0), _pm_cost(1)
{
	this->_x = x;
	this->_y = y;
	this->_dir = dir;
	this->_shape = shape;
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::generate_pm(void)
{
	++this->_pm;
}

void	Weapon::movement(void)
{
	if (_pm >= _pm_cost)
	{
		++_y;
		_pm -= _pm_cost;
	}
	return ;
}

void	Weapon::action(void *&window)
{
	this->generate_pm();
	this->movement();
	this->display(window);
}
