/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 00:03:30 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/23 10:26:13 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char		*findn(char *buffn)
{
	char	*buff;
	size_t	i;
	int		j;

	j = BUFF_SIZE;
	i = 0;
	while (buffn[i] != '\n' && j--)
		i++;
	buff = ft_memalloc(i + 1);
	ft_memcpy(buff, buffn, i);
	return (buff);
}

static t_gnl		*get_first_line(const int fd, char **line)
{
	t_gnl			*new;
	char			buffn[BUFF_SIZE + 1];
	ssize_t			rd;
	char			*buff;

	*line = ft_strnew(BUFF_SIZE);
	new = (t_gnl*)malloc(BUFF_SIZE);
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		buff = ft_strdup(findn(buffn));
		*line = ft_strjoin(*line, buff);
		if (ft_strcmp(buff, buffn) != 0)
		{
			printf("%s", &**line);
			new->buff = ft_strchr(buffn, '\n') + 1;
			new->fd = fd;
			return (new);
		}
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	list = (t_gnl*)malloc(sizeof(list));
	t_gnl			*last;

	last = get_first_line(fd, line);
	last->next = list;
	list = last;
	// printf("%s", &**line);
	return (0);
}

int			main()
{
	int		file;
	char	*line = "12345";



	file = open("/Users/pcollio-/Projects/gnl/test", O_RDONLY);
	get_next_line(file, &line);
	return (0);
}
