/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:01:20 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:44:03 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			str_len;
	size_t			i;

	i = 0;
	ch = c;
	str_len = ft_strlen(s);
	while (i <= str_len)
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
