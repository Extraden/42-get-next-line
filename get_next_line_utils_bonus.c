/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:57:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/01/20 19:56:23 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	res = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		res[i + j] = str2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

static char	*ft_return_empty_str(void)
{
	char	*res;

	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	char	*res;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		res = ft_return_empty_str();
		return (res);
	}
	tmp = (char *)s;
	tmp += start;
	if (ft_strlen(tmp) < len)
		res = malloc(ft_strlen(tmp) + 1);
	else
		res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (tmp[i] && i < len)
	{
		res[i] = tmp[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
