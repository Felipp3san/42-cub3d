/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:56:32 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:08:45 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>

#include "defs.h"
#include "image.h"
#include "player.h"
#include "map.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (ERROR);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, NAME);
	if (game->win == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ERROR);
	}
	game->img = create_img(game);
	if (!game->img)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ERROR);
	}
	game->re_render = true;
	game->map = get_map();
	game->player = create_player(game);
	game->keys = (t_keys){false, false, false, false, false, false};
	return (OK);
};

void	destroy_game(t_game *game)
{
	if (game->img)
	{
		if (game->img->img)
			mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
		game->img = NULL;
	}
	if (game->map)
		destroy_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game = NULL;
}
