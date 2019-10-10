/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:42:27 by malallai          #+#    #+#             */
/*   Updated: 2019/05/13 15:25:05 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_file		*new_file(t_opt *opt, int id, char *name, t_folder *parent)
{
	t_file		*file;

	file = malloc(sizeof(t_file *) * 8);
	file->id = id;
	file->next = NULL;
	file->prev = NULL;
	file->name = ft_strdup(name);
	if (parent->folder)
		file->path = get_clean_path(parent->folder, file);
	else
		file->path = ft_strdup(file->name);
	file->exist = exist(file);
	file->infos = get_infos(opt, file, parent);
	if (!file->exist || !file->infos)
	{
		opt->forcedetail = 1;
		if (!file->exist)
			no_file(opt, file);
		free_file(file);
		return ((file = NULL));
	}
	if (!parent->sizes)
		parent->sizes = file->infos->sizes;
	return (file);
}

t_infos		*get_infos(t_opt *opt, t_file *file, t_folder *parent)
{
	t_infos			*infos;
	struct stat		filestat;

	infos = malloc(sizeof(t_infos *) * (sizeof(struct stat) + 12));
	infos->path = ft_strdup(file->path);
	if ((lstat(infos->path, &filestat)) < 0)
	{
		free(infos->path);
		free(infos);
		return (NULL);
	}
	infos->name = ft_strdup(file->name);
	infos->file_stat = filestat;
	infos->perms = get_perms(infos->file_stat.st_mode);
	infos->uid = getpwuid(infos->file_stat.st_uid) \
		? getpwuid(infos->file_stat.st_uid) : NULL;
	infos->gid = getgrgid(infos->file_stat.st_gid) \
		? getgrgid(infos->file_stat.st_gid) : NULL;
	infos->millis = infos->file_stat.st_mtime;
	infos->date = get_date(infos->millis);
	infos->size = infos->file_stat.st_size;
	infos->maj = major(infos->file_stat.st_rdev);
	infos->min = minor(infos->file_stat.st_rdev);
	infos->sizes = get_sizes(opt, infos, infos->file_stat, parent->sizes);
	return (infos);
}

t_infosize	*get_sizes(t_opt *opt, t_infos *info, struct stat pstat, \
	t_infosize *parent)
{
	t_infosize	*isize;
	int			len;

	isize = parent ? parent : new_size();
	if (!can_print(opt, info->name))
		return (isize);
	len = ft_len((int)pstat.st_blocks);
	isize->blocks = len > isize->blocks ? len : isize->blocks;
	len = ft_len((int)pstat.st_nlink);
	isize->links = len > isize->links ? len : isize->links;
	len = !info->uid ? ft_len(info->file_stat.st_uid) \
		: (int)ft_strlen(info->uid->pw_name);
	isize->uid = len > isize->uid ? len : isize->uid;
	len = !info->gid ? ft_len(info->file_stat.st_gid) \
		: (int)ft_strlen(info->gid->gr_name);
	isize->gid = len > isize->gid ? len : isize->gid;
	len = ft_len(info->size);
	isize->size = len > isize->size ? len : isize->size;
	len = ft_len(info->maj);
	isize->maj = len > isize->maj ? len : isize->maj;
	len = ft_len(info->min);
	isize->min = len > isize->min ? len : isize->min;
	len = (int)ft_strlen(info->date);
	isize->date = len > isize->date ? len : isize->date;
	return (isize);
}

t_infosize	*new_size(void)
{
	t_infosize	*size;

	size = malloc(sizeof(t_infosize *) * 6);
	size->blocks = 1;
	size->links = 1;
	size->uid = 0;
	size->gid = 0;
	size->size = 1;
	size->date = 0;
	size->maj = 0;
	size->min = 0;
	return (size);
}

t_folder	*new_folder(t_file *file)
{
	t_folder	*folder;

	folder = malloc(sizeof(t_folder *) * 5);
	folder->folder = file;
	folder->file = NULL;
	folder->first = NULL;
	folder->size = 0;
	folder->count = 0;
	folder->sizes = NULL;
	return (folder);
}
