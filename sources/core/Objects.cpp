/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:37:16 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 22:48:26 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"

Objects::Objects(int type)
{
	int	random;

	random = rand() % 100 + 1;
	_c = type;
	_s = '.';
	if (random >= 98 && type != LIFE)
	{
		_s = '0';
		_c = METEOR;
	}
	else if (type == LIFE)
	{
		_s = '$';
		_c = COLOR_RED;
	}
	_v = rand() % 3  + 1;
	_x = rand() % LINES + 1;
	if (_x <= 10)
		_x += 20;
	_y = COLS - 6;
}

Objects::~Objects(void)
{
	return ;
}

int	Objects::get_X_O(void)
{
	return _x;
}

int	Objects::get_Y_O(void)
{
	return _y;
}

int	Objects::get_C(void)
{
	return _c;
}

int	Objects::get_S(void)
{
	return _s;
}

void	Objects::aff_obj()
{
	_x = get_X_O();
	_y = get_Y_O() - _v;
}

void	ft_spawn_objs(t_data *game)
{
	int	random;

	(void)game;
	random = rand() % 100 + 1;
	if (random == 100)
		g_objs.push_back(Objects(LIFE));
	if (random <= 20)
		g_objs.push_back(Objects(RED_STAR));
	if (random >= 80)
		g_objs.push_back(Objects(YELLOW_STAR));
	g_objs.push_back(Objects(STAR));
}
