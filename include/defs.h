/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:50:12 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/31 22:23:02 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <stdbool.h>

# define ERROR -1
# define OK 0

# define NAME "Cub3d"
# define WIDTH 1980
# define HEIGHT 1024

# define W 119
# define A 97
# define S 115
# define D 100
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define SPEED 4
# define ANGLE_SPEED 0.05

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define YELLOW 0x00FFFF00
# define CHARCOAL 0x001C1C1C
# define MIDNIGHT_NAVY 0x00151922
# define OFF_WHITE 0x00F5F7FA
# define ASH_WOOD 0x00E3DCD2
# define BLUE_SKY 0x0090CAF9
# define CLEAR_GRAY 0x007D7F7C

# define BLOCK_SIZE 64
# define PLAYER_SIZE 20

typedef enum e_direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
}	t_direction;

typedef enum e_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEAST
}	t_orientation;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	t_point	position;
	float	angle;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	bool		re_render;
	t_img		*img;
	t_player	player;
	t_map		map;
	t_keys		keys;
}	t_game;

#endif
