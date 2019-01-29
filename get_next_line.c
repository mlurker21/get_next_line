/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 00:03:30 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/29 13:24:30 by mlurker          ###   ########.fr       */
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
	char			buffn[BUFF_SIZE + 1];
	ssize_t			rd = 0;

	if (list->buff && ft_strlen(list->buff))
	{
		*line = ft_strsub(list->buff, 0, ft_len_line(list->buff));
		if ((ft_strcmp(*line, list->buff)))
		{
			list->buff = ft_strchr(list->buff, '\n') + 1;
			return (list);
		}
	}
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		if ((ft_strchr(buffn, '\n')))
		{
			if (rd < BUFF_SIZE)
			{
				*line = ft_strsub(buffn, 0, (size_t) rd);
				return (0);
			}
			if ((list->buff = ft_strchr(buffn, '\n') + 1))
			{
				if (!(*line))
					*line = ft_strsub(buffn, 0, ft_len_line(buffn));
				else
					*line = ft_strjoin(*line, ft_strsub(buffn, 0, ft_len_line(buffn)));
				list->fd = fd;
				return (list);
			}
		}
		else
			*line = ft_strjoin(*line, buffn);
		ft_bzero(buffn, BUFF_SIZE + 1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*temp;

	if (!(list))
		list = (t_gnl*)ft_lstnew(NULL, BUFF_SIZE);
	temp = list;
	while (temp->fd != fd && temp->next)
		temp = temp->next;
	if (list->fd == fd || list->fd == 0)
	{
		get_first_line(fd, line, list);
		return (1);
	}
	if (!(temp = temp->next))
	{
		temp = (t_gnl*)ft_lstnew(NULL, BUFF_SIZE);
		get_first_line(fd, line, temp);
		return (1);
	}
	return (0);
}

int			main()
{
	int file1 = 0;
	int file2 = 0;
	char *line;
	int i = 6;
	file1 = open("/Users/mlurker/Desktop/gnl_new/test", O_RDONLY);
	ft_putstr("-> 1 file: \n");
	while (i-- != 0)
	{
		get_next_line(file1, &line);
		ft_putstr(&*line);
		ft_putstr("\n");
		free(line);
	}
//	free(line);
	i = 5;
	file2 = open("/Users/mlurker/Desktop/gnl_new/test2", O_RDONLY);
	ft_putstr("-> 2 file: \n");
	while (i-- != 0)
	{
		get_next_line(file2, &line);
		ft_putstr(&*line);
		ft_putstr("\n");
		free(line);
	}
//	free(line);
	i = 3;
	ft_putstr("-> 1 file: \n");
	while (i-- != 0)
	{
		get_next_line(file1, &line);
		ft_putstr(&*line);
		ft_putstr("\n");
		free(line);
	}
}




//static char *ft_find_n(char *buffn, char **line)
//{
//	int 	i;
//	char	*buff;
//
//	i = 0;
//	buff = ft_strnew(BUFF_SIZE);
//	if (*buffn == '\n')
//		buffn++;
//	while (*buffn != '\n' && *buffn)
//	{
//		buff[i] = *buffn++;
//		i++;
//	}
//
//	*line = ft_strjoin(*line, buff);
//	free(buff);
//	return (buffn);
//}
//
//static int get_first_line(const int fd, char **line, t_gnl *list)
//{
//	char		buffn[BUFF_SIZE + 1];
//	ssize_t		rd = 0;
//
//	if (list->buff && ft_strlen(list->buff))
//	{
//		list->buff = ft_find_n(list->buff, line);
//		if (list->buff && ft_strlen(list->buff))
//			return (1);
//	}
//	while ((rd = read(fd, buffn, BUFF_SIZE)))
//	{
//		list->buff = ft_find_n(buffn, line);
//		if (!(ft_strlen(list->buff)))
//			return (1);
//	}
//	return (0);
//}

