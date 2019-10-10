/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:31:51 by malallai          #+#    #+#             */
/*   Updated: 2019/01/11 13:21:11 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_char(char *str, char ch)
{
	int		index;
	size_t	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == ch)
			count++;
		index++;
	}
	return (count);
}
