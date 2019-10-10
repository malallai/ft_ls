/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:28:25 by malallai          #+#    #+#             */
/*   Updated: 2019/05/13 16:07:43 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		print_file(t_opt *opt, t_file *file)
{
	if (!can_print(opt, file->name))
		return (0);
	opt->print = 1;
	if (!file->infos)
		return (0);
	if (has_flag(opt, F_DETAIL))
		return (print_details(opt, file));
	else
	{
		if (has_flag(opt, F_BLOCKS))
		{
			ft_putnbr(file->infos->file_stat.st_blocks);
			ft_putchar(' ');
		}
		ft_putstr(get_color(opt, file->infos->file_stat.st_mode));
		ft_putstr(file->name);
		ft_putstr(get_color(opt, 0));
	}
	return (1);
}

void	print_folder(t_opt *opt, t_folder *folder, int name)
{
	t_file	*file;
	int		ret;

	file = reverse(opt) ? folder->file : folder->first;
	ft_putstr(opt->print ? "\n" : "");
	opt->print = 1;
	if (name || opt->forcedetail)
	{
		ft_putstr(folder->folder->path);
		ft_putendl(":");
	}
	if (!file)
		return ;
	if (can_print_total_folder(opt, folder))
	{
		ft_putstr("total ");
		ft_putnbrln(folder->size);
	}
	while (file)
	{
		ret = print_file(opt, file);
		file = reverse(opt) ? file->prev : file->next;
		if (ret)
			ft_putchar('\n');
	}
}

int		print_details(t_opt *opt, t_file *file)
{
	t_infos		*infos;

	infos = file->infos;
	if (has_flag(opt, F_BLOCKS))
	{
		put_nbr(infos->file_stat.st_blocks, 1, 0, infos->sizes->blocks);
		put_str(infos->perms, 1, 1, 10);
	}
	else
		put_str(infos->perms, 0, 0, 0);
	put_nbr(infos->file_stat.st_nlink, 1, 2, infos->sizes->links);
	put_guid(infos, infos->sizes);
	print_size(infos, infos->sizes);
	ft_putchar(' ');
	put_str(infos->date, 0, 0, infos->sizes->date);
	ft_putchar(' ');
	ft_putstr(get_color(opt, infos->file_stat.st_mode));
	put_str(file->name, 0, 0, 0);
	ft_putstr(get_color(opt, 0));
	put_lnk(file);
	return (1);
}

void	print_size(t_infos *infos, t_infosize *sizes)
{
	if (S_ISBLK(infos->file_stat.st_mode) || S_ISCHR(infos->file_stat.st_mode))
	{
		put_nbr(infos->maj, 1, 4, sizes->maj);
		ft_putstr(",");
		put_nbr(infos->min, 1, 2, sizes->min);
	}
	else
	{
		put_nbr(infos->size, 1, 2, sizes->size);
	}
}

void	print_lnk(t_opt *opt, t_file *file)
{
	char	*tmp;
	char	*tmp2;

	tmp = file->path;
	if (has_flag(opt, F_DETAIL))
		return ;
	tmp2 = ft_strjoin(tmp, "/");
	if (is_folder(tmp2))
	{
		file->path = tmp2;
		free(tmp);
	}
	else
		free(tmp2);
}
