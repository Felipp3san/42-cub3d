/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:28:47 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:16:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

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
