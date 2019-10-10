/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:02:22 by malallai          #+#    #+#             */
/*   Updated: 2019/03/21 16:04:01 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*result;
	int		temp;
	size_t	i;
	int		r;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_len(n);
	temp = ft_abs(n);
	if (!(result = ft_strnew(i)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	while (temp != 0)
	{
		r = temp % 10;
		result[--i] = r + 48;
		temp /= 10;
	}
	return (result);
}
