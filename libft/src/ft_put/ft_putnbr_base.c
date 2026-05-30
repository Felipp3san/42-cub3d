/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:10:17 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:42:30 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_put.h"

static size_t	get_base(char	*str)
{
	return (ft_strlen(str));
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	nbr;
	size_t			base_size;

	base_size = get_base(base);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -nb;
	}
	nbr = nb;
	if (nbr >= base_size)
		ft_putnbr_base((nbr / base_size), base);
	ft_putchar_fd(base[nbr % base_size], 1);
}
