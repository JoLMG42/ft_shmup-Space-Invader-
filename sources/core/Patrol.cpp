/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patrol.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:36:23 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/31 15:50:46 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include "Patrol.hpp"

Patrol::Patrol(void): Enemy('8')
{
	this->_move = 0;
	this->_shape = "<-\n |\n |";
	this->_pa_cost = PATROL_PA;
	this->_pm_cost = PATROL_PM;
}

Patrol::~Patrol(void)
{
	return ;
}

/*void	Patrol::action(void *&window)
{
	generate_pa_pm();
	if (this->_pa >= this->_pa_cost)
		ft_shoot(get_X(), get_Y(), window);
	if (this->_pm >= this->_pm_cost)
		movement();
}*/

void	Patrol::shoot(void)
{
	g_missiles.emplace_back(Missiles());
	return ;
}

void	Patrol::go_front(void *window)
{
	this->set_Y(get_Y() - 1);
	this->display(window);
}

void	Patrol::movement(void)
{
	if (this->_pm >= this->_pm_cost)
	{
		if (_move == 0)
			this->set_X(get_X() - 1);
		if (_move == 1)
			this->set_X(get_X() + 1);
		if (this->get_X() - 1 <= 10)
			_move = 1;
		if (this->get_X() + 1 >= LINES)
			_move = 0;
		this->_pm -= this->_pm_cost;
	}
	return ;
}
