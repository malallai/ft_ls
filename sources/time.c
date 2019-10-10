/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:10:33 by malallai          #+#    #+#             */
/*   Updated: 2019/05/13 16:11:25 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		free_split(char **split)
{
	int	index;

	index = 0;
	while (split[index])
		free(split[index++]);
	free(split);
}

static char		*join_split(char **split)
{
	char	*tmp;
	char	*new;
	int		index;

	index = 0;
	new = ft_strdup(split[index]);
	while (split[++index])
	{
		tmp = ft_strjoin(new, split[index]);
		free(new);
		new = tmp;
	}
	return (new);
}

static char		**get_finaldate(time_t date, char **split)
{
	long int	current_time;
	char		**final_time;

	current_time = time(0);
	final_time = (char **)malloc(sizeof(char *) * 5);
	final_time[0] = ft_strdup(split[1]);
	final_time[1] = ft_strdup((int)ft_strlen(split[2]) == 1 ? "  " : " ");
	final_time[2] = ft_strdup(split[2]);
	if ((date > current_time) || (date < (current_time - 15724800)))
	{
		final_time[3] = ft_strdup("  ");
		final_time[4] = ft_strdup(split[4]);
	}
	else
	{
		final_time[3] = ft_strdup(" ");
		final_time[4] = ft_strsub(split[3], 0, 5);
	}
	final_time[5] = 0;
	return (final_time);
}

char			*get_date(time_t date)
{
	char		*file_time;
	char		**final_split;
	char		**split;
	char		*tmp;

	file_time = ft_strdup(ctime(&date));
	split = ft_strsplit(file_time, ' ');
	tmp = split[4];
	split[4] = ft_trimchar(tmp, '\n');
	final_split = get_finaldate(date, split);
	free_split(split);
	free(file_time);
	free(tmp);
	tmp = join_split(final_split);
	free_split(final_split);
	return (tmp);
}
