/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:57:33 by dsemenov          #+#    #+#             */
/*   Updated: 2025/01/18 20:13:53 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*read_to_remainder(int fd, char *remainder)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
    {
    	free(buffer);
			return (NULL);
    }
	}
	buffer[bytes_read] = '\0';
	tmp = ft_strjoin(remainder, buffer);
	// if (!tmp)
	// {
	// 	free(buffer);
	// 	return (NULL);
	// }
	// free(remainder);
	// remainder = tmp;
	// }
	// free(buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_to_remainder(fd, remainder);
	return (remainder);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("./text", O_RDONLY);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s", res);
}
