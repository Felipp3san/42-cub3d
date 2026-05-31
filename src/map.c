/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 18:30:56 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/31 22:23:30 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "defs.h"

// TODO: Needs to load map from file.
t_map	get_map(void)
{
	t_map	map;

	// TODO: Find a way to detect number of rows.
	int rows = 10;
	map.grid = (char **) malloc(sizeof(char *) * (rows + 1));
	if (!map.grid)
		return (map);
	map.grid[0] = "111111111111111";
	map.grid[1] = "100100000000001";
	map.grid[2] = "10010000000P001";
	map.grid[3] = "100000000000001";
	map.grid[4] = "100000000000001";
	map.grid[5] = "100000111100001";
	map.grid[6] = "100000100000001";
	map.grid[7] = "100000100000001";
	map.grid[8] = "100000100000001";
	map.grid[9] = "111111111111111";
	map.grid[10] = NULL;

	// TODO: Improve logic to detect map size. Conside rows and columns with different sizes.
	map.width = ft_strlen(map.grid[0]);
	map.height = rows;
	return (map);
};

void	destroy_map(t_map *map)
{
	if (map->grid)
		free(map->grid);
	map->grid = NULL;
}
