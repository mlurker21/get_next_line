/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:39 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/03 21:12:28 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static void		cut_line(char **line, char *temp)
{
	size_t	i;
	char	*line_n;

	i = 0;
	line_n = ft_strnew(0);
	while (*temp && *temp != '\n')
		line_n[i++] = *temp++;
	line_n[i] = '\0';
	*line = ft_strcat(*line, line_n);
	free(line_n);
}

static int		get_line(const int fd, char **line, char **multy_n)
{
	char	buffn[BUFF_SIZE + 1];
	ssize_t	rd;
	char	*temp;

	*line = ft_strnew(0);
	if (multy_n[0] != '\0')
	{
		cut_line(line, *multy_n);
//		*line = ft_strjoin(*line, ft_strsub(*multy_n, 0, find_n(*multy_n)));
		if ((ft_strchr(*multy_n, '\n')))
		{
			*multy_n = ft_strchr(*multy_n, '\n') + 1;
			return (1);
		}
	}
	temp = ft_memalloc(BUFF_SIZE);
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		temp = ft_strcpy(temp, buffn);
		temp[rd] = '\0';
		if (rd < BUFF_SIZE)
		{
			cut_line(line, temp);
//			*line = ft_strjoin(*line, ft_strsub(temp, 0, find_n(temp)));
			if (ft_strchr(temp, '\n'))
				*multy_n = ft_strchr(temp, '\n') + 1;
			break ;
		}
		if (ft_strchr(temp, '\n'))
		{
			*multy_n = ft_strchr(temp, '\n') + 1;
			cut_line(line, temp);
//			*line = ft_strjoin(*line, ft_strsub(temp, 0, find_n(temp)));
			break ;
		}
		*line = ft_strjoin(*line, temp);
	}
	free(temp);
	if (rd)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *multy[1023];

	if (!line || fd < 0 || fd > 1022 || (read(fd, multy[fd], 0) < 0))
		return (-1);
	if (get_line(fd, line, &multy[fd]))
		return (1);
	bzero(multy, BUFF_SIZE);
	return (0);
}


int			main()
{
//	int		file1 = open("/Users/mlurker/Desktop/final_libft/test_lib/42FileChecker/srcs/gnl/gnl7_2.txt", O_RDONLY);
	int		file1 = open("/Users/mlurker/Desktop/gnl_new copy/test2", O_RDONLY);
	int		file2 = open("/Users/mlurker/Desktop/gnl_new copy/test", O_RDONLY);
	char	*line;
	int		i;

	ft_putstr("-> 1 file: \n");
	i = 8;
	while (i--)
	{
		get_next_line(file1, &line);
		ft_putstr(line);
		ft_putchar('\n');
	}
}
