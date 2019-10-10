/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:56:02 by malallai          #+#    #+#             */
/*   Updated: 2019/05/12 15:19:25 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	put_lnk(t_file *file)
{
	char	*tmp;

	if (!S_ISLNK(file->infos->file_stat.st_mode))
		return ;
	tmp = lsgetlink(file->path);
	ft_putstr(" -> ");
	ft_putstr(tmp);
	free(tmp);
}

void	put_nbr(int nbr, int position, int spaces, int max)
{
	char	*str;

	str = ft_itoa(nbr);
	put_str(str, position, spaces, max);
	free(str);
}

void	put_str(char *str, int position, int spaces, int max)
{
	if (position == 1)
		tab(spaces, max, (int)ft_strlen(str));
	ft_putstr(str);
	if (position == 2)
		tab(spaces, max, (int)ft_strlen(str));
}

void	put_guid(t_infos *infos, t_infosize *sizes)
{
	ft_putchar(' ');
	if (getpwuid(infos->file_stat.st_uid))
		put_str(getpwuid(infos->file_stat.st_uid)->pw_name, 2, 2, sizes->uid);
	else
		put_nbr(infos->file_stat.st_uid, 2, 2, sizes->uid);
	if (getgrgid(infos->file_stat.st_gid))
		put_str(getgrgid(infos->file_stat.st_gid)->gr_name, 2, 0, sizes->gid);
	else
		put_nbr(infos->file_stat.st_gid, 2, 0, sizes->gid);
}

void	tab(int spaces, int max, int size)
{
	int index;

	index = 0;
	while (index++ < spaces + (max - size))
		ft_putchar(' ');
}
