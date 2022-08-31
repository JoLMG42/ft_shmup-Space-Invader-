/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:25:52 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/31 20:29:46 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"

Enemy::Enemy(void):_x (11+ (rand() % (LINES - 11))),_y (COLS - 1),_dir (ENEMY)
{
	int	random;
	
	random = rand() % 100 + 1;
	_velocity = 1;
	if (random  >= 80)
		_velocity = 3;
	if (random <= 100)
		_velocity = 8;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
}

Enemy::Enemy(int value):_x (11+ (rand() % (LINES - 11))),_y (COLS - 1),_dir (ENEMY)
{
	(void)value;
	int	random;

	random = rand() % LINES + 1;
	_y = COLS - 6;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
}

Enemy::Enemy(const char &shape):_shape(shape)
{
	_x = 11 + (rand() % (LINES - 11));
	_y = COLS - 1;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
}

Enemy::Enemy(int x, int y, int type)
{
	_x = x;
	_y = y;
	_type = type;
}

Enemy::Enemy(const Enemy &src)
{
	*this = src;
}

Enemy::~Enemy(void)
{
	return ;
}

int	Enemy::get_X(void) const
{
	return (_x);
}

void	Enemy::setType(int type)
{
	_type = type;
}

int	Enemy::get_Y(void) const
{
	return (_y);
}

void	Enemy::set_X(int x)
{
	_x = x;
}

void	Enemy::set_Y(int y)
{
	_y = y;
}

void	Enemy::generate_pa_pm(void)
{
	this->_pa++;
	this->_pm++;
}

void	Enemy::shoot(void)
{
	return ;
}	

void	Enemy::set_boss(int x)
{
	_boss = x;
}

int	Enemy::get_boss(void)
{
	return _boss;
}

void	Enemy::display(void *&window)
{
	if (get_boss() == 1)
	{
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y - 1, _shape | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y, '-' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y + 1, '-' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y + 2, '-' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y, _shape | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y + 1, '-' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x  +1, this->_y - 1, _shape | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, '-' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y + 1, '-' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y + 2, '-' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y + 2, '|' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y + 2, '|' | COLOR_PAIR(4) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y + 2, '|' | COLOR_PAIR(4) | A_BOLD);
	}
	else
		mvwaddch((WINDOW *)window, this->_x, this->_y, _shape | COLOR_PAIR(4) | A_BOLD);
}

void	Enemy::display(char shape, void *&window)
{
	if (get_boss() == 1)
	{
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y, shape | COLOR_PAIR(RED_STAR) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y, shape | COLOR_PAIR(RED_STAR) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, shape | COLOR_PAIR(RED_STAR) | A_BOLD);
	}
	else
		mvwaddch((WINDOW *)window, this->_x, this->_y, shape | COLOR_PAIR(RED_STAR) | A_BOLD);
}

void	Enemy::action(void *&window)
{
	generate_pa_pm();
	if (this->_pa >= this->_pa_cost)
		shoot();
	if (this->_pm >= this->_pm_cost)
		movement();
	this->display(window);
}

void	Enemy::movement(void)
{
	return ;
}
