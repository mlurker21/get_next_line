/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:39 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/09 23:58:44 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static int		cut_line(char **line, char *temp, char **multy_n)
{
	int		i;
	int 	check;
	char 	*line_n;

	i = 0;
	check = 1;
	line_n = ft_strdup(temp);
	if (*temp == '\n')
		temp++;
	while (*temp != '\0' && *temp != '\n')
		line_n[i++] = *temp++;
	line_n[i] = '\0';
	*line = ft_strjoin(line, &line_n);
	if (*temp == '\n')
		check = 2;
	*multy_n = ft_strdup(temp);
	return (check);
//	if check == 2 -> string ending on \n, if check == 1 -> \0
}

static ssize_t	read_line(const int fd, char **line, char **multy_n)
{
	char	buffn[BUFF_SIZE + 1];
	ssize_t	rd;

	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		buffn[rd] = '\0';
		if (rd < BUFF_SIZE)
		{
			rd = cut_line(line, buffn, &multy_n[fd]);
			break ;
		}
		if (ft_strchr(buffn, '\n'))
		{
			if (*buffn == '\n')
			{
				multy_n[fd] = ft_strdup(buffn);
				rd = 2;
				break ;
			}
			rd = cut_line(line, buffn, &multy_n[fd]);
			break ;
		}
		rd = cut_line(line, buffn, &multy_n[fd]);
	}
	return (rd);
}

int				get_next_line(const int fd, char **line)
{
	static char *multy[1023];
	ssize_t check;

	check = 0;
	if (!line || fd < 0 || fd > 1022 || (read(fd, multy[fd], 0) < 0))
		return (-1);
	*line = ft_strnew(0);
	if (!(multy[fd]) || *(multy[fd]) == '\0')
		check = read_line(fd, line, multy);
	else
	{
		check = cut_line(line, multy[fd], &multy[fd]);
		if (check == 2 && ft_strlen(multy[fd]) <= 1)
			multy[fd]++;
		if (check == 1)
			check = read_line(fd, line, multy);
	}
	if (check > 0)
		return (1);
//	free(multy[fd]);
//	ft_bzero(multy, BUFF_SIZE);
	return (0);
}

int			main()
{
	int		file1 = open("/Users/pcollio-/Projects/get_next_line/test", O_RDONLY);
	int		file2 = open("/Users/pcollio-/Projects/get_next_line/test2", O_RDONLY);
	char	*line;
	int		i;

	ft_putstr("-> 1 file: \n");
	i = 0;
	while (i < 4)
	{
		i++;
		get_next_line(file1, &line);
		ft_putstr(line);
		ft_putchar('\n');
	}
//	ft_putstr("-> 2 file: \n");
//	i = 0;
//	while (i < 4)
//	{
//		i++;
//		get_next_line(file2, &line);
//		ft_putstr(line);
//		ft_putchar('\n');
//	}
//	ft_putstr("-> 1 file again: \n");
//	i = 0;
//	while (i < 4)
//	{
//		i++;
//		get_next_line(file1, &line);
//		ft_putstr(line);
//		ft_putchar('\n');
//	}
}