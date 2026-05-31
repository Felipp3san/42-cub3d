/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:53:19 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/31 15:37:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "utils.h"
#include "image.h"
#include "calculation.h"
#include "ray.h"

/* Draw a single vertical wall slice (one screen column). */
static void	draw_column(t_game *game, const float angle, int column)
{
	const t_point	ray_hit_point = trace_ray(game, angle);
	double			distance;
	double			wall_height;
	double			wall_start;
	double			wall_bottom;

	distance = fixed_distance(game->player.position, game->player.angle, ray_hit_point);

	// Project wall height based on distance.
	wall_height = (BLOCK_SIZE / distance) * ((float) WIDTH / 2);

	// Center the wall slice vertically on screen.
	wall_start = (HEIGHT - wall_height) / 2;
	wall_bottom = wall_start + wall_height;

	int start = 0;
	while (start < HEIGHT)
	{
		// Draw sky.
		if (start < wall_start)
			my_mlx_pixel_put(game->img, column, start, BLUE_SKY);
		// Draw walls.
		else if (start >= wall_start && start < wall_bottom)
			my_mlx_pixel_put(game->img, column, start, OFF_WHITE);
		// Draw floor.
		else
			my_mlx_pixel_put(game->img, column, start, CLEAR_GRAY);
		start++;
	}
}

/* Render the 3D field of view using raycasting. */
void	draw_3D_FOV(t_game *game)
{
	// Angle difference between each screen column ray.
	const float	angle_step = degrees_to_radians(60) / WIDTH;
	float		ray_angle;
	int			column;

	// Start from left edge of FOV (player angle - 30 degrees).
	ray_angle = game->player.angle - degrees_to_radians(30);
	column = 0;
	while (column < WIDTH)
	{
		draw_column(game, ray_angle, column);
		ray_angle += angle_step;
		column++;
	}
}

