/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:57:33 by dsemenov          #+#    #+#             */
/*   Updated: 2025/01/12 17:57:35 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUFFER_SIZE 20

char  *get_next_line(int fd)
{
  size_t  len;
  char  buffer[BUFFER_SIZE + 1];
  char  *line;
  size_t  bytes_read;

  bytes_read = read(fd, buffer, BUFFER_SIZE);
  buffer[BUFFER_SIZE] = '\0';
  line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
  ft_strjoin(line, buffer);
  return (line);
}

int main()
{
  int fd;
  char *res;

  fd = open("./text", O_RDONLY);
  res = get_next_line(fd);
  printf("%s\n", res);
  res = get_next_line(fd) ;
  printf("%s", res);
}
 
