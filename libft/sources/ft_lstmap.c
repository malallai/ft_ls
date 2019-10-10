/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:06:37 by malallai          #+#    #+#             */
/*   Updated: 2018/11/20 12:49:38 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new_elem;
	t_list	*new_lst;

	if (!lst || !(new_lst = f(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	lst = lst->next;
	tmp = new_lst;
	while (lst)
	{
		new_elem = f(ft_lstnew(lst->content, lst->content_size));
		tmp->next = new_elem;
		lst = lst->next;
		tmp = new_elem;
	}
	return (new_lst);
}
