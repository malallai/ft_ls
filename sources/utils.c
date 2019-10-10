/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:11:26 by malallai          #+#    #+#             */
/*   Updated: 2019/04/23 14:30:28 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	get_type(int mode)
{
	if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISREG(mode))
		return ('-');
	else if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}

char	*get_color(t_opt *opt, int mode)
{
	if (!has_flag(opt, F_COLOR))
		return ("");
	if (S_ISLNK(mode))
		return (PURPLE);
	else if (S_ISDIR(mode))
		return (CYAN);
	else if (mode & S_IXUSR)
		return (RED);
	else if (S_ISCHR(mode))
		return (CHR);
	else if (S_ISBLK(mode))
		return (BLK);
	else if (S_ISFIFO(mode))
		return (FIFO);
	return (WHITE);
}

char	*get_perms(int mode)
{
	char *perm;

	perm = (char *)malloc(sizeof(char *) * 11);
	perm[0] = get_type(mode);
	perm[1] = (mode & S_IRUSR) && (mode & S_IREAD) ? 'r' : '-';
	perm[2] = (mode & S_IWUSR) && (mode & S_IWRITE) ? 'w' : '-';
	if (mode & S_ISUID)
		perm[3] = (mode & S_IXUSR) && (mode & S_IEXEC) ? 's' : 'S';
	else
		perm[3] = (mode & S_IXUSR) && (mode & S_IEXEC) ? 'x' : '-';
	perm[4] = (mode & S_IRGRP) && (mode & S_IREAD) ? 'r' : '-';
	perm[5] = (mode & S_IWGRP) && (mode & S_IWRITE) ? 'w' : '-';
	if (mode & S_ISGID)
		perm[6] = (mode & S_IXGRP) && (mode & S_IEXEC) ? 's' : 'S';
	else
		perm[6] = (mode & S_IXGRP) && (mode & S_IEXEC) ? 'x' : '-';
	perm[7] = (mode & S_IROTH) && (mode & S_IREAD) ? 'r' : '-';
	perm[8] = (mode & S_IWOTH) && (mode & S_IWRITE) ? 'w' : '-';
	if (mode & S_ISVTX)
		perm[9] = (mode & S_IXOTH) && (mode & S_IEXEC) ? 't' : 'T';
	else
		perm[9] = (mode & S_IXOTH) && (mode & S_IEXEC) ? 'x' : '-';
	perm[10] = 0;
	return (perm);
}

int		has_flag(t_opt *opt, int flag)
{
	return ((opt->flag & flag) > 0);
}

int		reverse(t_opt *opt)
{
	return (has_flag(opt, F_REVERSE) && !has_flag(opt, F_UNSORT));
}
