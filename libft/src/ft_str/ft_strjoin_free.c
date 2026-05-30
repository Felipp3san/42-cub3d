/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:48:39 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:44:42 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	size_t	total_len;
	ssize_t	i;
	ssize_t	j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = ft_calloc(total_len, sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_str[i++] = s2[j];
	new_str[i] = 0;
	return (free(s1), free(s2), new_str);
}