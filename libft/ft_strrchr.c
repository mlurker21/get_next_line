/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:22:52 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/29 13:41:15 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;
	int		len;

	d = (char *)s;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (len--)
		if (d[len] == c)
			return (&d[len]);
	return (NULL);
}
