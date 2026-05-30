/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:28:56 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:08:22 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "defs.h"

/* Custom mlx_pixel_put, faster */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 ||  y < 0)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_img	*create_img(t_game *game)
{
	t_img	*img;

	img = (t_img *) malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

/* Sets all pixels in image to black */
void	clear_img(t_game *game)
{
	int	column;
	int	row;

	row = 0;
	while (row < HEIGHT)
	{
		column = 0;
		while (column < WIDTH)
		{
			my_mlx_pixel_put(game->img, column, row, BLACK);
			column++;
		}
		row++;
	}
}
