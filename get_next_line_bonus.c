/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:57:33 by dsemenov          #+#    #+#             */
/*   Updated: 2025/01/20 19:55:45 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static char	*read_loop(int fd, char *remainder, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(remainder, buffer);
		free(remainder);
		if (!tmp)
			return (NULL);
		remainder = tmp;
	}
	return (remainder);
}

static char	*read_to_remainder(int fd, char *remainder)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(remainder);
		return (NULL);
	}
	remainder = read_loop(fd, remainder, buffer);
	free(buffer);
	if (!remainder)
		return (NULL);
	return (remainder);
}

static char	*extract_line(char *remainder)
{
	char	*line;
	size_t	i;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = ft_substr(remainder, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*clean_remainder(char *remainder)
{
	size_t	len;
	char	*tmp;
	char	*new_start;

	tmp = ft_strchr(remainder, '\n');
	if (!tmp)
	{
		free(remainder);
		return (NULL);
	}
	tmp++;
	len = ft_strlen(tmp);
	new_start = ft_substr(tmp, 0, len);
	if (!new_start)
	{
		free(remainder);
		return (NULL);
	}
	free(remainder);
	return (new_start);
}

char	*get_next_line(int fd)
{
	static char	*remainder[FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_to_remainder(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = extract_line(remainder[fd]);
	if (!line)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	if (!line[0])
	{
		free(line);
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	remainder[fd] = clean_remainder(remainder[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("./text", O_RDONLY);
  do
  {
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
  }
  while (res);
  return (0);
}
*/