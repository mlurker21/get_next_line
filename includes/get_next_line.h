/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:33:07 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/31 19:35:55 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H

# define GNL_GET_NEXT_LINE_H
# include "../includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 5

typedef struct			s_gnl
{
	char			*buffn;
//	char			*buff;
	int				fd;
	struct s_gnl	*next;
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif