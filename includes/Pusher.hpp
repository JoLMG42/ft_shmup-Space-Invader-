/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pusher.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:00:13 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/31 19:41:09 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHER_HPP

#define PUSHER_HPP

#include "ft_shmup.hpp"

class	Pusher: virtual public Enemy
{
	protected:
		int		_dmg;
		int		_speed_shot;
		int		_boss;
		void	shoot(void);
		virtual void	movement(void);
	public:
		Pusher(void);
		Pusher(int phase);
		Pusher(int x, int y);
		void	set_boss(int x);
		int	get_boss(void);
		~Pusher(void);
};

#endif
