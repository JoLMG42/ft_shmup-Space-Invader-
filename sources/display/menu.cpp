/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:32:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/31 16:00:39 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"

int	ft_menu(void *window, t_data *game)
{
	int	ch;

	mvwprintw((WINDOW *)window, 0, COLS / 2 - 29, "");
	mvwprintw((WINDOW *)window, 1, COLS / 2 - 29, "       __  _              _                              ");
	mvwprintw((WINDOW *)window, 2, COLS / 2 - 29, "      / _|| |_       ___ | |__   _ __ ___   _   _  _ __  ");
	mvwprintw((WINDOW *)window, 3, COLS / 2 - 29, "     | |_ | __|     / __|| '_ \\ | '_ ` _ \\ | | | || '_ \\ ");
	mvwprintw((WINDOW *)window, 4, COLS / 2 - 29, "     |  _|| |_      \\__ \\| | | || | | | | || |_| || |_) |");
	mvwprintw((WINDOW *)window, 5, COLS / 2 - 29, "     |_|   \\__|     |___/|_| |_||_| |_| |_| \\__,_|| .__/ ");
	mvwprintw((WINDOW *)window, 6, COLS / 2 - 29, "                                                 |_|    ");
	mvwprintw((WINDOW *)window, 7, COLS / 2 - 29, "");
	mvwprintw((WINDOW *)window, LINES / 2, COLS / 2 - 12,"press ENTER to continue");
	mvwprintw((WINDOW *)window, LINES / 2 + 1, COLS / 2 - 12,"press ESC to quit");
	mvwprintw((WINDOW *)window, LINES / 2 + 2, COLS / 2 - 12,"PRESS 1 FOR HARDMODE");
	mvwprintw((WINDOW *)window, LINES / 2 + 3, COLS / 2 - 12,"PRESS 2 FOR MULTIPLAYER MODE");
	mvwprintw((WINDOW *)window, LINES / 2 + 4, COLS / 2 - 12,"PRESS 3 FOR IMPOSSIBLE MODE");
	refresh();
	while ((ch = getch()))
	{
		if (ch == KEY_ESC)
			return (-1);
		if (ch == 10)
			return (0);
		if (ch == 49)
		{
			game->mode = 1;
			return (0);
		}
		if (ch == 50)
		{
			game->mode = 2;
			game->multi = 1;
			return (0);
		}
		if (ch == 51)
		{
			game->mode = 3;
			game->impossible = 1;
			return (0);
		}
	}
	return (0);
}
