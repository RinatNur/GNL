/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:10:35 by jheat             #+#    #+#             */
/*   Updated: 2020/07/12 18:46:58 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 1000

int 	get_next_line(int fd,char **line)
{
	static char		*buf_tail;
	char			buf[BUF_SIZE + 1];
	int 			num_of_reading_bytes;
	char 			*p = NULL;
	char 			*p_l =NULL;

	if (BUF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (buf_tail)
	{
		if ((p = ft_strchr(buf_tail, '\n'))) {
			*p = '\0';
			*line = ft_strdup(buf_tail);
			buf_tail = ft_strdup(++p);
		} else
		{
			*line = ft_strdup(buf_tail);
			free(buf_tail);
			buf_tail = NULL;
		}
	}
	else
		*line = ft_strnew(1);
	while (!p && (num_of_reading_bytes = read(fd, buf, BUF_SIZE)) > 0)
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

	return (num_of_reading_bytes || ft_strlen(*line) || ft_strlen(buf_tail) ? 1 : 0);
}

int		main(void)
{
	int		fd;
	char	*line = NULL;
	fd = open("../test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file not open\n");
		return (1);
	}

	while ((get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}
	return (0);


}
