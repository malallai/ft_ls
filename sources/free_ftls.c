/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ftls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:29:06 by malallai          #+#    #+#             */
/*   Updated: 2019/05/10 16:08:35 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	free_infos(t_infos *infos)
{
	if (!infos)
		return ;
	free(infos->path);
	free(infos->name);
	free(infos->perms);
	free(infos->date);
	free(infos);
}

void	free_file(t_file *file)
{
	if (!file)
		return ;
	free_file(file->next);
	free(file->name);
	free(file->path);
	free_infos(file->infos);
	free(file);
}

void	free_folder(t_folder *folder)
{
	if (!folder)
		return ;
	free_file(folder->first);
	free(folder->sizes);
	free(folder);
}

void	free_nofile(t_nofile *nofile)
{
	if (!nofile)
		return ;
	free_nofile(nofile->next);
	free(nofile->name);
	free(nofile);
}

void	free_opt(t_opt *opt)
{
	free_folder(opt->main);
	free_nofile(opt->nofile);
	free(opt->flags);
	free(opt);
}
