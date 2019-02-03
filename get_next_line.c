/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:39 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/03 18:01:04 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char		*cut_line(char **line1, char **multy_n, char const *temp)
{
	size_t	i;
	char	*line_n;

	i = 0;
	line_n = ft_strnew(0);
	while (*temp && *temp != '\n')
		line_n[i++] = *temp++;
	line_n[i] = '\0';
	*line1 = ft_strcat(*line1, line_n);
	if (*temp)
		*multy_n = ft_strchr(temp, '\n') + 1;
	else
		*multy_n = ft_strcpy(*multy_n, temp);
	free(line_n);
	return (*line1);
}

static int		get_line(const int fd, char **line, char **multy_n)
{
	char	buffn[BUFF_SIZE + 1];
	ssize_t	rd;
	char	*temp;
	int 	check;

	check = 0;
	*line = ft_strnew(0);
	if (multy_n[0] && ft_strlen(*multy_n))
	{
		*line = cut_line(line, multy_n, *multy_n);
		if (ft_strlen(*multy_n))
			return (1);
		check = 1;
	}
	temp = ft_strnew(0);
	while ((rd = read(fd, buffn, BUFF_SIZE)))
	{
		temp = ft_strcpy(temp, buffn);
		temp[rd] = '\0';
		if (ft_strchr(temp, '\n') || rd < BUFF_SIZE)
		{
			*line = cut_line(line, multy_n, temp);
			check = 1;
			break ;
		}
		*line = ft_strcat(*line, temp);
	}
	free(temp);
	if (rd || check)
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
	int		file1 = open("/Users/mlurker/Desktop/gnl_new copy/test", O_RDONLY);
	int		file2 = open("/Users/mlurker/Desktop/gnl_new copy/test2", O_RDONLY);
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
