/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 00:03:30 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/20 21:48:05 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static size_t	ft_len_line(const char *buffn)
{
	size_t i;
	int j;

	j = BUFF_SIZE;
	i = 0;
	while (buffn[i] != '\n' && j--)
		i++;
	return (i);
}

static t_gnl		*get_first_line(const int fd, char **line, t_gnl *list)
{
	t_gnl			*new;
	char			buffn[BUFF_SIZE + 1];
	ssize_t			rd;

	*line = ft_strnew(BUFF_SIZE); //del
	new = list;
	if (list->buff)
	{
		ft_strncat(*line, list->buff, ft_len_line(list->buff));
		if (ft_strcmp(*line, list->buff) != 0)
		{
			list->buff = ft_strchr(list->buff, '\n') + 1;
			return (list);
		}
	}
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		new->buff = ft_strsub(buffn, 0, ft_len_line(buffn));
		*line = ft_strjoin(*line, new->buff);
		if (ft_strcmp(new->buff, buffn) != 0)
		{
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
	t_gnl			*temp;

	if (!(list))
		list = (t_gnl*)ft_lstnew(NULL, BUFF_SIZE);
	temp = list;
	if (list->fd == fd || list->fd == 0)
	{
		list = get_first_line(fd, line, list);
		return (1);
	}
	while (temp->next && temp->fd != fd)
		temp = temp->next;
	if (!(temp->next))
		list->next = get_first_line(fd, line, list);
	return (0);
}

int			main()
{
	int		file;
	char	*line = "12345";
	int i = 10;
	file = open("/Users/pcollio-/Projects/gnl/test", O_RDONLY);
	printf("-> 1 file: \n");
	while(i-- != 0)
	{
		get_next_line(file, &line);
		free(line);
		printf("%s \n", &*line);
	}
	i = 8;
	file = open("/Users/pcollio-/Projects/gnl/test2", O_RDONLY);
	printf("-> 2 file: \n");
	while(i-- != 0)
	{
		get_next_line(file, &line);
		free(line);
		printf("%s \n", &*line);
	}
	return (0);
}