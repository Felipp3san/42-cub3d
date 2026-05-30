/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:33:13 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:34:01 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

#include <stddef.h>
#include <stdint.h>

size_t	ft_printnbr(int nbr, int padding, int fd);
size_t	ft_printstr(char *str, int fd);
size_t	ft_printchar(char ch, int fd);
size_t	ft_printptr(uintptr_t ptr, int fd);
size_t	ft_printunbr_base(unsigned int nbr, const char *base, int fd);

#endif