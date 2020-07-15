/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:10:35 by jheat             #+#    #+#             */
/*   Updated: 2020/07/15 21:02:22 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*check_buf_tail(char **line, char **buf_tail)
{
	char		*p;
	char		*p_l;
	char 		flag;

	flag = 1;
	p = NULL;
	if (*buf_tail)
	{
		if ((p = ft_strchr(*buf_tail, '\n')))
		{
			*p = '\0';
			if (!(*line = ft_strdup(*buf_tail)))
			{
				free(buf_tail);
				return (p = &flag);
			}
			p_l = ft_strdup(++p);
			free(*buf_tail);
			*buf_tail = ft_strdup(p_l);
			free(p_l);
		}
		else
		{
			*line = ft_strdup(*buf_tail);
			free(*buf_tail);
			*buf_tail = NULL;
		}
	}
	else
		*line = ft_strdup("");
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
			buf_tail = ft_strdup(++p);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (num_of_reading_bytes || ft_strlen(buf_tail) || p ? 1 : 0);
}
