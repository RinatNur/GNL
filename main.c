/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:33:51 by jheat             #+#    #+#             */
/*   Updated: 2020/07/15 18:15:47 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line = NULL;
	int		i = 0;

	fd = open("../alphabet", O_RDONLY);

	if (fd == -1)
	{
		printf("file not open\n");
		return (1);
	}

	while (((get_next_line(fd, &line))) > 0)
	{
		printf("%d. %s\n",++i, line);
		free(line);
	}
	printf("%d. %s\n",i, line);
	free(line);
	return (0);
}