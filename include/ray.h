/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:11:52 by fde-alme          #+#    #+#             */
/*   Updated: 2026/06/01 17:59:32 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "defs.h"

t_point	trace_ray(t_game *game, float angle);
t_ray	calculate_ray_distance_h(t_game *game, float ray_angle);
t_ray	calculate_ray_distance_v(t_game *game, float ray_angle);

#endif
