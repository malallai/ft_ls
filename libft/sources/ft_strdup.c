/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:35:22 by malallai          #+#    #+#             */
/*   Updated: 2019/01/23 14:10:38 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	char	*dest;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(*src) * (size + 1))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
