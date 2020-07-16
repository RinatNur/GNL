/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:10:35 by jheat             #+#    #+#             */
/*   Updated: 2020/07/16 22:45:08 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*check(char **line, char **buf_tail)
{
	char		flag;
	char		*p;
	char		*p_l;

	p = NULL;
	flag = 1;
	if ((p = ft_strchr(*buf_tail, '\n')))
	{
		*p = '\0';
		if (!(p_l = ft_strdup(++p, 0)))
			return (p = &flag);
		if (!(*line = ft_strdup(*buf_tail, 1)))
		{
			free(p_l);
			return (p = &flag);
		}
		if (!(*buf_tail = ft_strdup(p_l, 1)))
		{
			free(*line);
			return (p = &flag);
		}
	}
	return (p);
}

static char		*check_buf_tail(char **line, char **buf_tail)
{
	char		flag;
	char		*p;

	p = NULL;
	flag = 1;
	if (*buf_tail)
	{
		if ((p = check(line, &(*buf_tail))) && *p == 1)
			return (p);
		else if (NULL == p)
		{
			if (!(*line = ft_strdup(*buf_tail, 1)))
				return (p = &flag);
			*buf_tail = NULL;
		}
	}
	else
	{
		if (!(*line = ft_strdup("", 0)))
			return (p = &flag);
	}
	return (p);
}

int				get_next_line(int fd, char **line)
{
	static char		*buf_tail;
	char			buf[BUFFER_SIZE + 1];
	int				num_of_reading_bytes;
	char			*p;

	if (BUFFER_SIZE < 1 || fd < 0 || !line || (read(fd, 0, 0) == -1) ||
	((p = check_buf_tail(line, &buf_tail)) && *p == 1))
		return (-1);
	while (!p && (num_of_reading_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[num_of_reading_bytes] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			if (!(buf_tail = ft_strdup(++p, 0)))
			{
				free(*line);
				return (-1);
			}
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	return (num_of_reading_bytes || ft_strlen(buf_tail) || p ? 1 : 0);
}
