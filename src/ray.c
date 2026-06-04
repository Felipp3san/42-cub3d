/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:28:47 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/04 22:57:12 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdio.h>

#include "defs.h"
#include "utils.h"

static float	distance(t_point a, t_point b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
};

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
			ray.dist = distance(game->player.position, ray.hit);
			return (ray);
		}
		ray.hit.x += ray.x_offset;
		ray.hit.y += ray.y_offset;
		depth_of_field++;
	}
	return (ray);
}

t_ray calculate_ray_distance_h(t_game *game, float ray_angle)
{
	t_ray	ray;

	ray.dist = FLT_MAX;
	ray.step_ratio = 1.0f / tanf(ray_angle);
	if (ray_angle > degrees_to_radians(180))
	{
		ray.hit.y = (((int) game->player.position.y >> 6) << 6);
		ray.y_offset = -BLOCK_SIZE;
		ray.orientation = NORTH;
	}
	else if (ray_angle < degrees_to_radians(180))
	{
		ray.hit.y = (((int) game->player.position.y >> 6) << 6) + BLOCK_SIZE;
		ray.y_offset = BLOCK_SIZE;
		ray.orientation = SOUTH;
	}
	else
		return (ray);
	ray.x_offset = ray.y_offset * ray.step_ratio;
	ray.hit.x = (ray.hit.y - game->player.position.y) * ray.step_ratio + game->player.position.x;
	return (step_ray(game, ray));
}

t_ray	calculate_ray_distance_v(t_game *game, float ray_angle)
{
	t_ray	ray;

	ray.dist = FLT_MAX;
	ray.step_ratio = tanf(ray_angle);
	if (ray_angle > degrees_to_radians(90) && ray_angle < degrees_to_radians(270))
	{
		ray.hit.x = (((int)game->player.position.x >> 6) << 6);
		ray.x_offset = -BLOCK_SIZE;
		ray.orientation = WEST;
	}
	else if (ray_angle < degrees_to_radians(90) || ray_angle > degrees_to_radians(270))
	{
		ray.hit.x = (((int)game->player.position.x >> 6) << 6) + BLOCK_SIZE;
		ray.x_offset = BLOCK_SIZE;
		ray.orientation = EAST;
	}
	else
		return (ray);
	ray.y_offset = ray.x_offset * ray.step_ratio;
	ray.hit.y = (ray.hit.x - game->player.position.x) * ray.step_ratio + game->player.position.y;
	return (step_ray(game, ray));
}
