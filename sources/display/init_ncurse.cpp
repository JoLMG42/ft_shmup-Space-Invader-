/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurse.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:52:25 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 19:44:07 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <iostream>
#include <ncurses.h>

int	ft_init_screen(void **window)
{
	*window = initscr();
	if (*window == NULL)
		return (1);
	if (raw() || noecho()
			|| keypad((WINDOW*)*window, TRUE))
	{
		endwin();
		delscreen((SCREEN *)*window);
		std::cout << "Screen initialization went wrong" << std::endl;
		exit (1);
		return (1);
	}
	curs_set(0);
	return (0);
}

int	ft_secure_nodelay(void **window)
{
	if (nodelay((WINDOW *)*window, TRUE))
	{
		endwin();
		delscreen((SCREEN *)*window);
		std::cout << "Screen initialization went wrong" << std::endl;
		exit (1);
	}
	return (0);
}
