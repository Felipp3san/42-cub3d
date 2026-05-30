/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:20:38 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:37:35 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_put.h"
#include "ft_str.h"
#include "ft_to.h"

static int	apply_padding(int fd)
{
	ft_putchar_fd(' ', fd);
	return (1);
}

size_t	ft_printnbr(int nbr, int padding, int fd)
{
	char	*str;
	size_t	size;

	str = ft_itoa(nbr);
	size = ft_strlen(str);
	if (padding > 0)
	{
		while (size < (unsigned long) padding)
			size += apply_padding(fd);
	}
	ft_putstr_fd(str, fd);
	if (padding < 0)
	{
		padding = -padding;
		while (size < (unsigned long) padding)
			size += apply_padding(fd);
	}
	free(str);
	return (size);
}
