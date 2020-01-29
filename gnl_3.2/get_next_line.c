/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 19:18:57 by wmartens       #+#    #+#                */
/*   Updated: 2020/01/28 22:14:56 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		free_f(char *str1, int ret)
{
	free(str1);
	return (ret);
}

static char		*re_mainder(char *rmd, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nl_check(buf))
	{
		while (buf[j] != '\n')
			j++;
		j++;
	}
	tmp = (char *)malloc(ft_strlen(buf) + 1 - j);
	if (!tmp)
		return (0);
	while (buf[j] != '\0')
	{
		tmp[i] = buf[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free(rmd);
	return (0);
}

static int		rmd_check(char **rmd, char **line)
{
	char *tmp;

	if (*rmd == NULL)
		*rmd = ft_strdup("");
	if (nl_check(*rmd))
	{
		tmp = *line;
		*line = ft_nldup(*rmd);
		free(tmp);
		tmp = *rmd;
		*rmd = re_mainder(tmp, *rmd);
		return (1);
	}
	return (0);
}

static int		get_line(int fd, char **rmd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		red;

	if (rmd_check(rmd, line))
		return (1);
	if (*rmd == NULL || *line == NULL)
		return (free_f(*rmd, -1));
	if (*rmd)
		*line = joiner(*line, *rmd);
	if (*rmd == NULL || *line == NULL)
		return (free_f(*rmd, -1));
	while (1)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red >= 0)
		{
			buf[red] = '\0';
			*line = joiner(*line, buf);
		}
		if (!*line)
			return (free_f(*rmd, -1));
		if (red <= 0 || nl_check(buf))
			break ;
	}
	*rmd = re_mainder(*rmd, buf);
	if (*rmd == NULL)
		return (free_f(*rmd, -1));
	return (red);
}

int		get_next_line(int fd, char **line)
{
	static char	*rmd[1024];
	int			ret;

	*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	if (fd < 0)
		return (-1);
	ret = get_line(fd, &rmd[fd], line);
	if (ret > 0)
		return (1);
	if (ret == 0)
	{
		rmd[fd][0] = '\0';
		return (0);
	}
	free(*line);
	*line = NULL;
	return (-1);
}
