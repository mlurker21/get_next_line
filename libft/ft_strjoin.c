/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:40:19 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/30 19:52:22 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		str = ft_memalloc(ft_strlen(s2) + 1);
		str = ft_strcpy(str, s2);
		return (str);
	}
	if (!s2)
		return ((char *)s1);
	if ((str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
