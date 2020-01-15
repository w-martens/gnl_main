/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 19:18:57 by wmartens       #+#    #+#                */
/*   Updated: 2020/01/15 18:53:44 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*re_mainder(char *buf)
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
	return (tmp);
}

static int		rmd_check(char **rmd, char **res)
{
	if (nl_check(*rmd))
	{
		*res = ft_nldup(*rmd);
		*rmd = re_mainder(*rmd);
		return (1);
	}
	return (0);
}

static int		free_f(char *str, int ret)
{
	free(str);
	return (ret);
}

static int		get_line(int fd, char **rmd, char **res)
{
	char	*buf;
	int		red;

	red = 1;
	if (rmd_check(rmd, res))
		return (1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	buf[BUFFER_SIZE] = '\0';
	if (*rmd)
		*res = ft_strdup(*rmd);
	while (1)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red)
			*res = joiner(*res, buf);
		if (!res)
			return (free_f(buf, -1));
		if (!red || nl_check(buf))
			break ;
	}
	*rmd = re_mainder(buf);
	free(buf);
	return (red);
}

int		get_next_line(int fd, char **line)
{
	static char	*rmd[OPEN_MAX];
	char		*res;
	int			ret;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	res = ft_strdup("");
	if (res == NULL)
		return (free_f(res, -1));
	ret = get_line(fd, &rmd[fd], &res);
	if (ret > 0)
	{
		*line = ft_strdup(res);
		return (free_f(res, 1));
	}
	if (ret == 0)
	{
		*line = ft_strdup(res);
		return (free_f(res, 0));
	}
	return (free_f(res, -1));
}
