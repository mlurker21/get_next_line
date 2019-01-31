/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:07:23 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/31 19:45:25 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_foreach(int *tab, int length, void (*f) (int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}
