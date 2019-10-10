/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:46:48 by malallai          #+#    #+#             */
/*   Updated: 2018/11/20 12:49:38 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int r;
	int inf;

	if (!str)
		return (0);
	r = 0;
	inf = 1;
	while (*str && (*str == '\n' || *str == '\f'
		|| *str == '\t' || *str == '\v' || *str == '\r'
		|| *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			inf = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	return (r * inf);
}
