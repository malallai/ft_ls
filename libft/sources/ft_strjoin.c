/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:06:33 by malallai          #+#    #+#             */
/*   Updated: 2019/05/13 16:01:25 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size;
	char	n;

	n = '\0';
	if (!s1)
		s1 = &n;
	if (!s2)
		s2 = &n;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_strnew(size)))
		return (NULL);
	if (!ft_strcpy(new, s1))
	{
		free(new);
		return (NULL);
	}
	if (!ft_strcpy(new + ft_strlen(s1), s2))
	{
		free(new);
		return (NULL);
	}
	return (new);
}
