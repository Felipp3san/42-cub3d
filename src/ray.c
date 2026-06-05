/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:28:47 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/05 15:21:32 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>

#include "defs.h"
#include "utils.h"

/* Calculates the distance between two points. */
static float	distance2(float x, float y){
	return sqrt(x * x + y * y);
}

/* Correction for distance calculation to avoid fish-eye effect. */
static float	fixed_distance(t_point start, t_point end, float angle)
{
	const float	delta_x = end.x - start.x;
	const float	delta_y = end.y - start.y;

	const float	new_angle = atan2(delta_y, delta_x) - angle;
	const float	fixed_dist = distance2(delta_x, delta_y) * cos(new_angle);
	return (fixed_dist);
}

/* Steps ray until it hits a wall and calculates the distance from player to impact point. */
static t_ray	step_ray(t_game *game, t_ray ray)
{
	const int	MAX_DOF = 24;
	int			depth_of_field = 0;
	int			map_x;
	int			map_y;

	while (depth_of_field < MAX_DOF)
	{
		map_x = (int)(floorf(ray.hit.x / BLOCK_SIZE));
		map_y = (int)(floorf(ray.hit.y / BLOCK_SIZE));
		if (ray.orientation == WEST)
			map_x -= 1;
		if (ray.orientation == NORTH)
			map_y -= 1;
		// Validate colision
		if (map_y >= 0 && map_y < game->map.height &&
			map_x >= 0 && map_x < game->map.width &&
			game->map.grid[map_y][map_x] == '1')
		{
			ray.dist = fixed_distance(game->player.position, ray.hit, game->player.angle);
			return (ray);
		}
		ray.hit.x += ray.x_offset;
		ray.hit.y += ray.y_offset;
		depth_of_field++;
	}
	return (ray);
}

/* Calculates closest ray impact point on horizontal grid lines,
 * sets the step offset and steps the ray using these values. */
t_ray calculate_ray_distance_h(t_game *game, float ray_angle)
{
	t_ray	ray;

	ray.dist = FLT_MAX;
	ray.step_ratio = 1.0f / tanf(ray_angle);
	if (ray_angle > degrees_to_radians(180))
	{
		ray.hit.y = floorf(game->player.position.y / BLOCK_SIZE) * BLOCK_SIZE;
		ray.y_offset = -BLOCK_SIZE;
		ray.orientation = NORTH;
	}
	else if (ray_angle < degrees_to_radians(180))
	{
		ray.hit.y = (floorf(game->player.position.y / BLOCK_SIZE) * BLOCK_SIZE) + BLOCK_SIZE;
		ray.y_offset = BLOCK_SIZE;
		ray.orientation = SOUTH;
	}
	else
		return (ray);
	ray.x_offset = ray.y_offset * ray.step_ratio;
	ray.hit.x = (ray.hit.y - game->player.position.y) * ray.step_ratio + game->player.position.x;
	return (step_ray(game, ray));
}

/* Calculates closest ray impact point on vertical grid lines,
 * sets the step offset and steps the ray using these values. */
t_ray	calculate_ray_distance_v(t_game *game, float ray_angle)
{
	t_ray	ray;

	ray.dist = FLT_MAX;
	ray.step_ratio = tanf(ray_angle);
	if (ray_angle > degrees_to_radians(90) && ray_angle < degrees_to_radians(270))
	{
		ray.hit.x = floorf(game->player.position.x / BLOCK_SIZE) * BLOCK_SIZE;
		ray.x_offset = -BLOCK_SIZE;
		ray.orientation = WEST;
	}
	else if (ray_angle < degrees_to_radians(90) || ray_angle > degrees_to_radians(270))
	{
		ray.hit.x = (floorf(game->player.position.x / BLOCK_SIZE) * BLOCK_SIZE) + BLOCK_SIZE;
		ray.x_offset = BLOCK_SIZE;
		ray.orientation = EAST;
	}
	else
		return (ray);
	ray.y_offset = ray.x_offset * ray.step_ratio;
	ray.hit.y = (ray.hit.x - game->player.position.x) * ray.step_ratio + game->player.position.y;
	return (step_ray(game, ray));
}
