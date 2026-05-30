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

#include "defs.h"
#include "image.h"
#include "utils.h"

/* Draw a hollow square centered at (centerX, centerY). */
void	draw_square(t_game *game, int centerX, int centerY, int size, int color)
{
	int			row;
	int			column;
	const int	offset = size / 2;

	row = centerY - offset;
	while (row < centerY + offset)
	{
		column = centerX - offset;
		while (column < centerX + offset)
		{
			// Draw only the borders of the square.
			if (column == centerX - offset || column == centerX + offset - 1)
				my_mlx_pixel_put(game->img, column, row, color);
			if (row == centerY - offset || row == centerY + offset - 1)
				my_mlx_pixel_put(game->img, column, row, color);
			column++;
		};
		row++;
	};
}

/* Cast a single ray in the given direction and draw its path in 2D. */
static void	draw_ray(t_game *game, const float angle, const int color)
{
	t_point	ray_point;

	ray_point.x = game->player.position.x;
	ray_point.y = game->player.position.y;

	// Step forward until the ray hit a wall.
	while (!touch(game, ray_point.x, ray_point.y))
	{
		my_mlx_pixel_put(game->img, ray_point.x, ray_point.y, color);
		// Increment ray position using direction vector (angle).
		ray_point.x += cos(angle);
		ray_point.y += sin(angle);
	};
}

/* Render the 2D field of view (raycasting visualization). */
void	draw_2D_FOV(t_game *game, int color)
{
	// Angle difference between each ray (60° field of view).
	const float	angle_step = radians(60) / WIDTH;
	float		ray_angle;

	// Start from left edge of the FOV (player angle - 30°).
	ray_angle = game->player.angle - radians(30);

	int column = 0;
	while (column < WIDTH)
	{
		draw_ray(game, ray_angle, color);
		ray_angle += angle_step;
		column++;
	}
}

void	draw_map(t_game *game, int block_size, int color)
{
	int	column;
	int	row;
	int centerX;
	int centerY;
	const int offset = block_size / 2;

	row = 0;
	while (game->map && game->map[row] != NULL)
	{
		column = 0;
		centerY = (row * block_size) + offset;
		while (game->map[row][column] != '\0')
		{
			centerX = (column * block_size) + offset;
			if (game->map[row][column] == '1')
				draw_square(game, centerX, centerY, block_size, color);
			column++;
		}
		row++;
	}
};

void	draw_minimap(t_game *game)
{
	draw_map(game, BLOCK_SIZE / 4, BLUE);
};
