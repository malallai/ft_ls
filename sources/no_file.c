/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:55:51 by malallai          #+#    #+#             */
/*   Updated: 2019/05/12 15:29:42 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		no_file(t_opt *opt, t_file *file)
{
	t_nofile	*nofile;

	if (!opt->nofile)
	{
		opt->nofile = malloc(sizeof(t_nofile) * 2);
		opt->nofile->name = ft_strdup(file->path);
		opt->nofile->next = NULL;
		opt->lastnofile = opt->nofile;
	}
	else
	{
		nofile = malloc(sizeof(t_nofile) * 2);
		nofile->name = ft_strdup(file->path);
		nofile->next = NULL;
		opt->lastnofile->next = nofile;
		opt->lastnofile = nofile;
	}
}

void		print_nofile(t_opt *opt)
{
	t_nofile	*nofile;

	if (!opt->nofile)
		return ;
	sort_nofile(opt);
	nofile = opt->nofile;
	while (nofile)
	{
		print_nexist(opt, nofile->name);
		nofile = nofile->next;
	}
	free_nofile(opt->nofile);
	opt->nofile = NULL;
	opt->lastnofile = NULL;
}

void		sort_nofile(t_opt *opt)
{
	t_nofile	*nofile;
	t_nofile	*tmp;
	char		*next;

	if (has_flag(opt, F_UNSORT))
		return ;
	nofile = opt->nofile;
	while (nofile)
	{
		tmp = opt->nofile;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			{
				next = tmp->name;
				tmp->name = tmp->next->name;
				tmp->next->name = next;
			}
			tmp = tmp->next;
		}
		nofile = nofile->next;
	}
}
