/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:16:22 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/01 00:17:03 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "defs.h"

/* Calculates the distance between two points. */
static float	distance(float x, float y){
	return sqrt(x * x + y * y);
}

/* Correction for distance calculation to avoid fish-eye effect. */
float	fixed_distance(t_point start, float angle, t_point end)
{
	const float	delta_x = end.x - start.x;
	const float	delta_y = end.y - start.y;

	const float	new_angle = atan2(delta_y, delta_x) - angle;
	const float	fixed_dist = distance(delta_x, delta_y) * cos(new_angle);
	return (fixed_dist);
}
