/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:13:38 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:55:55 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>
# include <mlx.h>

# include "defs.h"
# include "game.h"
# include "events.h"
# include "render.h"
# include "image.h"

int	loop(void *param)
{
	t_game	*game;

	game = (t_game *) param;

	// Player movement
	rotate_player(game);
	move_player(game);

	// Draw player/map
	clear_img(game);

	// 2D vision
	//draw_square(game, game->player.position.x, game->player.position.y, PLAYER_SIZE, RED);
	//draw_map(game, BLOCK_SIZE, BLUE);
	//draw_2D_FOV(game, RED);

	// 3D vision
	draw_3D_FOV(game);
	//draw_minimap(game);

	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);

	usleep(100);
	return (0);
}

int main(void)
{
	t_game	game;

	// Initialization
	if (init_game(&game) == ERROR)
		return (ERROR);

	// Hooks
	mlx_hook(game.win, KeyPress, KeyPressMask, (int (*)())key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, (int (*)())key_release, &game);
	mlx_loop_hook(game.mlx, (int (*)())loop, &game);

	// Loop
	mlx_loop(game.mlx);

	// Cleanup
	destroy_game(&game);

	return (0);
}
