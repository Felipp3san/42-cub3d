/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:58:58 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:10:22 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <X11/keysym.h>
# include <mlx.h>
# include <libft.h>

# include "defs.h"
# include "movement.h"

int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_w)
		game->keys.w = false;
	if (keycode == XK_s)
		game->keys.s = false;
	if (keycode == XK_a)
		game->keys.a = false;
	if (keycode == XK_d)
		game->keys.d = false;
	if (keycode == XK_Left)
		game->keys.left = false;
	if (keycode == XK_Right)
		game->keys.right = false;
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_w)
		game->keys.w = true;
	if (keycode == XK_s)
		game->keys.s = true;
	if (keycode == XK_a)
		game->keys.a = true;
	if (keycode == XK_d)
		game->keys.d = true;
	if (keycode == XK_Left)
		game->keys.left = true;
	if (keycode == XK_Right)
		game->keys.right = true;
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	return (0);
}

#endif
