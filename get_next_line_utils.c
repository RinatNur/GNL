/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:35:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/11 20:31:56 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}


size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		src_len;
	size_t		len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (size)
	{
		if (src_len >= size)
			len = size - 1;
		else
			len = src_len;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (src_len);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (NULL == s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		str_len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[str_len] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*buff;
	int		i;

	i = 0;
	while (str[i])
		i++;
	buff = (char *)malloc(sizeof(*str) * (i + 1));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}