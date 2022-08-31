/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:05:54 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 15:14:15 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define WEAPON_HPP

#include "ft_shmup.hpp"

class	Weapon: public SpaceShip
{
	protected:
		//int	_hp;
		//int	_speed;
		int	_pm;
		int	_pm_cost;
		Weapon(void);
		void	generate_pm(void);
		void	movement(void);
	public:
		Weapon(int x, int y, int dir, char shape);
		~Weapon(void);
		int	get_X_M(SpaceShip ally);
		int	get_Y_M(SpaceShip ally);
		int	get_X_M(Enemy enemy);
		int	get_Y_M(Enemy enemy);
		void	action(void *&window);
};

#endif
