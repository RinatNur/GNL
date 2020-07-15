/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:35:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/15 21:23:43 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (NULL == s)
		return (0);
	while (s[i] && s[i] != '\0')
		i++;
	return (i);
}

int ft_free(char *s)
{
	free(s);
	return 1;
}

char		*ft_strjoin(char  *s1, char const *s2)
{
	char		*str;
	size_t		str_len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	str_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (ft_free(s1) ? NULL : 0);
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
	free(s1);
	return (str);
}

char		*ft_strdup(char *str)
{
	char	*buff;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(buff = (char *)malloc(sizeof(*str) * (i + 1))))
		return (ft_free(str) ? NULL : 0);
	i = 0;
	while (str[i])
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
//	if (str)
//		free(str);
	return (buff);
}
