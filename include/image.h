/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:42:54 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 20:23:04 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <mlx.h>

# include "defs.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	clear_img(t_game *game);
t_img	*create_img(t_game *game);

#endif
