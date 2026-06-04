/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:28:47 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/04 20:39:26 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdio.h>

#include "defs.h"
#include "utils.h"

/* Returns the first wall hit position for a ray. */
t_point	trace_ray(t_game *game, float angle)
{
	t_point	p;

	p.x = game->player.position.x;
	p.y = game->player.position.y;
	while (!touch(game, p.x, p.y))
	{
		p.x += cos(angle);
		p.y += sin(angle);
	};
	return (p);
}

static float	distance(t_point a, t_point b)
{
	// Pythagorean Theorem
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
};

static t_ray	step_ray(t_game *game, t_ray ray, t_orientation orientation)
{
	const int	MAX_DOF = 24;
	int			depth_of_field = 0;
	int			map_x;
	int			map_y;

	while (depth_of_field < MAX_DOF)
	{
		map_x = (int)(floorf(ray.hit.x / BLOCK_SIZE));
		map_y = (int)(floorf(ray.hit.y / BLOCK_SIZE));
		if (orientation == WEST)
			map_x -= 1;
		if (orientation == NORTH)
			map_y -= 1;
		// Validate colision
		if (map_y >= 0 && map_y < game->map.height &&
			map_x >= 0 && map_x < game->map.width &&
			game->map.grid[map_y][map_x] == '1')
		{
			ray.dist = distance(game->player.position, ray.hit);
			return (ray);
		}
		ray.hit.x += ray.x_offset;
		ray.hit.y += ray.y_offset;
		depth_of_field++;
	}
	return (ray);
}

// === Horizontal Rays ===
t_ray calculate_ray_distance_h(t_game *game, float ray_angle)
{
	t_ray			ray;
	float			y_intercept;
	t_orientation	orientation;

	ray.dist = FLT_MAX;
	ray.step_ratio = 1.0f / tanf(ray_angle);
	// Looking UP
	if (ray_angle > degrees_to_radians(180))
	{
		y_intercept = floorf(game->player.position.y / BLOCK_SIZE) * BLOCK_SIZE;
		ray.y_offset = -BLOCK_SIZE;
		orientation = NORTH;
	}
	// Looking DOWN
	else if (ray_angle < degrees_to_radians(180))
	{
		y_intercept = floorf(game->player.position.y / BLOCK_SIZE) * BLOCK_SIZE
						+ BLOCK_SIZE;
		ray.y_offset = BLOCK_SIZE;
		orientation = SOUTH;
	}
	else
		return (ray);
	ray.x_offset = ray.y_offset * ray.step_ratio;
	// Calculate first hit location
	ray.hit.y = y_intercept;
	ray.hit.x = (ray.hit.y - game->player.position.y) * ray.step_ratio + game->player.position.x;
	return (step_ray(game, ray, orientation));
}

// Vertical rays
t_ray	calculate_ray_distance_v(t_game *game, float ray_angle)
{
	t_ray			ray;
	float			x_intercept;
	t_orientation	orientation;

	ray.dist = FLT_MAX;
	ray.step_ratio = tanf(ray_angle);
	if (ray_angle > degrees_to_radians(90) && ray_angle < degrees_to_radians(270)) // Looking left
	{
		x_intercept = floorf(game->player.position.x / BLOCK_SIZE) * BLOCK_SIZE;
		ray.x_offset = -64;
		orientation = WEST;
	}
	else if (ray_angle < degrees_to_radians(90) || ray_angle > degrees_to_radians(270)) // Looking right
	{
		printf("looking_right\n");
		x_intercept = floorf(game->player.position.x / BLOCK_SIZE) * BLOCK_SIZE + 64;
		ray.x_offset = 64;
		orientation = EAST;
	}
	else
		return (ray);
	// Calculate first hit location
	ray.y_offset = ray.x_offset * ray.step_ratio;
	ray.hit.x = x_intercept;
	ray.hit.y = (ray.hit.x - game->player.position.x) * ray.step_ratio + game->player.position.y;
	return (step_ray(game, ray, orientation));
}
