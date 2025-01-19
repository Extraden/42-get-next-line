/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:57:33 by dsemenov          #+#    #+#             */
/*   Updated: 2025/01/19 20:16:05 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*read_to_remainder(int fd, char *remainder)
{
  char  *buffer;
  ssize_t bytes_read;
  //char  *tmp;

  buffer = (char *) malloc((BUFFER_SIZE + 1) * (sizeof (char)));
  if (!buffer)
    return (NULL);
  bytes_read = 1;
  while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
  {
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0)
    {
      free(buffer);
      return (NULL);
    }
    buffer[bytes_read] = '\0';
    remainder = ft_strjoin(remainder, buffer);
    if (!remainder)
      return (NULL);
  }
  //remainder = buffer;
  return (remainder);
}

static char *extract_line(char *remainder)
{
  char  *line;
  size_t i;

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

static char *clean_remainder(char *remainder)
{
  remainder = ft_strchr(remainder, '\n');
  if (!remainder)
    return (NULL);
  remainder++;
  return (remainder);
}

char	*get_next_line(int fd)
{
	static char *remainder;
  char  *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_to_remainder(fd, remainder);
  line = extract_line(remainder);
  remainder = clean_remainder(remainder);

	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("./text", O_RDONLY);
	res = get_next_line(fd);
	printf("%s", res);
	res = get_next_line(fd);
	printf("%s", res);
	res = get_next_line(fd);
	printf("%s", res);
}
*/
