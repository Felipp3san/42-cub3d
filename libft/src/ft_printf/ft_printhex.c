/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:45:54 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:37:04 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_put.h"
#include "ft_str.h"
#include "ft_to.h"

size_t	ft_printunsigned_base(unsigned int nbr, char *base)
{
	char	*str;
	size_t	size;

	str = ft_uitoa_base(nbr, base);
	size = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (size);
}
