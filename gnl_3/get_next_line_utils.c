/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 19:19:24 by wmartens       #+#    #+#                */
/*   Updated: 2020/01/15 18:31:00 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		nl_check(char *buf)
{
	int i;

	i = 0;
	if (!buf || buf[i] == '\0')
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*joiner(char *res, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)malloc(ft_strlen(res) + ft_strlen(buf) + 1);
	if (!tmp)
		return (0);
	while (res[i] != '\0')
	{
		tmp[j] = res[i];
		i++;
		j++;
	}
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		tmp[j] = buf[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(res);
	return (tmp);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (cpy == 0)
		return (0);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_nldup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (!cpy)
		return (0);
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
