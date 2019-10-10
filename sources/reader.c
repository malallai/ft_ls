/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:28:26 by malallai          #+#    #+#             */
/*   Updated: 2019/05/12 17:47:26 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	read_folder(t_opt *opt, t_folder *folder, int name, int r)
{
	int				index;
	DIR				*dir;
	struct dirent	*sd;
	t_file			*tmp;

	index = 0;
	if (!(dir = opendir(folder->folder->path)))
		error_dir(opt, folder, name);
	else
	{
		while ((sd = readdir(dir)))
		{
			if ((tmp = new_file(opt, index, sd->d_name, folder)))
				update_read_folder(opt, folder, tmp, index++);
		}
		closedir(dir);
		folder->count = index;
		sort(opt, folder, 0, folder->count);
		if (!(r && !can_print(opt, folder->folder->name)))
		{
			print_folder(opt, folder, name);
			recurs(opt, folder);
		}
	}
	free_folder(folder);
}

void	update_read_folder(t_opt *opt, t_folder *folder, t_file *tmp, int index)
{
	if (index)
	{
		tmp->prev = folder->file;
		folder->file->next = tmp;
	}
	else
		folder->first = tmp;
	folder->file = tmp;
	if (folder->file->infos)
		folder->size += can_print(opt, folder->file->name) \
			? folder->file->infos->file_stat.st_blocks : 0;
}

void	ls_folder(t_opt *opt, t_file *file)
{
	while (file)
	{
		if (file->exist && is_folder(file->path))
			read_folder(opt, new_folder(file), file->prev || file->next, 0);
		file = reverse(opt) ? file->prev : file->next;
	}
}

void	ls(t_opt *opt, t_file *file)
{
	int		ret;
	int		f;
	int		fi;

	fi = 0;
	while (file)
	{
		ret = 0;
		f = f ? f : is_folder(file->path);
		if (file->exist && is_lnk(file->path))
			print_lnk(opt, file);
		if (file->exist && !is_folder(file->path))
			ret = print_file(opt, file);
		fi = ret && !fi ? 1 : fi;
		file = reverse(opt) ? file->prev : file->next;
		if (ret == 1)
			ft_putchar('\n');
	}
	if (f)
		ls_folder(opt, reverse(opt) \
			? opt->main->file : opt->main->first);
}
