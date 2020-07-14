/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:33:35 by jheat             #+#    #+#             */
/*   Updated: 2020/07/14 20:35:45 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

# include <stdlib.h>
# include <unistd.h>

char		*ft_strdup(const char *str);
int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
char		*ft_strchr(const char *s, int c);

#endif
