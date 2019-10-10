/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:33:06 by malallai          #+#    #+#             */
/*   Updated: 2019/05/10 14:32:31 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		is_hidden_file(char *str)
{
	return ((str[0] == '.' && str[1] != '/') \
		|| (str[0] == '.' && str[1] == '.'));
}

int		is_parent(char *str)
{
	return (ft_strequ(str, ".") || ft_strequ(str, ".."));
}

int		can_print(t_opt *opt, char *str)
{
	return (has_flag(opt, F_ALL) \
		|| (has_flag(opt, F_ALLEXCEPTPT) && !is_parent(str)) \
		|| (!has_flag(opt, F_ALL) && !is_hidden_file(str)));
}

int		can_print_total_folder(t_opt *opt, t_folder *folder)
{
	t_file *file;

	if (!has_flag(opt, F_DETAIL))
		return (0);
	file = folder->first;
	while (file)
	{
		if (can_print(opt, file->name))
			return (1);
		if (has_flag(opt, F_ALLEXCEPTPT) && !is_parent(file->name))
			return (1);
		file = file->next;
	}
	return (0);
}
