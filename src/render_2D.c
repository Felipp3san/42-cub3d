/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2D.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:17:33 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 12:32:47 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

#include "defs.h"
#include "image.h"
#include "utils.h"
#include "ray.h"

/* Draw a hollow square centered at (centerX, centerY). */
void	draw_square(t_game *game, t_point position, float size, int color, bool filled)
{
	int			row;
	int			column;
	const float	offset = size / 2.0f;
	const float	top = (int)floorf(position.y - offset);
	const float	bottom = (int)floorf(position.y + offset);
	const float	left = (int)floorf(position.x - offset);
	const float	right = (int)floorf(position.x + offset);

	row = top;
	while (row <= bottom)
	{
		column = left;
		while (column <= right)
		{
			if (!filled && (column == left || column == right || row == top || row == bottom))
				my_mlx_pixel_put(game->img, column, row, color);
			else if (filled)
				my_mlx_pixel_put(game->img, column, row, color);
			column++;
		};
		row++;
	};
}

/* Draw the ray from origin to destination. */
static void	draw_ray(t_game *game, t_point origin, t_point destination, int color)
{
	const float	dx = destination.x - origin.x;
	const float	dy = destination.y - origin.y;
	const float	steps = fmaxf(fabsf(dx), fabsf(dy));
	float		x;
	float		y;
	int			i;

	x = origin.x;
	y = origin.y;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(game->img, (int)x, (int)y, color);
		x += dx / steps;
		y += dy / steps;
		i++;
	}
}

void	draw_2D_FOV(t_game *game)
{
	float	ray_angle;
	int		rays;
	t_ray	h_ray;
	t_ray	v_ray;

	ray_angle = normalize_angle(game->player.angle - degrees_to_radians(30));
	rays = 0;
	while (rays < 60)
	{
		h_ray = calculate_ray_distance_h(game, ray_angle);
		v_ray = calculate_ray_distance_v(game, ray_angle);
		if (v_ray.dist < h_ray.dist)
			draw_ray(game, game->player.position, v_ray.hit, BLUE);
		else
			draw_ray(game, game->player.position, h_ray.hit, BLUE);
		ray_angle = normalize_angle(ray_angle + degrees_to_radians(1));
		rays++;
	}
}

/* Draws the player square and a line indicating the view direction. */
void	draw_player(t_game *game, int color)
{
	t_point	destination;

	draw_square(game, game->player.position, PLAYER_SIZE, color, true);

	destination.x = game->player.position.x + cos(game->player.angle) * 10;
	destination.y = game->player.position.y + sin(game->player.angle) * 10;

	draw_ray(game, game->player.position, destination, GREEN);
}

/* Draws the map in 2D vision. */
void	draw_map(t_game *game, float block_size)
{
	int			column;
	int			row;
	t_point		position;
	const float	offset = (block_size / 2);

	row = 0;
	while (game->map.grid && game->map.grid[row] != NULL)
	{
		column = 0;
		position.y = (row * block_size) + offset;
		while (game->map.grid[row][column] != '\0')
		{
			position.x = (column * block_size) + offset;
			if (game->map.grid[row][column] == '1')
				draw_square(game, position, block_size - 1, RED, false);
			else
				draw_square(game, position, block_size - 1, WHITE, false);
			column++;
		}
		row++;
	}
};

//void	draw_minimap(t_game *game)
//{
	//draw_map(game, BLOCK_SIZE / 4);
//};
