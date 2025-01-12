/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:57:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/01/12 17:57:53 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "get_next_line.h"

char  *ft_strjoin(char *dest, char *src)
{
  size_t  i;
  size_t  j;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  while (src[j])
  {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  return (dest);
}

char *strchr(const char *s, int c)
{
  size_t  i;

  i = 0;
  while (s[i] != '\0')
  {
    if (s[i] == (unsigned char) c)
      return ((char *) (s + i));
    i++;
  }
  if (c == '\0')
    return ((char *) (s + i));
  return (NULL);
}

void  *ft_calloc(size_t nmemb, size_t size)
{
  void  *arr;
  size_t  i;

  if (size != 0 && nmemb > SIZE_MAX / size)
    return (NULL);
  arr = malloc(nmemb * size);
  i = 0;
  while (i < nmemb * size)
  {
    ((char *) arr)[i] = '\0';
    i++;
  }
  return (arr);
}
