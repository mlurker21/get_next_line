/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:40:19 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/30 16:20:40 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	join = (char *)malloc(sizeof(char) *
						  ((ft_strlen(s1) + 1) + (ft_strlen(s2) + 1)));
	if (join)
	{
		while (*s1)
		{
			join[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			join[i] = *s2++;
			i++;
		}
		join[i] = '\0';
	}
	return (join);
}
