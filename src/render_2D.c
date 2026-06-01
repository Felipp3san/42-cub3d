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
#include <stdlib.h>
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

static void	draw_ray(t_game *game, t_point origin, t_point destination, const int color)
{
	const int	distance_x = abs(destination.x - origin.x);
	const int	distance_y = abs(destination.y - origin.y);
	int			sx = (origin.x < destination.x) ? 1 : -1;
	int			sy = (origin.y < destination.y) ? 1 : -1;
	int			err = distance_x - distance_y;
	int 		e2;
	t_point		current;

	current = origin;
	err = distance_x - distance_y;
	while (true)
	{
		my_mlx_pixel_put(game->img, current.x, current.y, color);
		if (current.x == destination.x && current.y == destination.y)
			break;
		e2 = 2 * err;
		if (e2 > -distance_y)
		{
			err -= distance_y;
			current.x += sx;
		}
		if (e2 <  distance_x)
		{
			err += distance_x;
			current.y += sy;
		}
	}
}

float	distance(t_point a, t_point b)
{
	// Pythagorean Theorem
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - b.y) * (b.y - a.y)));
};

void	draw_rays(t_game *game)
{
	const int	MAX_DOF = 24;
	float	ray_angle;
	float	x_offset;
	float	y_offset;
	int		depth_of_field;
	int		map_x;
	int		map_y;
	int		rays;
	bool	side = false;

	ray_angle = game->player.angle - degrees_to_radians(30);
	rays = 0;
	while (rays < 20)
	{
		// === Horizontal Rays ===
		// For each step in Y, how much should i move X?
		t_point	h_hit;
		float	distH = 100000000;
		float	x_step_per_y = -1.0f / tan(ray_angle);
		depth_of_field = 0;
		if (ray_angle > degrees_to_radians(180)) // Looking down
		{
			// Get the next grid starting position from the player position.
			// - If the player is at position 80, the next grid starts at position 128.
			h_hit.y = (((int) game->player.position.y >> 6) << 6) - 0.0001;
			h_hit.x = (game->player.position.y - h_hit.y) * x_step_per_y + game->player.position.x;
			y_offset = -64;
			x_offset = -y_offset * x_step_per_y;
		}
		if (ray_angle < degrees_to_radians(180)) // Looking up
		{
			h_hit.y = (((int)game->player.position.y >> 6) << 6) + 64;
			h_hit.x = (game->player.position.y - h_hit.y) * x_step_per_y + game->player.position.x;
			y_offset = 64;
			x_offset = -y_offset * x_step_per_y;
		}
		if (ray_angle == 0 || ray_angle == degrees_to_radians(180)) // Looking straight left or right
		{
			// The ray will never intercept any horizontal grid lines.
			h_hit.x = game->player.position.x;
			h_hit.y = game->player.position.y;
			depth_of_field = MAX_DOF; // Set to max to skip loop.
		}

		while (depth_of_field < MAX_DOF)
		{
			map_x = (int)((h_hit.x - 1) / BLOCK_SIZE);
			map_y = (int)(h_hit.y / BLOCK_SIZE);
			// If hit a wall, stop.
			if (map_y >= 0 && map_y < game->map.height &&
				map_x >= 0 && map_x < game->map.width &&
				game->map.grid[map_y][map_x] == '1')
			{
				distH = distance(game->player.position, h_hit);
				depth_of_field = MAX_DOF;
			}
			// If not, add offset to intersect position.
			else
			{
				h_hit.x += x_offset;
				h_hit.y += y_offset;
			}
			depth_of_field++;
		}

		// === Vertical Rays ===
		t_point	v_hit;
		float	distV = 100000000;
		float	y_step_per_x = -tan(ray_angle);
		if (ray_angle > degrees_to_radians(90) && ray_angle < degrees_to_radians(270)) // Looking left
		{
			// Get the next grid starting position from the player position.
			// - If the player is at position 80, the next grid starts at position 128.
			v_hit.x = (((int) game->player.position.x >> 6) << 6) - 0.0001;
			v_hit.y = (game->player.position.x - v_hit.x) * y_step_per_x + game->player.position.y;
			x_offset = -64;
			y_offset = -x_offset * y_step_per_x;
			side = true;
		}
		if (ray_angle < degrees_to_radians(90) || ray_angle > degrees_to_radians(270)) // Looking right
		{
			v_hit.x = (((int)game->player.position.x >> 6) << 6) + 64;
			v_hit.y = (game->player.position.x - v_hit.x) * y_step_per_x + game->player.position.y;
			x_offset = 64;
			y_offset = -x_offset * y_step_per_x;
		}
		if (ray_angle == 90 || ray_angle == degrees_to_radians(270)) // Looking straight up or down
		{
			// The ray will never intercept any horizontal grid lines.
			v_hit.x = game->player.position.x;
			v_hit.y = game->player.position.y;
			depth_of_field = MAX_DOF; // Set to max to skip loop.
		}

		depth_of_field = 0;
		while (depth_of_field < MAX_DOF)
		{
			map_x = (int)(v_hit.x / BLOCK_SIZE);
			map_y = (int)((v_hit.y - 1) / BLOCK_SIZE);
			// If hit a wall, stop.
			if (map_y >= 0 && map_y < game->map.height &&
				map_x >= 0 && map_x < game->map.width &&
				game->map.grid[map_y][map_x] == '1')
			{
				distV = distance(game->player.position, v_hit);
				depth_of_field = MAX_DOF;
			}
			// If not, add offset to intersect position.
			else
			{
				v_hit.x += x_offset;
				v_hit.y += y_offset;
			}
			depth_of_field++;
		}
		if (distV < distH)
			draw_ray(game, game->player.position, v_hit, BLUE);
		else
			draw_ray(game, game->player.position, h_hit, BLUE);
		ray_angle += degrees_to_radians(60) / 20;
		rays++;
	}
}

void	draw_player(t_game *game, int color)
{
	t_point	destination;

	draw_square(game, game->player.position.x, game->player.position.y, PLAYER_SIZE, color);

	destination.x = game->player.position.x + cos(game->player.angle) * 10;
	destination.y = game->player.position.y + sin(game->player.angle) * 10;

	draw_ray(game, game->player.position, destination, GREEN);
}

/* Render the 2D field of view (raycasting visualization). */
//void	draw_2D_FOV(t_game *game, int color)
//{
//	// Angle difference between each ray (60° field of view).
//	const float	angle_step = degrees_to_radians(60) / WIDTH;
//	float		ray_angle;
//
//	// Start from left edge of the FOV (player angle - 30°).
//	ray_angle = game->player.angle - degrees_to_radians(30);
//
//	int column = 0;
//	while (column < WIDTH)
//	{
//		draw_ray(game, ray_angle, color);
//		ray_angle += angle_step;
//		column++;
//	}
//}

void	draw_map(t_game *game, int block_size)
{
	int	column;
	int	row;
	int centerX;
	int centerY;
	const int offset = block_size / 2;

	row = 0;
	while (game->map.grid && game->map.grid[row] != NULL)
	{
		column = 0;
		centerY = (row * block_size) + offset;
		while (game->map.grid[row][column] != '\0')
		{
			centerX = (column * block_size) + offset;
			if (game->map.grid[row][column] == '1')
				draw_square(game, centerX, centerY, block_size - 1, RED);
			else
				draw_square(game, centerX, centerY, block_size - 1, WHITE);
			column++;
		}
		row++;
	}
};

void	draw_minimap(t_game *game)
{
	draw_map(game, BLOCK_SIZE / 4);
};
