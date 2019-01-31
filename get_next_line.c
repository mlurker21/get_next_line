/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:39 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/31 19:27:51 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static size_t	find_n(const char *buffn)
{
	size_t	i;

	i = 0;
	while (buffn[i] && buffn[i] != '\n')
		i++;
	return (i);
}

static int		get_line(const int fd, char **line, char **multy_n)
{
	char	buffn[BUFF_SIZE + 1];
	ssize_t	rd;
	size_t i = 0;
//	char *temp;

	*line = ft_strnew(0);
	if (*multy_n)
	{
		*line = ft_strjoin(*line, ft_strsub(*multy_n, 0, find_n(*multy_n)));
		*multy_n = ft_strchr(*multy_n, '\n') + 1;
		if (*multy_n)
			return (1);
	}
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
//		*multy[rd] = '\0';
		if (rd < BUFF_SIZE)
		{
			*line = ft_strsub(buffn, 0, (size_t)rd);
			return (0);
		}
		if ((ft_strchr(buffn, '\n')))
		{
			*multy_n = ft_strchr(buffn, '\n') + 1;
			*line = ft_strjoin(*line, ft_strsub(buffn, 0, find_n(buffn)));
			return (1);
		}
		*line = ft_strjoin(*line, ft_strsub(buffn, 0, BUFF_SIZE));
	}
	return (-1);
}

static t_gnl	*init_struct(t_gnl *multy)
{
	multy = (t_gnl*)ft_memalloc(sizeof(*multy));
	if (multy)
	{
		if (!(multy->buffn = malloc(BUFF_SIZE + 1)))
		{
			free(multy);
			return (NULL);
		}
		multy->buffn = NULL;
		multy->fd = 0;
		multy->next = NULL;
	}
	return (multy);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*multy;
//	t_gnl			*temp;

	if (!(*line) && fd < 0)
		return (-1);
	if (!(multy))
		multy = init_struct(multy);
	if (get_line(fd, line, &(multy->buffn)))
		return (1);
	return (0);
}

int			main()
{
	int		file1 = open("/Users/mlurker/Desktop/gnl_new/test", O_RDONLY);
	int		file2 = open("/Users/mlurker/Desktop/gnl_new/test2", O_RDONLY);
	char	*line;
	int		i;

	ft_putstr("-> 1 file: \n");
	i = 5;
	while (i--)
	{
		get_next_line(file1, &line);
		ft_putstr(line);
		ft_putchar('\n');
//		ft_strdel(&line);
	}
}
