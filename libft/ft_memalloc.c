/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:11:24 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/30 16:20:40 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	if (size == 0)
		return (NULL);
	a = (void *)malloc(size * sizeof(*a));
	if (a)
	{
		ft_bzero(a, size);
		return (a);
	}
	return (NULL);
}
