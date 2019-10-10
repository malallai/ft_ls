/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:06:12 by malallai          #+#    #+#             */
/*   Updated: 2019/04/23 14:01:59 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		sort(t_opt *opt, t_folder *folder, int low, int high)
{
	if (has_flag(opt, F_UNSORT))
		return ;
	if (has_flag(opt, F_TIME))
		sort_time(folder, low, high);
	else
		sort_ascii(folder, low, high);
}

void		sort_ascii(t_folder *folder, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while (i <= high && compare(0, get_file(folder->first, i), \
				get_file(folder->first, pivot), 1))
				i++;
			while (j >= low && compare(0, get_file(folder->first, j), \
				get_file(folder->first, pivot), 0))
				j--;
			if (i < j)
				swap(get_file(folder->first, i), get_file(folder->first, j));
		}
		swap(get_file(folder->first, j), get_file(folder->first, pivot));
		sort_ascii(folder, low, j - 1);
		sort_ascii(folder, j + 1, high);
	}
}

void		sort_time(t_folder *folder, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while (i <= high && compare(1, get_file(folder->first, i), \
				get_file(folder->first, pivot), 1))
				i++;
			while (j >= low && compare(1, get_file(folder->first, j), \
				get_file(folder->first, pivot), 0))
				j--;
			if (i < j)
				swap(get_file(folder->first, i), get_file(folder->first, j));
		}
		swap(get_file(folder->first, j), get_file(folder->first, pivot));
		sort_time(folder, low, j - 1);
		sort_time(folder, j + 1, high);
	}
}

int			compare(int t, t_file *f1, t_file *f2, int i)
{
	if (!f1 || !f2)
		return (1);
	if (t)
	{
		if (f1->infos->millis == f2->infos->millis)
			return (ft_strcmp(f1->name, f2->name) > 0);
		return (i ? f1->infos->millis >= f2->infos->millis \
			: f1->infos->millis < f2->infos->millis);
	}
	else
	{
		return (i ? ft_strcmp(f1->name, f2->name) <= 0 \
			: ft_strcmp(f1->name, f2->name) > 0);
	}
	return (0);
}
