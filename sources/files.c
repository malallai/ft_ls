/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:52:52 by malallai          #+#    #+#             */
/*   Updated: 2019/04/23 14:50:11 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		to_folder(char *name, char *entry_name)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		r;

	r = 0;
	if (name[ft_strlen(name) - 1] == '/')
		return (0);
	tmp2 = ft_strjoin(entry_name ? entry_name : "", name);
	if (is_regular_file(tmp2))
	{
		free(tmp2);
		return (0);
	}
	free(tmp2);
	tmp = ft_strjoin(name, "/");
	tmp2 = ft_strjoin(entry_name ? entry_name : "", tmp);
	tmp3 = ft_strjoin(entry_name ? entry_name : "", name);
	if (!is_lnk(tmp3) && !is_regular_file(tmp2) && is_folder(tmp2))
		r = 1;
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (r);
}

t_file	*get_file(t_file *first, int id)
{
	if (!first || id < 0)
		return (NULL);
	if (first->id == id)
		return (first);
	return (get_file(first->next, id));
}
