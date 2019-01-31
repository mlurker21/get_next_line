/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:39 by pcollio-          #+#    #+#             */
/*   Updated: 2019/01/31 16:49:11 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char		*cut_buffn(char *buffn, t_gnl *multy)
{
	int		i;
	char	*buff;

	i = 0;
	buff = ft_strnew(BUFF_SIZE);
//	if (buffn[0] == '\n' && buffn[1] )
	while (*buffn != '\n' && i <= BUFF_SIZE)
		buff[i++] = *buffn++;
	buff[i] = '\0';
//	multy->buff = buff;
//	multy->buff = ft_strdup(buff);
	//ft_strdel(&buff);
	return (buff);
}

static int		get_line(const int fd, char **line,t_gnl *multy)
{
	char	buffn[BUFF_SIZE + 1];
	ssize_t	rd;
//	char *temp;

	if (multy->buffn && multy->buffn[0])
	{
		*line = ft_strjoin(*line, cut_buffn(multy->buffn, multy));
		multy->buffn = ft_strchr(multy->buffn, '\n') + 1;
		if (multy->buffn[0])
			return (1);
	}
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		if (rd < BUFF_SIZE)
		{
			*line = ft_strjoin(*line, ft_strsub(buffn, 0, (size_t)rd));
			return (0);
		}
		if ((ft_strchr(buffn, '\n')))
		{
			multy->buffn = ft_strchr(buffn, '\n') + 1;
			*line = ft_strjoin(*line, cut_buffn(buffn, multy));
			return (1);
		}
		*line = ft_strjoin(*line, buffn);
	}
	return (-1);
}


int				get_next_line(const int fd, char **line)
{
	static t_gnl	*multy;
	t_gnl			*temp;

	if (!(*line) && fd < 0)
		return (-1);
	if (!(multy))
		multy = (t_gnl*)ft_lstnew(NULL, BUFF_SIZE);
	if (get_line(fd, line, multy))
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
		ft_putstr(&*line);
		ft_putchar('\n');
		ft_strdel(&line);
	}
}
