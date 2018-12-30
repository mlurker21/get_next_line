/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 00:03:30 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/30 19:29:45 by mlurker          ###   ########.fr       */
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

	*line = ft_strnew(BUFF_SIZE);
	new = (t_gnl*)malloc(BUFF_SIZE);
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		new->buff = ft_strdup(findn(buffn));
		*line = ft_strjoin(*line, new->buff);
		if (ft_strcmp(new->buff, buffn) != 0)
		{
			printf("%s", &**line);
			new->buff = ft_strchr(buffn, '\n') + 1;
			new->fd = fd;
			return (new);
		}
		free(new->buff);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*list;

	list = (t_gnl*)malloc(sizeof(list));
	if (list->fd == 0)
		list = get_first_line(fd, line);
	while (list->fd != fd)
		list = list->next;
	if (list->next == NULL)
		list->next = get_first_line(fd, line);
	if (list->fd == fd)
		list = get_first_line(list->fd, &list->buff);
	
	return (0);
}

int			main()
{
	int		file;
	char	*line = "12345";
	int i = 2;

	file = open("/Users/pcollio-/Projects/gnl/test", O_RDONLY);
	//while(i--)
		get_next_line(file, &line);
	return (0);
}
