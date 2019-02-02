/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:33:07 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/02 21:44:57 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H

# define GNL_GET_NEXT_LINE_H
# include "../includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 13

int						get_next_line(const int fd, char **line);

#endif