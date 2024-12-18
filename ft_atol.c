/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:02:23 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/23 18:25:27 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

long	ft_atol(const char *s)
{
	int		isnegative;
	long	res;

	res = 0;
	isnegative = 1;
	while (*s == ' ' || *s == '\f' || *s == '\r' || *s == '\v' || *s == '\t'
		|| *s == '\n')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			isnegative = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	return (res * isnegative);
}
