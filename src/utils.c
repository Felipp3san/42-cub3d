/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:21:35 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/04 22:29:10 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "defs.h"

/* Check if a position hits a wall tile. */
bool	touch(t_game *game, float px, int py)
{
	// convert world coordinates (pixels) to map grid indices.
	const int	row = py / BLOCK_SIZE;
	const int	column = px / BLOCK_SIZE;

	if (game->map.grid[row][column] == '1')
		return true;
	return false;
}

double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI) / 180.0;
}

float	radians_to_degrees(float radians)
{
	return (radians * 180.0) / M_PI;
}

float	normalize_angle(float angle)
{
	float	two_pi;

	two_pi = degrees_to_radians(360);
	if (angle < 0)
	{
		while (angle < 0)
			angle += two_pi;
	}
	else
	{
		while (angle > two_pi)
			angle -= two_pi;
	}
	return (angle);
}
