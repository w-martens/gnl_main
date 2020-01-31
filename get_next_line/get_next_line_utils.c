/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 19:19:24 by wmartens       #+#    #+#                */
/*   Updated: 2020/02/01 00:00:27 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		nl_check(char *str)
{
	int i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*free_str(char *str1)
{
	free(str1);
	return (NULL);
}

char	*joiner(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (tmp == NULL)
		return (free_str(str1));
	while (str1[i] != '\0')
	{
		tmp[j] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (str2[i] != '\0' && str2[i] != '\n')
	{
		tmp[j] = str2[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(str1);
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_nldup(char *s1)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(ft_strlen(s1) + 1);
	if (tmp == NULL)
		return (0);
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
