/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:26:10 by malallai          #+#    #+#             */
/*   Updated: 2019/05/10 14:41:06 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	recurs(t_opt *opt, t_folder *folder)
{
	t_file		*file;

	if (!has_flag(opt, F_RECURS))
		return ;
	file = reverse(opt) ? folder->file : folder->first;
	while (file)
	{
		if (file->exist && is_folder(file->path) && !is_parent(file->name))
			read_folder(opt, new_folder(file), file->prev || file->next, 1);
		file = reverse(opt) ? file->prev : file->next;
	}
}

char	*get_clean_path(t_file *file1, t_file *file2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(file1->path, "/");
	tmp2 = ft_strjoin(tmp, file2->name);
	free(tmp);
	return (tmp2);
}
