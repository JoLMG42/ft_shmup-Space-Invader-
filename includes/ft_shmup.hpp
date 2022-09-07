/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:56:46 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/07 18:33:36 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_HPP
# define FT_SHMUP_HPP

#include <vector>
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Pusher.hpp"
#include "ncurses.h"
#include "Missiles.hpp"
#include "Weapon.hpp"
#include "Objects.hpp"
#include <memory>
#include "Objects.hpp"
#include "Patrol.hpp"

// GLOBALS BECAUSE WE CAN <3
extern std::vector<Enemy>	g_enemies;
extern std::vector<Weapon> g_weapon;
extern std::vector<SpaceShip> g_allies;
extern std::vector<Objects>	g_objs;
extern std::vector<Pusher> g_pusher;
extern std::vector<Missiles> g_missiles;
extern std::vector<Patrol> g_patrol;

# define HARDMODE 1
# define PROBA_BOSS 100

# define FRAME_MS 16
//KEYS
# define KEY_ESC 27
# define KEY_CTRL_C 3
# define KEY_CTRL_D 4
# define KEY_SPACE 32
# define W 119	
# define A 97
# define S 115	
# define D 100	

//ALLIES
#define ALLY 1

#define ALLY_SHAPE ">"
#define ALLY_PM 0

//ENEMIES

#define ENEMY -1
#define ENEMY_BULLET_1 10
#define ENEMY_BULLET_2 5
#define ENEMY_BULLET_3 1

#define STAY 0
#define PUSHER 1
#define PATROL 2
#define PATROL_Z 3
#define PUSHER_Z 4
#define PUSHER_UP 5
#define PUSHER_DOWN 6
#define PATROL_DOWN 7

//ENEMIES SHAPES
#define PUSHER_SHAPE '<'
#define STAY_SHAPE '0'
#define PATROL_SHAPE '8'
#define PUSHER_Z_SHAPE 'Z'
#define PUSHER_UP_SHAPE '\\'
#define PUSHER_DOWN_SHAPE '/'
#define PATROL_DOWN_SHAPE '8'

//ENEMIES COSTS
#define STAY_PA 0
#define PUSHER_PA 300
#define PATROL_PA 300
#define PATROL_Z_PA 0
#define PUSHER_Z_PA 0
#define PUSHER_UP_PA 0
#define PUSHER_DOWN_PA 0
#define PATROL_DOWN_PA 0

#define STAY_PM 0
#define PUSHER_PM 60
#define PATROL_PM 30
#define PATROL_Z_PM 0
#define PUSHER_Z_PM 0
#define PUSHER_UP_PM 0
#define PUSHER_DOWN_PM 0
#define PATROL_DOWN_PM 0

//STARS

#define STAR 0
#define RED_STAR 1
#define YELLOW_STAR 2
#define METEOR 3
#define LIFE 4

#ifndef HP

#define HP 3

#endif

#define PUSHER_POINT 300
#define PATROL_POINT 50
#define BULLET_POINT 10

typedef struct g_data
{
	int loop;
	int phase;
	int score;
	int frags;
	int hp;
	int mode;
	int multi;
	int impossible;
	int cheat;
	int boss;
}		t_data;

extern t_data g_data;


int		ft_init_screen(void **window);
int		ft_spawn_phase_1(t_data &game);
int		ft_spawn_phase_2(t_data &game);
int		ft_spawn_phase_3(t_data &game);
int		ft_spawn_mobs(t_data &game);
void	ft_spawn_objs(t_data *game);
int		ft_secure_nodelay(void **window);
int		ft_menu(void *window, t_data *game);


#endif
