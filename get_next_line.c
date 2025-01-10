#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

size_t  ft_strlen(char *str)
{
  size_t  len;

  len = 0;
  while (str[len] != '\0')
    len++;
  return (len);
}

char  *get_next_line(int fd)
{
  size_t  len;
  char  buffer[1024];
  char  *line;

  read(fd, buffer, 20);
  line = malloc(20);
  line[0] = '\0';
  ft_strjoin(line, buffer);
  printf("%s\n", buffer);
  return (line);
}

int main()
{
  int fd;
  char *res;

  fd = open("./text", O_RDONLY);
  res = get_next_line(fd);
  printf("%s", res);
}
