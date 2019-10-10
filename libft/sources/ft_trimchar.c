/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:35:06 by malallai          #+#    #+#             */
/*   Updated: 2018/11/20 12:49:39 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trimchar(char *str, char c)
{
	char	*new;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] && str[i] == c)
		i++;
	if (i == j + 1)
		i = 0;
	while (str[j] == c)
		j--;
	new = ft_strsub(str, i, j - i + 1);
	return (new);
}
