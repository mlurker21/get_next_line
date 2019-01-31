/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 03:07:54 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/31 17:23:21 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *nlist;

	list = f(lst);
	nlist = list;
	if (lst && f)
	{
		while (lst->next)
		{
			lst = lst->next;
			list->next = f(lst);
			if (list->next == NULL)
				return (NULL);
			list = list->next;
		}
		return (nlist);
	}
	return (NULL);
}
