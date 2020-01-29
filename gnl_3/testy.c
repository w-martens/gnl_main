/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 22:12:01 by wmartens       #+#    #+#                */
/*   Updated: 2020/01/16 11:10:02 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd1;
	// int		fd2;
	int		ret;
	int		i;
	char	*line;
	char	*wth = ft_strdup("");
	wth[0] = '\0';
	fd1 = open("1.txt", O_RDONLY);
		// fd2 = open("2.txt", O_RDONLY);
	ret = 1;
	i = 0;
	while (ret)
	{
		ret = get_next_line(fd1, &line);
		printf("l:%d r:%d \t '%s' \n", (i + 1), ret, line);
	 	free(line);
//		ret = get_next_line(fd2, &line);
//		printf("l:%d r:%d \t '%s' \n", (i + 1), ret, line);
//	 	free(line);
		i++;
	}
	// printf("line = '%s' \n", line);
	// printf("wth = '%s' \n", wth);
	// while (1){}
	return (0);
}
