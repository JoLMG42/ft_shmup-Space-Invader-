/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patrol.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:35:28 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 18:17:48 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATROL_HPP

#define PATROL_HPP

#include "ft_shmup.hpp"

class	Patrol:public Enemy
{
	private:
		int		_move;
		int		_max;
		int		_dmg;
		std::string	_shape;
		void	shoot(void);
		void	movement(void);
	public:
		Patrol(void);
		Patrol(int phase);
		Patrol(int x, int y);
		void	go_front(void *window);
		~Patrol(void);
};

#endif
