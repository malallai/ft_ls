/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 09:47:04 by malallai          #+#    #+#             */
/*   Updated: 2018/11/20 12:49:38 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char		ch;
	unsigned char		*t_d;
	unsigned const char	*t_s;

	if (d && s)
	{
		ch = (unsigned char)c;
		t_d = (unsigned char*)d;
		t_s = (unsigned char*)s;
		while (n-- > 0)
		{
			*t_d = *t_s;
			if (*t_d++ == ch)
				return (t_d);
			t_s++;
		}
	}
	return (NULL);
}
