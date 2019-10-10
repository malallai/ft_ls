/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:21:45 by malallai          #+#    #+#             */
/*   Updated: 2019/04/23 14:01:59 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	swap(t_file *a, t_file *b)
{
	t_file	tmp;

	if (!a || !b)
		return ;
	tmp = *a;
	swap_item(&a, b);
	swap_item(&b, &tmp);
}

void	swap_item(t_file **a, t_file *cpy)
{
	(*a)->name = cpy->name;
	(*a)->path = cpy->path;
	(*a)->infos = cpy->infos;
}
