/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 20:06:43 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 12:19:18 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <libft.h>
# include <unistd.h>

# include "defs.h"

// 2D
void	draw_square(t_game *game, t_point position, float size, int color, bool filled);
void	draw_player(t_game *game, int color);
void	draw_map(t_game *game, float block_size);
void	draw_2D_FOV(t_game *game, int color);

// 3D
void	draw_3D_FOV(t_game *game);

#endif
