/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:22:40 by malallai          #+#    #+#             */
/*   Updated: 2019/05/10 16:09:26 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		bad_option(t_opt *opt, char option)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(option);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-");
	ft_putstr(opt->flags);
	ft_putendl("] [file ...]");
	opt->error = 1;
	return (exit_ftls(opt));
}

void	print_nexist(t_opt *opt, char *name)
{
	ft_putstr("ft_ls: ");
	ft_putstr(name);
	ft_putendl(": No such file or directory");
	opt->error = 1;
}

void	error_dir(t_opt *opt, t_folder *folder, int name)
{
	if (errno != ENOTDIR)
	{
		print_folder(opt, folder, name);
		print_error(opt, folder->folder);
	}
}

void	print_error(t_opt *opt, t_file *file)
{
	ft_putstr("ft_ls: ");
	perror(file->name);
	opt->error = 1;
}

int		exit_ftls(t_opt *opt)
{
	int		r;

	r = opt->error ? 1 : 0;
	free_opt(opt);
	exit(r);
	return (r);
}
