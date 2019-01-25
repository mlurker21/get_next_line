/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 00:03:30 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/25 23:37:54 by pcollio-         ###   ########.fr       */
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
	ssize_t			rd = 0;

	new = list;
	if (new->buff)
	{
		*line = ft_strsub(new->buff, 0, ft_len_line(new->buff));
		if ((ft_strcmp(*line, new->buff)))
		{
			new->buff = ft_strchr(new->buff, '\n') + 1;
			return (new);
		}
	}
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		if ((new->buff = ft_strchr(buffn, '\n') + 1))
		{
			if (!(*line))
				*line = ft_strsub(buffn, 0, ft_len_line(buffn));
			else
				ft_strncat(*line, buffn, ft_len_line(buffn));
			new->fd = fd;
			return (new);
		}
		*line = ft_strjoin(*line, buffn);
		ft_bzero(buffn, BUFF_SIZE + 1);
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
	while (temp->fd != fd && temp->next)
		temp = temp->next;
	if (!(temp = temp->next))
	{
		list = get_first_line(fd, line, list);
		return (1);
	}
	return (0);
}

int			main()
{
	int		file1 = 0;
	int		file2 = 0;
	char	*line;
	int i = 5;
	file1 = open("/Users/pcollio-/Projects/gnl/test", O_RDONLY);
	ft_putstr("-> 1 file: \n");
	while(i-- != 0)
	{
		get_next_line(file1, &line);
		ft_putstr(&*line);
		ft_putstr("\n");
		free(line);
	}
	i = 6;
	file2 = open("/Users/pcollio-/Projects/gnl/test2", O_RDONLY);
	ft_putstr("-> 2 file: \n");
	while(i-- != 0)
	{
		get_next_line(file2, &line);
		ft_putstr(&*line);
		ft_putstr("\n");
		free(line);
	}
	i = 3;
	ft_putstr("-> 1 file: \n");
	while(i-- != 0)
	{
		get_next_line(file1, &line);
		ft_putstr(&*line);
		ft_putstr("\n");
		free(line);
	}
	return (0);
}