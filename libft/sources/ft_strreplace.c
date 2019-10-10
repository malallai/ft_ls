/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:40:03 by malallai          #+#    #+#             */
/*   Updated: 2019/01/15 17:35:00 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(const char *str, char to_replace, char replace)
{
	char	*new_str;
	int		str_index;
	int		newstr_index;
	char	c;

	str_index = 0;
	newstr_index = 0;
	new_str = ft_strnew(ft_strlen(str));
	while (str[str_index])
	{
		if (!replace && str[str_index] == to_replace)
			str_index++;
		else
		{
			c = str[str_index] == to_replace ? replace : str[str_index];
			new_str[newstr_index] = c;
			newstr_index++;
			str_index++;
		}
	}
	return (new_str);
}
