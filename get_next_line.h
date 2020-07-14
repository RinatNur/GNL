#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char		*ft_strdup(const char *str);
int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
char		*ft_strchr(const char *s, int c);
//void		*ft_memcpy(void *dest, const void *src, size_t n);
//size_t		ft_strlcpy(char *dst, const char *src, size_t size);

#endif