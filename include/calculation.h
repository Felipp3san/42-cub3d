/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:16:29 by fde-alme          #+#    #+#             */
/*   Updated: 2026/05/30 13:48:03 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATION_H
# define CALCULATION_H

# include "defs.h"

float	distance(float x, float y);
float	fixed_distance(t_point start, float angle, t_point end);

#endif
