/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:10:35 by jheat             #+#    #+#             */
/*   Updated: 2020/07/08 19:17:00 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 20

int		get_next_line(int fd, char **line)
{
	static char		*buf_tail;
	char			buf[BUF_SIZE + 1];
	int				num_of_bytes;
	int				i;
	char			*n_pointer;
	
	i = 0;
	n_pointer = NULL;
	*line = ft_strnew(1);
	while ((num_of_bytes = read(fd, buf, BUF_SIZE)))
	{
		buf[num_of_bytes] = '\0';
		if ((n_pointer = ft_strchr(buf, '\n')))
		{
			*n_pointer = '\0';
			*line = ft_strdup(buf);
			//n_pointer++;
			buf_tail = n_pointer;
			printf("buf_tail = %p\n", buf_tail);
			//printf("n_pointer = %s\n", ++n_pointer);
			return (1);
		}
			
	//	printf("Number of reading bytes = %d\n", num_of_bytes);
	
		// *line = ft_strjoin(*line, buf);
	}
	if (num_of_bytes  == 0)
		return(0);
	return (0);
}

int		main(void)
{
	int		fd;
	char	*line;
	int		gnl_result;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file not open\n");
		return (1);
	}
	printf("------------------------------------------------------\n");
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);

	/* while ((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
	} */
	

	return (0);
}
