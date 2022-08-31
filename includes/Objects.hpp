/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:12:32 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 15:17:39 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_HPP

#define OBJECTS_HPP

#include "ft_shmup.hpp"

class	Objects
{
	private:
		int	_x;
		int	_y;
		int	_c;
		int	_v;
		int	_s;
	public:
		Objects(int type);
		~Objects(void);
		void	aff_obj(void);
		int	get_X_O(void);
		int	get_Y_O(void);
		int	get_C(void);
		int	get_S(void);
};

#endif
