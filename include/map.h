/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:40:59 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:10:30 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "defs.h"

char	**get_map(void);
void	destroy_map(char **map);
void	draw_map(t_game *game);
void	draw_minimap(t_game *game);

#endif
