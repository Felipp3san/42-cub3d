/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:09:49 by fde-alme          #+#    #+#             */
/*   Updated: 2026/01/20 14:10:44 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TO_H
# define FT_TO_H

long long	ft_atoll(const char *nptr);
int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
char		*ft_uitoa_base(unsigned int nbr, const char *base);
char		*ft_itoa(int n);
int			ft_toupper(int c);
int			ft_tolower(int c);

#endif