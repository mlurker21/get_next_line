/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:39 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/02 22:33:16 by mlurker          ###   ########.fr       */
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
	char	*temp;

	*line = ft_strnew(0);
	if (multy_n[0] != '\0')
	{
		*line = ft_strjoin(*line, ft_strsub(*multy_n, 0, find_n(*multy_n)));
		if ((ft_strchr(*multy_n, '\n')))
		{
			*multy_n = ft_strchr(*multy_n, '\n') + 1;
			return (1);
		}
	}
	temp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		temp = buffn;
		temp[rd] = '\0';
		if (rd < BUFF_SIZE)
		{
			*line = ft_strjoin(*line, ft_strsub(temp, 0, find_n(temp)));
			if (ft_strchr(temp, '\n'))
			{
				*multy_n = ft_strchr(temp, '\n') + 1;
				free(temp);
				return (1);
			}
			free(temp);
			return (0);
		}
		if ((ft_strchr(temp, '\n')))
		{
			*multy_n = ft_strchr(temp, '\n') + 1;
			*line = ft_strjoin(*line, ft_strsub(temp, 0, find_n(temp)));
			free(temp);
			return (1);
		}
		*line = ft_strjoin(*line, temp);
	}
	free(temp);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *multy[1023];

	if (!(line) || !(read(fd, multy[fd], 0)))
		return (-1);
	if (get_line(fd, line, &multy[fd]))
		return (1);
	bzero(multy, BUFF_SIZE);
	return (0);
}


int			main()
{
	int		file1 = open("/Users/mlurker/Desktop/gnl_new copy/test", O_RDONLY);
	int		file2 = open("/Users/mlurker/Desktop/gnl_new copy/test2", O_RDONLY);
	char	*line;
	int		i;

	ft_putstr("-> 1 file: \n");
	i = 8;
	while (i--)
	{
		get_next_line(file1, &line);
		ft_putstr(&*line);
		ft_putchar('\n');
	}
}
