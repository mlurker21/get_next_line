/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:16:54 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/02 16:58:16 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long int	i;
	unsigned char		*ptr;

	ptr = (unsigned char*)s;
	i = 0;
	while (i < n)
		ptr[i++] = '\0';
}
