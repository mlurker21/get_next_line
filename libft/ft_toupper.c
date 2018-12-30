/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:05:47 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/30 18:20:14 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	return (c);
}
