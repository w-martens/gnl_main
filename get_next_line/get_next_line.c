/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 19:18:57 by wmartens       #+#    #+#                */
/*   Updated: 2020/02/01 00:15:20 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ret_f(char **buf, char *res, char **line, int ret)
{
	if (ret > 0)
	{
		*line = ft_nldup(res);
		free(res);
		if (*line == NULL)
			return (ret_f(buf, NULL, NULL, -1));
		return (1);
	}
	if (ret == 0)
	{
		*line = ft_nldup(res);
		if (*line == NULL)
			return (ret_f(buf, res, NULL, -1));
		*buf[0] = '\0';
		free(*buf);
		*buf = NULL;
		free(res);
		return (0);
	}
	if (*buf)
		*buf[0] = '\0';
	free(*buf);
	*buf = NULL;
	free(res);
	return (-1);
}

static void		re_mainder(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nl_check(str) != 0)
		j = nl_check(str);
	if (nl_check(str) != 0)
	{
		while (str[j] != '\0')
		{
			str[i] = str[j];
			i++;
			j++;
		}
		str[i] = '\0';
	}
}

static int		buf_check(char **buf, char **res)
{
	if (nl_check(*buf) != 0)
	{
		*res = ft_nldup(*buf);
		if (*res == NULL)
		{
			(*buf)[0] = '\0';
			free(*buf);
			*buf = NULL;
			return (-1);
		}
		re_mainder(*buf);
		return (1);
	}
	return (0);
}

static int		get_line(int fd, char **buf, char **res)
{
	int	ret;

	if (*buf == NULL)
		*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buf == NULL)
		return (-1);
	if (*res == NULL)
		*res = ft_nldup("");
	if (*res == NULL)
		return (-1);
	while (1)
	{
		ret = read(fd, *buf, BUFFER_SIZE);
		if (ret >= 0)
		{
			(*buf)[ret] = '\0';
			*res = joiner(*res, *buf);
		}
		if (*res == NULL)
			return (-1);
		if (ret <= 0 || nl_check(*buf) != 0)
			break ;
	}
	re_mainder(*buf);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	static char *buf[OPEN_MAX];
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	if (buf[fd] != NULL && nl_check(buf[fd]) != 0)
		return (buf_check(&buf[fd], line));
	if (buf[fd] != NULL && nl_check(buf[fd]) == 0)
	{
		res = ft_nldup(buf[fd]);
		if (res == NULL)
			return (ret_f(&buf[fd], NULL, NULL, -1));
	}
	ret = get_line(fd, &buf[fd], &res);
	return (ret_f(&buf[fd], res, line, ret));
}
