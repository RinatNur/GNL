/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:10:35 by jheat             #+#    #+#             */
/*   Updated: 2020/07/14 17:01:51 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*buf_tail;
	char			buf[BUFFER_SIZE + 1];
	int				num_of_reading_bytes;
	char			*p;
	char			*p_l;

	p_l = NULL;
	p = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (buf_tail)
	{
		if ((p = ft_strchr(buf_tail, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(buf_tail);
			p++;
			p_l = ft_strdup(p);
			free(buf_tail);
			buf_tail = ft_strdup(p_l);
			free(p_l);
		}
		else
		{
			*line = ft_strdup(buf_tail);
			free(buf_tail);
			buf_tail = NULL;
		}
	}
	else
		*line = ft_strnew(1);
	while (!p && (num_of_reading_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[num_of_reading_bytes] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			buf_tail = ft_strdup(++p);
		}
		p_l = *line;
		*line = ft_strjoin(*line, buf);
		if (p_l)
			free(p_l);
	}
	if (num_of_reading_bytes == -1)
		return (-1);
	return (num_of_reading_bytes || ft_strlen(buf_tail) || p ? 1 : 0);
}
