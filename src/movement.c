/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:26:08 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/31 15:37:11 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "defs.h"
#include "utils.h"

/* Updates the player's position based on movement input. */
void	move_player(t_game *game)
{
	const float		cos_angle = cos(game->player.angle);
	const float 	sin_angle = sin(game->player.angle);
	float			dx;
	float			dy;
	float			x;
	float			y;

	dx = 0;
	dy = 0;
	if (game->keys.w)
	{
		dx += cos_angle;
		dy += sin_angle;
	}
	if (game->keys.s)
	{
		dx -= cos_angle;
		dy -= sin_angle;
	}
	if (game->keys.a)
	{
		dx += sin_angle;
		dy -= cos_angle;
	}
	if (game->keys.d)
	{
		dx -= sin_angle;
		dy += cos_angle;
	}
	x = game->player.position.x + dx * SPEED;
	y = game->player.position.y + dy * SPEED;
	// TODO: Adjust to detect player size.
	if (!touch(game, x, y))
	{
		game->player.position.x = x;
		game->player.position.y = y;
	}
}

/* Updates the player's looking direction based on movement input. */
void	rotate_player(t_game *game)
{
	t_player	*player = &game->player;

	if (game->keys.left)
		player->angle -= ANGLE_SPEED;
	if (game->keys.right)
		player->angle += ANGLE_SPEED;
	if (player->angle > degrees_to_radians(360))
		player->angle = 0;
	if (player->angle < 0)
		player->angle = degrees_to_radians(360);
}
