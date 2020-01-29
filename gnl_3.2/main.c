#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		rv;
	int		i;
	i = 1;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((rv = get_next_line(fd, &line)) > 0)
		{
			printf("Line %d : OUTPUT %d : %s\n", i, rv, line);
			i++;
			if (line)
				free(line);
		}
		printf("Line %d : OUTPUT %d : %s\n", i, rv, line);
		close(fd);
	}
	while(1);
	return (0);
}