/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:54:33 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/09 16:58:18 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
		while (*s != c && *s != '\0')
		{
			len++;
			s++;
		}
	return (len);
}
