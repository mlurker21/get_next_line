/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:39 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/03 21:55:02 by pcollio-         ###   ########.fr       */
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
	while (*temp + 1 != '\0' && *temp != '\n')
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


//int				main(void)
//{
//	char		*line;
//	int			fd;
//	int			ret;
//	int			count_lines;
//	char		*filename;
//	int			errors;
//
//	filename = "/Users/mlurker/Desktop/final_libft/test_lib/42FileChecker/srcs/gnl/gnl_to_free_or_not_to_free.txt";
//	fd = open(filename, O_RDONLY);
//	if (fd > 2)
//	{
//		count_lines = 0;
//		errors = 0;
//		line = NULL;
//		while ((ret = get_next_line(fd, &line)) > 0)
//		{
//			if (count_lines == 0 && strcmp(line, "This is the first line") != 0)
//				errors++;
//			if (count_lines == 1 && strcmp(line, "This is the second one") != 0)
//				errors++;
//			if (count_lines == 2 && strcmp(line, "This is the third") != 0)
//				errors++;
//			if (count_lines == 3 && strcmp(line, "This is the last") != 0)
//				errors++;
//			count_lines++;
//			free(line);
//			if (count_lines > 50)
//				break ;
//		}
//		close(fd);
//		if (count_lines != 4)
//			printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
//		if (errors > 0)
//			printf("-> must have read \"This is the first line\", \"This is the second one\", \"This is the third\", \"This is the last\".\n");
//		if (count_lines == 4 && errors == 0)
//			printf("OK");
//	}
//	else
//		printf("An error occured while opening file %s\n", filename);
//	return (0);
//}
int			main()
{
//	int		file1 = open("/Users/mlurker/Desktop/gnl/test2", O_RDONLY);
	int		file1 = open("/Users/mlurker/Desktop/final_libft/test_lib/42FileChecker/moulitest_42projects/get_next_line_tests/sandbox/one_big_fat_line.txt", O_RDONLY);
	int		file2 = open("/Users/mlurker/Desktop/gnl/test", O_RDONLY);
	char 	*str = "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\n\n";
	char	*line;
	int		i;

	ft_putstr("-> 1 file: \n");
	i = 0;
	while (i < 2)
	{
		get_next_line(file1, &line);
		ft_putstr(line);
//		ft_putchar('\n');
//		ft_putchar('3');
//		ft_putchar('\n');
//		ft_putstr(str);
//		ft_putchar('1');
//		while (*line == str[i])
//		{
//			line++;
			i++;
//		}
//		printf("%d\n", i);
//
////		printf("%s\n", ft_strcspn(line, str));
//		printf("%c\n", str[i]);
//		printf("%d\n", ft_strcmp(line, str));
		free(line);
	}
//
//	ft_putchar('c');
//	ft_putstr("-> 2 file: \n");
//	i = 0;
//	while (i < 6)
//	{
//		i++;
//		get_next_line(file2, &line);
//		ft_putstr(line);
//		ft_putchar('\n');
//		free(line);
//	}
//	ft_putstr("-> 1 file: \n");
//	i = 0;
//	while (i < 4)
//	{
//		i++;
//		get_next_line(file1, &line);
//		ft_putstr(line);
//		ft_putchar('\n');
//		free(line);
//	}
}
