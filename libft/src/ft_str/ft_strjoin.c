/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:57:01 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:44:54 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_str.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	dst = (char *) malloc(len + 1);
	if (dst)
	{
		*dst = '\0';
		ft_strlcat(dst, s1, len + 1);
		ft_strlcat(dst, s2, len + 1);
	}
	return (dst);
}
