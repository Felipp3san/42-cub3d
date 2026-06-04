/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:53:19 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/04 22:59:59 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "utils.h"
#include "image.h"
#include "ray.h"

/* Draw a single vertical wall slice (one screen column). */
static void	draw_column(t_game *game, t_ray ray, int column, bool vertical)
{
	float	wall_height;
	float	wall_start;
	float	wall_bottom;

	// Project wall height based on distance.
	wall_height = ((float)BLOCK_SIZE / ray.dist) * ((float)WIDTH / 2);

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
		{
			if (vertical)
				my_mlx_pixel_put(game->img, column, start, WARM_OFF_WHITE);
			else
				my_mlx_pixel_put(game->img, column, start, DARKER_OFF_WHITE);
		}
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
	t_ray		h_ray;
	t_ray		v_ray;
	int			column;

	ray_angle = normalize_angle(game->player.angle - degrees_to_radians(30));
	column = 0;
	while (column < WIDTH)
	{
		h_ray = calculate_ray_distance_h(game, ray_angle);
		v_ray = calculate_ray_distance_v(game, ray_angle);
		if (v_ray.dist < h_ray.dist)
			draw_column(game, v_ray, column, true);
		else
			draw_column(game, h_ray, column, false);
		ray_angle = normalize_angle(ray_angle + angle_step);
		column++;
	}
}
