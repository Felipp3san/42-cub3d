/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 18:32:22 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:09:09 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "defs.h"
#include "utils.h"

/* Gets player starting position from map. */
static t_point	get_player_position(t_game *game)
{
	int	column;
	int	row;

	row = 0;
	while (game->map && game->map[row] != NULL)
	{
		column = 0;
		while (game->map[row][column] != '\0')
		{
			// TODO: Adjust player position to capture angle (N, E, W, S)
			if (game->map[row][column] == 'P')
				return ((t_point){column, row});
			column++;
		}
		row++;
	}
	return ((t_point){-1, -1});
}

/* Creates the player structure and initializes it. */
t_player	create_player(t_game *game)
{
	t_player	player;
	t_point		start_position;

	start_position = get_player_position(game);
	// TODO: Fix invalid starting position
	// Suggestion: Pick the next valid position
	if (start_position.x == -1 || start_position.y == -1)
	{
		player.position.x = (float) WIDTH / 2;
		player.position.y = (float) HEIGHT / 2;
	}
	player.position.x = start_position.x * BLOCK_SIZE;
	player.position.y = start_position.y * BLOCK_SIZE;
	player.angle = radians(180);
	return (player);
}
