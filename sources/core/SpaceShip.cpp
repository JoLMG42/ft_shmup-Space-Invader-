/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:04:04 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/31 21:13:35 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>

SpaceShip::SpaceShip(void):_x(0),_y(0),_dir(ALLY)
{
	this->_cheat = 0;
	if (g_data.cheat)
		_cheat = 1;
	this->_ammos = 20;
	this->_shape = '>';
	return ;
}

SpaceShip::SpaceShip(int x, int y):_x(x),_y(y),_dir(ALLY)
{
	this->_cheat = 0;
	this->_ammos = 20;
	this->_shape = '>';
	return ;
}

SpaceShip::~SpaceShip(void)
{
	return ;
}

int	SpaceShip::get_X(void) const
{
	return (_x);
}

int	SpaceShip::get_Y(void) const
{
	return (_y);
}

void	SpaceShip::set_X(int x)
{
	_x = x;
}

void	SpaceShip::set_Y(int y)
{
	_y = y;
}

void	SpaceShip::set_ammos(int ammos)
{
	_ammos = ammos;
}

int	SpaceShip::get_ammos(void)
{
	return (_ammos);
}

void	SpaceShip::shoot(void)
{
	g_weapon.emplace_back(Weapon(this->_x, this->_y, this->_dir, '-'));
}

void	SpaceShip::movement(int input)
{
	if (get_ammos() < 20)
		set_ammos(get_ammos() + 1);
	if (input == KEY_DOWN && _x + 1 < LINES)
		++_x;
	if (input == KEY_UP && _x - 1 > 10)
		--_x;
	if (input == KEY_LEFT && _y - 1 > 0)
		--_y;
	if (input == KEY_RIGHT && _y + 1 < COLS)
		++_y;
}

void	SpaceShip::display_player_2(void *&window)
{
	if (_cheat)
	{
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y + 1 , this->_shape | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, '-' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, '-' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y, this->_shape | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y - 1, '-' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y - 1, '-' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, '-' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y + 1, this->_shape | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y - 2, '-' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y - 2, '|' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y - 2, '|' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y - 2, '|' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y - 1, '-' | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y, '-' | A_BOLD);
	}
	else
		mvwaddch((WINDOW *)window, this->_x, this->_y, this->_shape | A_BOLD);
}

void	SpaceShip::display(void *&window)
{
	if (_cheat)
	{
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y + 1 , this->_shape | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, '-' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, '-' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y, this->_shape | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y - 1, '-' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y - 1, '-' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y, '-' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y + 1, this->_shape | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y - 2, '-' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x + 1, this->_y - 2, '|' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x, this->_y - 2, '|' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y - 2, '|' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y - 1, '-' | COLOR_PAIR(5) | A_BOLD);
		mvwaddch((WINDOW *)window, this->_x - 1, this->_y, '-' | COLOR_PAIR(5) | A_BOLD);
	}
	else
		mvwaddch((WINDOW *)window, this->_x, this->_y, this->_shape | COLOR_PAIR(5) | A_BOLD);
}

void	SpaceShip::action(void *&window)
{
	(void)window;
}

void	SpaceShip::movement_player_2(int input)
{
	if (get_ammos() < 20)
		set_ammos(get_ammos() + 1);
	if (input == S && _x + 1 < LINES)
		++_x;
	if (input == W && _x - 1 > 10)
		--_x;
	if (input == A && _y - 1 > 0)
		--_y;
	if (input == D && _y + 1 < COLS)
		++_y;
}

void	SpaceShip::action_player_2(int input, void *&window)
{
	if (g_data.cheat)
		_cheat = 1;
	if (input == S || input == W || input == 97
		|| input == D)
		this->movement_player_2(input);
	if (input == 114)
	{
		set_ammos(get_ammos() - 1);
		shoot();
	}
	this->display_player_2(window);
}

void	SpaceShip::action(int input, void *&window)
{
	if (g_data.cheat)
		_cheat = 1;
	if (input == KEY_DOWN || input == KEY_UP || input == KEY_LEFT
		|| input == KEY_RIGHT)
		this->movement(input);
	if (input == KEY_SPACE && _ammos > 0)
	{
		set_ammos(get_ammos() - 1);
		shoot();
	}
	this->display(window);
}
