/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pusher.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:45:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/31 21:14:28 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include "Pusher.hpp"
#include "Pusher.hpp"

Pusher::Pusher(void): Enemy('<')
{
	int	random;
	static	int count;

	random = rand() % 100 + 1;
	this->_velocity = 1;
	this->_speed_shot = 1;
	if (random >= 70)
	{
		this->_velocity = 2;
		this->_speed_shot = 5;
	}
	if (random >= 97)
	{
		this->_velocity =  3;	
		this->_speed_shot = 7;
	}
	this->_shape = '<';
	if (random >= PROBA_BOSS && _x > 11)
	{
		this->_boss = 1;
		this->_velocity = 2;
		this->_speed_shot = 5;
	}
	if (count == 100)
	{
		this->_boss = 1;
		this->_velocity = 2;
		this->_speed_shot = 5;
		count = 0;
	}
	count++;
	this->_pa_cost = PUSHER_PA;
	this->_pm_cost = PUSHER_PM;
}

Pusher::~Pusher(void)
{
	return ;
}

void	Pusher::shoot(void)
{
	this->_pa -= this->_pa_cost;
	g_missiles.emplace_back(Missiles(_x, _y));
	return ;
}

void	Pusher::set_boss(int x)
{
	_boss = x;
}

int	Pusher::get_boss(void)
{
	return _boss;
}

void	Pusher::movement(void)
{
	if (_pm >= _pm_cost)
	{
		_y -= _velocity;
		_pm -= _pm_cost;
	}
	return ;
}
