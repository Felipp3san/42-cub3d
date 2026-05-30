/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:28:15 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:38:28 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"
#include "ft_str.h"

size_t	ft_printstr(char *str, int fd)
{
	size_t	size;

	if (!str)
		str = "(null)";
	ft_putstr_fd(str, fd);
	size = ft_strlen(str);
	return (size);
}
