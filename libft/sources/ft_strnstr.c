/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:12:14 by malallai          #+#    #+#             */
/*   Updated: 2018/11/20 12:49:39 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		mlen;

	if (!haystack || !needle)
		return (NULL);
	j = 0;
	mlen = len;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack == needle)
		return ((char*)haystack);
	while (haystack[j] && len-- > 0)
	{
		if (haystack[j] == needle[0])
		{
			i = 1;
			while (needle[i] && j + i < mlen && haystack[i + j] == needle[i])
				i++;
			if (!needle[i])
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
