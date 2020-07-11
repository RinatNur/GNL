/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:10:35 by jheat             #+#    #+#             */
/*   Updated: 2020/07/11 21:10:37 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 500

int 	get_next_line(int fd,char **line)
{
	static char 	*buf_tail;
	char 			*p_buf_tail = buf_tail;
	char 	buf[BUF_SIZE + 1];
	int 	num_of_reading_bytes;
	char 	*p = NULL;
	char 	*p_l =NULL;

	if (buf_tail)
	{
		if ((p = ft_strchr(buf_tail, '\n'))) {
			*p = '\0';
			*line = ft_strdup(buf_tail);
			//printf("p++ = %s\n", ++p);
			buf_tail = ft_strdup(++p);
		} else
		{
			*line = ft_strdup(buf_tail);
			//strclr(buf_tail);
			buf_tail = NULL;
		}
	}
	else
		*line = ft_strnew(1);
//	printf("p = %s", p);
	while (!p && (num_of_reading_bytes = read(fd, buf, BUF_SIZE)))
	{
		buf[num_of_reading_bytes] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			buf_tail = ft_strdup(++p);
//			printf("buf_tail = %s\n", buf_tail);
//			*line = ft_strjoin(*line, buf_tail);
		}
		p_l = *line;
		*line = ft_strjoin(*line, buf);
		if (p_l)
			free(p_l);
	}
	return (num_of_reading_bytes || ft_strlen(*line) || ft_strlen(buf_tail) ? 1 : 0);
	return(0);
}

//int		get_next_line(int fd, char **line)
//{
//	static char		*buf;
//	char 			*st_copy = &buf;
//
//	int				num_of_bytes;
//	int				i;
//	int 			j;
//	char			*n_pointer;
//	char			*b_pointer;
//
//	i = 0;
//	j = 0;
//	n_pointer = NULL;
//	if (!(*line = ft_strnew(1)))
//		return(-1);
//	if (!(buf = ft_strnew(BUF_SIZE)))
//		return(-1);
//	*line = ft_strjoin(*line, buf);
//	while ((num_of_bytes = read(fd, buf, BUF_SIZE)))
//	{
//		buf[num_of_bytes] = '\0';
//		//printf("buf = %s\n", buf);
//		if ((n_pointer = ft_strchr(buf, '\n')))
//		{
//			*n_pointer = '\0';
//			*line = ft_strjoin(*line, ft_strdup(buf));
//			n_pointer++;
//			buf = n_pointer;
//		//	printf("buf = %s\n", n_pointer);
//		//	return (1);
//		} else
//			*line = ft_strjoin(*line, buf);
//	}
//
//	if (!(*line))
//		*line = ft_strjoin(*line, buf);
//
//	free(buf);
//	return (0);
//}

//int		get_next_line(int fd, char **line)
//{
//	static char		buf_tail[BUF_SIZE + 1];
//	char 			*st_copy = buf_tail;
//	char			*buf;
//	int				num_of_bytes;
//	int				i;
//	int 			j;
//	char			*n_pointer;
//	char			*b_pointer;
//
//	i = 0;
//	j = 0;
//	n_pointer = NULL;
//	*line = ft_strnew(1);
//	buf = ft_strnew(BUF_SIZE)
//	if ((b_pointer = ft_strchr(buf_tail, '\n')))
//	{
//		printf("есть перенос");
//	}
//	if (!(*line = ft_strnew(1)))
//		return(-1);
//	if (!(buf = ft_strnew(BUF_SIZE)))
//		return(-1);
//	*line = ft_strjoin(*line, buf_tail);
//	*buf_tail = NULL;
//	while ((num_of_bytes = read(fd, buf, BUF_SIZE)))
//	{
//		buf[num_of_bytes] = '\0';
//		if ((n_pointer = ft_strchr(buf, '\n')))
//		{
//			while (buf[i] != '\n')
//				i++;
//			while (++i < BUF_SIZE)
//			{
//				buf_tail[j] = buf[i];
//				j++;
//			}
//			buf_tail[j] = '\0';
//			*n_pointer = '\0';
//			*line = ft_strjoin(*line, ft_strdup(buf));
//			//free(buf);
//			return (1);
//		} else
//			*line = ft_strjoin(*line, buf);
//	}
//
//	if (!(*line))
//		*line = ft_strjoin(*line, buf);
//
//	free(buf);
//	return (0);
//}


int		main(void)
{
	int		fd;
	char	*line = NULL;
	int		gnl_result;
	fd = open("../test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file not open\n");
		return (1);
	}

	while ((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
	}
	return (0);
}
