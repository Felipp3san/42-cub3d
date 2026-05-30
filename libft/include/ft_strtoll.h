/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:26:52 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:52:32 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOLL_H
# define FT_STRTOLL_H

#include <stddef.h>

typedef struct s_strtoll
{
	long long	nbr;
	int			sign;
	size_t		i;
}	t_strtoll;

long long	ft_strtoll(const char *nptr, char **endptr, int base);

#endif