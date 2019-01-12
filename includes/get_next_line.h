/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:01:29 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/12 23:37:46 by pcollio-         ###   ########.fr       */
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
		char			*buff;
		int				fd;
		struct s_gnl	*next;
}						t_gnl;

#endif
