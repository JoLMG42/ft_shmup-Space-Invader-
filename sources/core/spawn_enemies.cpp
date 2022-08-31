/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemies.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:53:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/31 17:42:05 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include <vector>

int ft_spawn_phase_1(t_data *game)
{
	int	decision;

	decision = rand() % 100 + 1;
	if (game->impossible)
		if ((game->loop % 4 == 0))
			g_patrol.emplace_back(Patrol());
	if ((game->loop % (60 * 2) == 0))
		g_pusher.emplace_back(Pusher());
	if ((game->loop % (60 * 6) == 0))
		g_pusher.emplace_back(Pusher());
	//if ((game->loop % (60 * 2) == 0))
	//	g_patrol.emplace_back(Patrol());
	//if ((game->loop % (60 * 8) == 0) && g_enemies.size() <= 10)
	//{
		//if (decision == 1)
			//g_enemies.push_back(Enemy(PATROL));
		//else
			//g_enemies.push_back(Enemy(PATROL_Z));
	//}
	return (0);
	(void)game;
}

int ft_spawn_phase_2(t_data *game)
{
	ft_spawn_phase_1(game);
	if ((game->loop % (60 * 5) == 0))
		g_pusher.emplace_back(Pusher());
	if ((game->loop % (60 * 6) == 0))
		g_pusher.emplace_back(Pusher());
	return (0);
}

int ft_spawn_phase_3(t_data *game)
{
	ft_spawn_phase_2(game);
	if ((game->loop % 4 == 0))
		g_pusher.emplace_back(Pusher());
	if ((game->loop % 2 == 0))
		g_pusher.emplace_back(Pusher());
	return (0);
}

int	ft_spawn_mobs(t_data &game)
{
	if (game.phase == 1)
		ft_spawn_phase_1(&game);
	if (game.phase == 2)
		ft_spawn_phase_2(&game);
	if (game.phase == 3)
		ft_spawn_phase_3(&game);
	return (0);
}
