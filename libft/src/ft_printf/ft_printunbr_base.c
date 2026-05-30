/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:35:02 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:38:58 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_to.h"
#include "ft_str.h"
#include "ft_put.h"

size_t	ft_printunbr_base(unsigned int nbr, const char *base, int fd)
{
	char	*str;
	size_t	size;

	str = ft_uitoa_base(nbr, base);
	size = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (size);
}
