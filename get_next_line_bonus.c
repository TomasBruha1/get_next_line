/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:27:10 by tbruha            #+#    #+#             */
/*   Updated: 2024/08/26 17:27:12 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*r_line;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	if (fd1 < 0)
// 	{
// 		write(1, "ERROR\n", 6);
// 		return (0);
// 	}
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd2 < 0)
// 	{
// 		write(1, "ERROR\n", 6);
// 		return (0);
// 	}
// 	fd3 = open("test3.txt", O_RDONLY);
// 	if (fd2 < 0)
// 	{
// 		write(1, "ERROR\n", 6);
// 		return (0);
// 	}
// 	r_line = get_next_line(fd1);
// 	printf("%s", r_line);
// 	if (r_line != NULL)
// 		free(r_line);
// 	r_line = get_next_line(fd2);
// 	printf("%s", r_line);
// 	if (r_line != NULL)
// 		free(r_line);
// 	r_line = get_next_line(fd3);
// 	printf("%s", r_line);
// 	if (r_line != NULL)
// 		free(r_line);
// 	r_line = get_next_line(fd1);
// 	printf("%s", r_line);
// 	if (r_line != NULL)
// 		free(r_line);
// 	r_line = get_next_line(fd2);
// 	printf("%s", r_line);
// 	if (r_line != NULL)
// 		free(r_line);
// 	r_line = get_next_line(fd3);
// 	printf("%s", r_line);
// 	if (r_line != NULL)
// 		free(r_line);
// 	return (0);
// }

// Last fix was "calloc" for r.
// To make the bonus I need to change static to array [].
char	*get_next_line(int fd)
{
	static char	*r[MAX_FD];
	char		*r_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else if (r[fd] == NULL)
	{
		r[fd] = malloc(BUFFER_SIZE + 1);
		i = 0;
		while (i < BUFFER_SIZE + 1)
			r[fd][i++] = 0;
	}
	if (!r[fd])
		return (NULL);
	r[fd] = read_content(fd, r[fd]);
	if (r[fd] != NULL)
	{
		r_line = prep_current_line(r[fd]);
		r[fd] = get_rest(r[fd]);
	}
	else
		r_line = NULL;
	return (r_line);
}

// I sent static here and put everything that is read 
// until first newline here and return.
char	*read_content(int fd, char *r)
{
	char	*buff;
	int		fd_r;

	while (ft_strchr(r, '\n') == NULL)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		fd_r = read(fd, buff, BUFFER_SIZE);
		if (fd_r <= 0)
		{
			free(buff);
			if (r[0] == 0 || fd_r < 0)
			{
				free(r);
				return (NULL);
			}
			return (r);
		}
		buff[fd_r] = '\0';
		r = ft_strjoin(r, buff);
		free(buff);
	}
	return (r);
}

// I'm sending read line including last buffer including '\n'.
// Just cut off what is after \n.
char	*prep_current_line(char *read)
{
	char	*line;
	int		i;

	i = 0;
	while (read[i] != '\n' && read[i] != '\0')
		i++;
	line = ft_substr(read, 0, i + 1);
	return (line);
}

// Also sending here the whole line with the differenc that I want only the end.
char	*get_rest(char *read)
{
	char	*rest;
	int		i;

	i = 0;
	while (read[i] != '\n' && read[i] != '\0')
		i++;
	rest = ft_substr(read, i + 1, ft_strlen(read));
	if (!rest)
	{
		free(read);
		return (NULL);
	}
	free(read);
	return (rest);
}
