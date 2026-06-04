/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:21:44 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/04 22:29:02 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "defs.h"

bool	touch(t_game *game, float px, int py);
double	degrees_to_radians(double degrees);
float	radians_to_degrees(float radians);
float	normalize_angle(float angle);

#endif
